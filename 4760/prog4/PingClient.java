import java.io.*;
import java.net.*;
import java.util.*;

/*
 * 
 */
public class PingClient
{
	public static int totalSent = 0;
	public static int totalRecv = 0;
	public static double minTime = 0.0;
	public static double avgTime = 0.0;
	public static double maxTime = 0.0;
	public static double totalTime = 0.0;
	public static double systemTime = 0.0;

	public static void main( String[] args) throws Exception
	{
		//obtain command line argument
		if( args.length != 2 )
		{
			System.out.println( "Required arguments: host port" );
			return;
		}//if
		systemTime = System.nanoTime()/1000000;
		final Timer qRunner = new Timer();
		InetAddress host = InetAddress.getByName( args[0] );
		int port = Integer.parseInt( args[1] );
		Runtime.getRuntime().addShutdownHook(new CPingClientShutdown(qRunner, totalSent, totalRecv, minTime, maxTime, totalTime));


		//Create a datagram socket for receiving and sending UDP packets
		//throught the port specified on the command line
		DatagramSocket socket = new DatagramSocket( );

		System.out.println( "----PING "+host.getCanonicalHostName()+"------" );
		//Processing loop
		for( int i=0; i<65000; i++ )
		{
			//create a datagram packet to hold incomming UDP packet.
			//DatagramPacket request = new DatagramPacket( new byte[1024], 1024);
			byte[] data = new byte[64];
			
			DatagramPacket request = new DatagramPacket( data, data.length, host, port);
			
		
			double sentTime = System.nanoTime();
			socket.send( request );
			totalSent++;

			socket.setSoTimeout( 1000 );
			byte[] echo = new byte[1024];
			try
			{
				socket.receive( request );
				totalRecv++;
				double recvTime = System.nanoTime();
				double timeForTrip = recvTime - sentTime;
				if( maxTime == 0 )
				{
					maxTime = timeForTrip;
					minTime = timeForTrip;
				}
				if( timeForTrip > maxTime)
					maxTime = timeForTrip;
				if( timeForTrip < minTime)
					minTime = timeForTrip;

				totalTime += timeForTrip;

				String msg = "64 bytes from "+host.getHostAddress()+": udp_seq="+i+" time="+(timeForTrip)/1000000+" ms";
				System.out.println( msg );
			}
			catch( SocketTimeoutException ste )
			{

			}

		}//while
			System.out.println(" packets transmitted, ");
	}//main

public static class CPingClientShutdown extends Thread
{
	private Timer m_oTimer;
	String lost = null;
	
	public CPingClientShutdown( Timer p_oTimer, int totalSent, 
		int totalRecv, double minTime, double maxTime, double totalTime )
	{
		super();
		m_oTimer = p_oTimer;
	}

	public void run()
	{
		if( totalSent != 0 )
			lost = new Integer( (int) (((float)(totalSent-totalRecv)/totalSent)*100) ).toString();
		else
			lost = "0";
	
		System.out.println( "LOST: "+ lost );
		System.out.println( "-----ping statistics-------" );
		systemTime = (System.nanoTime()/1000000)-systemTime;
		System.out.println( totalSent+" packets transmitted, "+totalRecv+" received, "+
			lost+"% packet loss, time "+systemTime );
		System.out.println( "rtt min/avg/max = "+(int)(minTime/1000000)+"/"+(int)(totalTime/totalRecv/1000000)+"/"+(int)(maxTime/1000000) );
		m_oTimer.cancel();
	}
}
}//PingServer

