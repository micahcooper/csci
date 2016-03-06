
import java.io.*;
import java.net.*;
import java.util.*;

/**
 * The ServerA class.
 *
 */
public class WebServer
{
	/* the listen port number
 	*/ 
	int port = 6799;
	/* the listen socket
 	*/ 
	ServerSocket server = null;
	/* the request object
 	*/ 
	HttpRequest request;
	/* the socket created upon a connection
 	*/ 
	Socket openSocket;
	/* the indepent thread execution
 	*/ 
	Thread thread;

	/**
 	*
 	*/
	public WebServer()
	{
			listen( );
	}

	/**
 	*
 	*
 	*/
	private void listen( ) 
	{
		try
		{
			server = new ServerSocket( port );

			while( true )
			{
				openSocket = server.accept( );
	
				request = new HttpRequest( openSocket );

				thread = new Thread( request );
				thread.start( );
			}
		}
		catch( Exception e )
		{

		}
	} 	
 
	/**
 	* Main method, used to initiliaze the server.
 	*
 	*/ 
	public static void main( String args[] ) throws Exception
	{
		new WebServer( );
	}	
}

/*===============================================================================*/
/*===============================================================================*/
/*===============================================================================*/

/**
 * Processes the request from the client.
 *
 */
final class HttpRequest implements Runnable
{
	/* convience constant for carriage return line feed
 	*/
	private final String CRLF = "\n\r";	 
	/*
 	*/
	Socket socket;
	/* reference to the socket's input data
 	*/ 
	BufferedReader inFromClient;
	/* referece to the socket's output data
 	*/ 
	DataOutputStream outToClient;
	/* the input stream filter
 	*/ 
	InputStream is;
	/**
 	*/
	StringTokenizer tokens; 
	/** the client requested file
 	*/
	FileInputStream requestFile; 
		// the status line of the response message
		String statusLine = null;
		// the content type of the response message
		String contentTypeLine = null;
		// the body of the response message
		String entityBody = null;

	/**
 	* Constructor
 	*
 	*/
	public HttpRequest( Socket socket )
	{
		this.socket = (Socket)socket;
	} 

	/**
 	* Overries the inherited method.
 	*
 	*/ 
	public void run()
	{
		try
		{
			processRequest( );
			socket.close( );
		}
		catch( FileNotFoundException ffe )
		{
			statusLine = "HTTP/1.0 404" + CRLF;
			contentTypeLine = "Content-type: text/html" + CRLF;
			entityBody = "<html><head><title>File Not Found</title></head>"+	
								"<body>Not Found</body></html>";
			
			try
			{
				outToClient.writeBytes( statusLine );
				outToClient.writeBytes( contentTypeLine );
				outToClient.writeBytes( CRLF );
				outToClient.writeBytes( entityBody );

				outToClient.close( );
				inFromClient.close( );
			}
			catch( Exception e ) {}
		}
		catch( Exception e )
		{
			System.out.println( "Error processing request: " + e );
		}
	}

	/**
 	*
 	*
 	*/
	private void processRequest( ) throws Exception
	{
		// the request line
		String requestLine = null;
		//the header line from the request
		String headerLine = null;
		//the name of the file
		String filename = null;

		is = (InputStream)socket.getInputStream( ); 
		outToClient = new DataOutputStream( socket.getOutputStream( ) );

		inFromClient = new BufferedReader( new InputStreamReader( is ) );

		requestLine = inFromClient.readLine( );
		System.out.println( requestLine );
		while( (headerLine = inFromClient.readLine()).length() != 0 )
		{
			//System.out.println( headerLine );
		}	
		//make tokens of the request line		
		tokens = new StringTokenizer( requestLine );
		tokens.nextToken( );

		//obtain the second token, the file name(assumed!)
		filename = tokens.nextToken( );
		filename = "." + filename;

		//try to read the requested file
		requestFile = new FileInputStream( filename );

System.out.println( "FILENAME: " + filename );
		//assemble the content of the message
		statusLine = "HTTP/1.0 200 Document Follows" + CRLF;
		contentTypeLine = "Content-type: " + contentType( filename ) + CRLF;		
		outToClient.writeBytes( statusLine );
		outToClient.writeBytes( contentTypeLine );
		outToClient.writeBytes( CRLF );
		sendBytes( requestFile, outToClient ); 
		requestFile.close( );


		outToClient.close( );
		inFromClient.close( );
	}

	/**
 	* determines the content type of the requested file
 	*
 	*/
	private String contentType( String filename )
	{
		if( filename.endsWith( ".html" ) || filename.endsWith( ".htm" ) )
			return "text/html";
		if( filename.endsWith( ".jpeg" ) || filename.endsWith( ".jpg" ) )
			return "image/jpeg";
		if( filename.endsWith( ".png" )  )
			return "image/png";

		return "application/octet-stream";
	} 

	/**
 	*
 	*
 	*/
	private void sendBytes( FileInputStream requestFile, OutputStream outToClient )
		throws Exception
	{
		//construct a one meg buffer for the socket
		byte[] buffer = new byte[1024];
		int bytes = 0;

		//copy requested file into the socket's output stream
		while( (bytes = requestFile.read(buffer)) != -1 )
		{
			outToClient.write( buffer, 0, bytes );
		}
	}
}
