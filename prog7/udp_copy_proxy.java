import java.io.*;
import java.net.*;
import java.util.*;

/*
 * 
 */
public class udp_copy_proxy
{
	private static final double LOSS_RATE = 0.3;
	private static final double AVERAGE_DELAY = 100;//milliseconds

	public static void main( String[] args) throws Exception
	{
		//obtain command line argument
		if( args.length != 1 )
		{
			System.out.println( "usage \"%udp_copy_proxy <server_port>\"" );
			return;
		}//if
		int port = Integer.parseInt( args[0] );

		//Create random number generator for use in simulating
		//packet loss and network delay
		Random random = new Random( );
	
		//Create a datagram socket for receiving and sending UDP packets
		//throught the port specified on the command line
		DatagramSocket socket = new DatagramSocket( port );

		//Processing loop
		while( true )
		{
			//create a datagram packet to hold incomming UDP packet.
			DatagramPacket request = new DatagramPacket( new byte[1024], 1024);
			
			//Block until the host receives a UDP packet.
			socket.receive( request );
	
			//Print the received data
			printData( request );

			//Decide whether to reply, or simulate packet loss.
			if( random.nextDouble() < LOSS_RATE )
			{
				System.out.println( "Reply not sent." );
				continue;
			}

			//simulate network delay
			Thread.sleep( (int) (random.nextDouble() * 2 * AVERAGE_DELAY ));

			//Send reply
			InetAddress clientHost = request.getAddress( );
			int clientPort = request.getPort( );
			byte[] buf = request.getData( );
			DatagramPacket reply = new DatagramPacket( buf, buf.length, clientHost, clientPort );
			socket.send( reply );

			System.out.println( "Reply sent." );
		}//while
	}//main

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
		System.out.println("Recieved form "+ request.getAddress().getHostAddress()+
							": " + new String(line) );
	}//printData
}//udp_copy_proxy
