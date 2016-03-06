/***************************************************************
 * @file udp_copy_client.java
 *
 * @author Micah Cooper
 * @version 0.9, Thur April 24 23:59:00 EDT 2008
 */

import java.io.*;
import java.net.*;
import java.util.*;

/**************************************************************
 * This class implements the client side of a file transfer program
 *     built over UDP but implementing reliability.
 */
public class udp_copy_client implements Runnable
{
	/** the socket over which communication with server is made
	*/
	private DatagramSocket output_socket;
	/** server's ip address
	*/
	private InetAddress host;
	/** server's port number
	*/
	private int port;
	/** file to transfer
	*/
	private String filename;
	/** incoming packet buffer
	*/
	private DatagramPacket input_packet;
	/** actual data from packet
	*/
	private byte[] input_data;
	/** packet to be sent to server
	*/
	private DatagramPacket output_packet;
	/** actual data to be sent
	*/
	private byte[] output_data;
	/** speaks for itself
	*/
	private final String CRLF = "\r\n";
	/** buffered array of packets
	*/
	private List<DatagramPacket> packet_list;
	/** the program's thread
	*/
	private Thread client;
	/** indicates ok to send file
	*/	
	private boolean okToSend;
	/** indicates all packets have been sent
	*/	
	private boolean complete;
	/** indicates connection made with server
	*/	
	private boolean connected;
	/**
	*/
	private boolean inProgress;
	/**
	*/
	int packet_no;
	private final int header_length = 100;
	private final int data_length   = 900;
	private final int packet_length = header_length + data_length;
	private final String unique_id = "Micah's Packet";
	private int timeout = 4000;

	/**
	* constructor to initialize the client
	*
	* @param _host 		string value of the server host
	* @param _port		string value fo the server port
	* @param _filename	the name of the file to transfer
	*/
	public udp_copy_client(String _host, String _port, String _filename)
	{
		try
		{
			host 			= InetAddress.getByName( _host );
			port 			= Integer.parseInt( _port );
			output_socket 	= new DatagramSocket( );
			output_socket.setSoTimeout( timeout );
			input_packet 	= new DatagramPacket( new byte[packet_length], packet_length);
			output_packet 	= new DatagramPacket( new byte[packet_length], packet_length);
			packet_list 	= new ArrayList<DatagramPacket>();
			filename 		= _filename;
			okToSend		= false;
			complete		= false;
			connected 		= false;
			inProgress		= false;
			packet_no		= 0;
		}
		catch( Exception e )
		{
			System.out.println("Exception caught in client constructor");
			System.out.println( e.toString() );
		}
		
		client = new Thread(this);
		client.start();
	}


	/**
	* the class thread of control
	*
	*/
	public void run()
	{
		createPackets(filename);
			
		try
		{
			manageConnection("open");//connect with server

			while( !complete )
			{
				if( !connected )
					throw new Exception("Unexpected loss of connection to server");

				if( !okToSend)
					manageConnection("send");
				if( okToSend )
				{
					sleep(100);
					while( packet_no < packet_list.size() )
					{
System.out.println("...sending packet: "+packet_no);
						output_socket.send( packet_list.get(packet_no) );
						input_packet = new DatagramPacket( new byte[packet_length], packet_length );
						output_socket.receive( input_packet );
						processPacket("send");
					}
					complete = true;
				}
			}//while

			manageConnection("close");//disconnect from server
		}
		catch( SocketTimeoutException ste )
		{
			System.out.print("output_socket timed out on client");
		}
		catch( Exception e )
		{
			System.out.println("Transmission failed");
			System.out.println( e.toString() );
		}
	}
	
	/**
	* Creates an array of DatagramPackets from the file specified.
	*
	* @param filename 	the name of the file to send
	*/
	public void createPackets(String filename)
	{
		String my_header;
		InputStream is;
		File file;
		byte[] packet_data =  new byte[data_length];
		byte[] packet	   = new byte[packet_length];
		DatagramPacket datagram_packet;
		int size;
		int packet_counter = 0;
		byte seq;

		try
		{
			file = new File( filename );
			is = new FileInputStream(file);
		
System.out.print("Creating packets...");	
			size = is.read(packet_data);
			while( size > 0 )
			{
				my_header =	"file"+CRLF
							+(new Integer(packet_counter++).toString())+CRLF
							+filename+CRLF
							+(new Integer(size).toString())+CRLF
							+unique_id+CRLF;

				for(int i=0; i<my_header.getBytes().length; i++)
					packet[i] = (my_header.getBytes())[i];

					for(int i=0; i<size; i++)
						packet[i+header_length] = packet_data[i];
				datagram_packet = new DatagramPacket( packet, packet.length, host, port );
				packet_list.add( datagram_packet );

				packet_data = new byte[data_length];
				packet 		= new byte[packet_length];
	
				size = is.read(packet_data);
			}//while			
System.out.println("done.");
		}
		catch( Exception e )
		{
			System.out.println("Exception in createPackets " );
			e.printStackTrace();
		}
	}

