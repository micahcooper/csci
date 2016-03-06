/***************************************************************
 * @file udp_copy_server.java
 *
 * @author Micah Cooper
 * @version 0.9, Thur April 24 23:59:00 EDT 2008
 */

import java.io.*;
import java.net.*;
import java.util.*;

/**************************************************************
 * This class implements the server side of a file transfer program
 *     built over UDP but implementing reliability.
 */
public class udp_copy_server
{
	/** the port this server will be listening on
	*/
	int port;
	/** string constant
	*/
	private final String CRLF = "\r\n";
	/** indicates the transmission is complete
	*/
	boolean complete;
	/** the incoming udp packet
	*/
	DatagramPacket input_packet;
	/** actual data from the input packet
	*/
	byte[] input_data;
	/** packet to be sent to the client
	*/
	DatagramPacket output_packet;
	/** data for the output packet
	*/
	byte[] output_data;
	/** the socket object
	*/
	DatagramSocket socket;
	/** indicates the server is ready
	*/
	boolean readyToReceive;
	/** holds the incoming packets
	*/
	List<DatagramPacket> packet_buffer;
	/** hold the next expected sequence number
	*/
	int next_seq_no;
	/**
 	*/
	boolean okToAdd;
	/**
	*/
	String filename = "r_file";
	/**
 	*/
	boolean completedTransmission;
    private final int header_length = 100;
    private final int data_length   = 900;
    private final int packet_length = header_length + data_length;
    private final String unique_id = "Micah's Packet";

	/**
	* the server's contructor
	*
	* @param _port 	the port the server will listen on
	*/
	public udp_copy_server(String _port)
	{
		try
		{
			socket 			= new DatagramSocket( Integer.parseInt(_port) );
			input_data 		= new byte[packet_length];
			input_packet 	= new DatagramPacket( input_data, packet_length);
			packet_buffer 	= new ArrayList<DatagramPacket>();	
			readyToReceive 	= false;
			okToAdd			= false;
			complete		= false;
			next_seq_no		= 0;
			runtime();
		}
		catch( Exception e )
		{
			System.out.println( "problem in server constructor "+e.getMessage() );
		}
	}

	/**
	* the server's control of action
	*
	*
	*/
	public void runtime()
	{
		while( true )
		{
			try
			{
				input_data = new byte[packet_length];
				input_packet 	= new DatagramPacket( input_data, packet_length);
				socket.receive( input_packet );
				checkStatus();
				processPacket();
				
				if( readyToReceive && okToAdd )
				{
						packet_buffer.add( input_packet );
				}
				if( complete )
					assembleData();
			}
			catch( Exception e )
			{
				System.out.println("Exception in server's runtime "+e.toString() );
				socket.close();
				System.exit(-1);
			}
		}//while

	}//runtime

	/**
	*
	*
	*
	*/
	private void checkStatus() throws Exception
	{
		byte[] header_bytes = new byte[header_length];
		String header;
		String[] tokens;

		for(int i=0; i<header_length; i++)
			header_bytes[i] = input_packet.getData()[i];

		header = getHeader( header_bytes );
		tokens = header.split(":");
System.out.println("\nClient says: "+header);
	}


	/**
	* checks the incoming packet for correctness
	*
	*
	*/
	public void processPacket() throws Exception
	{
		byte[] buf = new byte[header_length];
		String header = "";
		String reply = "";
		String[] tokens;
		InetAddress clientHost = input_packet.getAddress( );
		int clientPort = input_packet.getPort( );

		for(int i=0; i<header_length; i++)
			buf[i] = input_packet.getData()[i];	

	 	header = getHeader( buf );
		tokens = header.split(":");
	
		if( tokens[0].equalsIgnoreCase("send") )
		{
			reply = "send"+CRLF;
			output_data = new byte[packet_length];

			for(int i=0; i<buf.length; i++)
				buf[i] = input_packet.getData()[i];

			header = getHeader(buf);
			tokens = header.split(":");
			reply += tokens[1]+CRLF;
		
			next_seq_no = (new Integer(tokens[1]).intValue());

			readyToReceive = true;
		}//ok to send
		if( tokens[0].equalsIgnoreCase("file") )
		{
System.out.println("UniqueID : "+tokens[4]+" "+tokens[4].compareTo(unique_id));
			if( next_seq_no == (new Integer(next_seq_no).intValue()) 
				&& tokens[4].equalsIgnoreCase(unique_id) )
			{
				next_seq_no++;
				okToAdd = true;
			}
			else
			{
				okToAdd = false;
			}
			reply = "send"+CRLF+(new Integer(next_seq_no).toString())+CRLF;
			output_data = new byte[packet_length];
		}

		if( tokens[0].equalsIgnoreCase("hello") )	
		{
			//System.out.println("hello "+clientHost);
			//packet_buffer = new ArrayList<DatagramPacket>();
			reply = "hello"+CRLF;
		}//say hello

		if( tokens[0].equalsIgnoreCase("goodbye") )
		{
			System.out.println("goodbye");
			reply = "goodbye"+CRLF;
			readyToReceive = false;
			complete = true;
		}//say goodbye


		output_data = new byte[packet_length];

		for(int i=0; i<(reply.getBytes()).length; i++)
			output_data[i] = reply.getBytes()[i];
//System.out.println("Server says: "+reply);
		output_packet = new DatagramPacket( output_data, packet_length, clientHost, clientPort ); 
		socket.send( output_packet );			
	}

	/**
	* writes the data from incoming packets to a file
	*
	*
	*/
	public void assembleData()
	{
		byte[] bytes = new byte[header_length];// = new byte[500];
		FileOutputStream fos;
		String header;
		String[] tokens;
		int length;

			

		try
		{
			for(int j=0; j<header_length; j++)
				bytes[j] = packet_buffer.get(0).getData()[j];
			header = getHeader(bytes);
			tokens = header.split(":");
			filename = "recieved_"+tokens[2];
			fos = new FileOutputStream(filename);

			for(int i=0; i<packet_buffer.size(); i++)
			{
				for(int j=0; j<header_length; j++)
					bytes[j] = packet_buffer.get(i).getData()[j];
				header = getHeader(bytes);
				tokens = header.split(":");
				length = new Integer(tokens[3]).intValue();
				bytes = new byte[length];


				for(int j=header_length; j<length+header_length; j++)
					bytes[j-header_length] = packet_buffer.get(i).getData()[j];
				fos.write(bytes);
			}
			fos.close();
		}
		catch(Exception e)
		{
			System.out.println("error assembling data ");
			e.printStackTrace();
		}
		finally
		{
			okToAdd=false;
			complete = false;
			packet_buffer=new ArrayList<DatagramPacket>();
		}
		
	}

	/**
	 * retrieves the header in String format
	 *
	 * @param buf	the header info as byte array
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
	*
	*
	*
	*/
	public static void main( String[] args) throws Exception
	{
		//obtain command line argument
		if( args.length != 1 )
		{
			System.out.println( "usage \"%udp_copy_server <server_port>\"" );
			return;
		}//if

		new udp_copy_server( args[0] );
	}//main
}//udp_copy_server
