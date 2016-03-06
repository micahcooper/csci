import java.io.*;
import java.net.*;
import java.util.*;

/*
 * 
 */
public class udp_proxy implements Runnable
{
	private double LOSS_RATE;
	private static final double AVERAGE_DELAY = 100;//milliseconds
	private int header_length = 100;
	private int data_length = 65400;
	private int packet_length = header_length + data_length;
	private int proxy_port;
	private int sendTo_port;
	private	InetAddress client_host;
	private	int client_port;
	private Random random;
	private DatagramSocket input_socket;
	private DatagramSocket output_socket;
	private DatagramPacket forward;
	private DatagramPacket receive;
	private InetAddress sendTo_ip;
	private boolean fromClient;
	private boolean dropPacket;
	Thread proxy1;
	Thread proxy2;
	
	/**
   	* Default constructor
   	*/
	public udp_proxy(String _proxy_port, String _sendTo_ip, String _sendTo_port, String _lossrate)
	{
		try
		{
			sendTo_ip = InetAddress.getByName( _sendTo_ip );
			proxy_port = Integer.parseInt( _proxy_port );
			sendTo_port = Integer.parseInt( _sendTo_port );
			random = new Random( );
			input_socket = new DatagramSocket( proxy_port );
			output_socket = new DatagramSocket( 6787 );
			fromClient = true;
			dropPacket = false;
			LOSS_RATE = new Double(_lossrate).doubleValue();

		}
		catch( Exception e)
		{
			System.out.println("udp_proxy constructor error");
			e.printStackTrace();
		}

		proxy1 = new Thread(this);
		proxy1.start();
	}

	/**
	* The run method
	*
	*/
	public void run()
	{
		while( true )
		{
			try
			{
				if(  random.nextDouble() < LOSS_RATE )
					dropPacket = true;
				if( fromClient )
				{
					forward = new DatagramPacket( new byte[packet_length], packet_length );
					input_socket.receive( forward ); 
					client_host = forward.getAddress();
					client_port = forward.getPort();
					byte[] temp = new byte[packet_length];
					for( int i=0; i<packet_length; i++ )
						temp[i] = forward.getData()[i]; 
					forward = new DatagramPacket( temp, packet_length, sendTo_ip, sendTo_port);
					if( !dropPacket )
					{
						output_socket.send(forward);
						fromClient = false;
					}
					if( dropPacket )
					{
System.out.println("drop packet from Client");
						fromClient = true;
					}
				}
				dropPacket = false;
				if(  random.nextDouble() < LOSS_RATE )
					dropPacket = true;
				if( !fromClient )
				{
					forward = new DatagramPacket( new byte[packet_length], packet_length );
					output_socket.receive( forward );
					byte[] temp = new byte[packet_length];
					for( int i=0; i<packet_length; i++ )
						temp[i] = forward.getData()[i]; 
					forward = new DatagramPacket( temp, packet_length, client_host, client_port);
					if( !dropPacket )
					{
						output_socket.send(forward);
						input_socket.send(forward);
						fromClient = true;
					}
					if( dropPacket )
					{
System.out.println("drop packet from server");
						fromClient = false;
					}
				}	
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}//else
	}


	/*
	 *  print ping data to the standard output stream
	 */
	private static void printData( DatagramPacket request ) throws Exception
	{
		//obtain references to the packet's array of bytes
		byte[] buf = request.getData( );

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

		//the message data is contained in a single line, so read this line
		String line = br.readLine( );

		//Print host address and data received from it
		System.out.println("Recieved from "+ request.getAddress().getHostAddress()+
							": " + new String(line) );
	}//printData

	/**
 	*
 	*
 	*/ 
	public static void main( String[] args) throws Exception
	{
		//obtain command line argument
		if( args.length != 4 )
		{
			System.out.println( "usage \"%udp_copy_proxy <proxy_port> <server_IP> <server_port> <loss_rate>\"" );
			return;
		}//if
		new udp_proxy( args[0], args[1], args[2], args[3] );

	}//main
}//udp_copy_proxy