	/**
	* initiates the connection with the server
	*
	*
	*/
	public void manageConnection(String command) throws Exception
	{
		output_data = new byte[packet_length];
	//	output_packet = new DatagramPacket( new byte[packet_length], packet_length, host, port );
		String expected_reply = "";
		String flag = "";

		if( command.equalsIgnoreCase("open") )
		{
			expected_reply = "hello";
			flag = expected_reply+CRLF;		
		}
		if( command.equalsIgnoreCase("close") )
		{
			expected_reply = "goodbye";
			inProgress = false;
			flag = expected_reply+CRLF;		
		}

		if( command.equalsIgnoreCase("send") )
		{
			expected_reply = "send";
			flag = expected_reply+CRLF+packet_no+CRLF;		
		}

		/*if( command.equalsIgnoreCase("transmit") )
		{
				expected_reply = "send";
				inProgress = true;
				flag = expected_reply+CRLF+packet_no+CRLF;		
		}*/
 
		
		for(int j=0; j<(flag.getBytes()).length; j++)
			output_data[j] = flag.getBytes()[j];

		output_packet = new DatagramPacket( output_data, packet_length, host, port );
		output_socket.send( output_packet );
		output_socket.receive( input_packet );
		sleep(1000);

		processPacket( expected_reply );
	}

	/**
	* suppose to extract flags from header to determine the 
	*	next course of action
	*
	*/
	public void processPacket(String expected_reply) throws Exception
	{
		byte[] buf = new byte[header_length];
        String header = "";
        String[] tokens;

        for(int i=0; i<header_length; i++)
            buf[i] = input_packet.getData()[i];

        header = getHeader( buf );
        tokens = header.split(":");
//System.out.println( tokens[0]+" "+expected_reply);//tokens[0].compareTo(expected_reply) );
        if( tokens[0].equalsIgnoreCase(expected_reply) && tokens[0].equalsIgnoreCase("send") )
		{
System.out.print("Server says: "+header);
			packet_no = new Integer(tokens[1]).intValue();
			if( (new Integer(tokens[1]).intValue()) < packet_list.size() )
			{
				okToSend = true;
			}
			else
			{
				okToSend = false;
			}
		}

        if( tokens[0].equalsIgnoreCase(expected_reply) && tokens[0].equalsIgnoreCase("hello") )
			connected = true;

        if( tokens[0].equalsIgnoreCase(expected_reply) && tokens[0].equalsIgnoreCase("goodbye") )
			connected = false;
	}

	/**
	* converts the byte array into a string with delimiters ':'
	*
	* @param buf	the byte array to convert
	*/
	private String getHeader( byte[] buf ) throws Exception
    {
        String data = "";
        String line = "";
        //wrap the bytes in a byte array input stream
        //so that you can read the data as a stream of bytes
        ByteArrayInputStream bais = new ByteArrayInputStream( buf );

        //wrap the byte array output stream in an input stream reader
        //so you can read the data as a stream of characters
        InputStreamReader isr = new InputStreamReader( bais );

        //wrap the input stream reader in a buffered reader
        //so you can read teh character data a line at a time
        //a line in terminated by any combination of \r\n
        BufferedReader br = new BufferedReader( isr );

        line = br.readLine( );
        while(line!=null)
        {
            data += line+":";
            line = br.readLine( );
        }

        return data;
    }//printData

	/**
	* puts this thread to sleep 
	*
	* @param time 	the amount of time in ms
	*/
	public void sleep(int time) throws Exception
	{
		synchronized(this)
		{
			wait(time);
		}
		
	}

	/**
	*
	*
	*
	*/
	public static void main( String[] args) throws Exception
	{
		//obtain command line argument
		if( args.length < 3 )
		{
			System.out.println( "usage \"%udp_copy_client <server_ip> <server_port> <filename>\"" );
			return;
		}//if

		new udp_copy_client( args[0], args[1], args[2] );
	}//main

}//udp_copy_client

