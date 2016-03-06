import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*;

public final class Webserver
{

	public static void main( String argv[] ) throws Exception
	{
		int port = 6700;
		
		ServerSocket server = new ServerSocket( port );
		while( true )
		{
			Socket socket = server.accept( );
			HttpRequest request = new HttpRequest( socket );
			Thread thread = new Thread( request );
			thread.start( );
		}
	}
}

final class HttpRequest implements Runnable
{
	Socket socket = null;
	String clientIP = "";
	String clientAgent = "";
	String clientCookie = "";
	String originalIP = "";
	String theHost = "Cooper's Incredible Website";
	boolean existingClient= false;
	final static String CRLF = "\r\n";

	public HttpRequest( Socket socket )
	{
		this.socket = socket;
		clientIP = (socket.getInetAddress()).getHostAddress();
		//clientIP = (socket.getInetAddress()).toString();
	}

	public void run( )
	{	
		try
		{
			processRequest( );
		}catch( Exception e )
		{
			System.out.println( e );
		}

	}

	private void processRequest( ) throws Exception
	{
		InputStream is = socket.getInputStream( );
		DataOutputStream os = new DataOutputStream(socket.getOutputStream( ));

		BufferedReader br = new BufferedReader( new InputStreamReader( is ) );
	
		String requestLine = br.readLine( );
		System.out.println( requestLine );
		StringTokenizer tokens = new StringTokenizer( requestLine );
		tokens.nextToken();
		String filename = tokens.nextToken();
		filename = "." + filename;
		//System.out.println( filename );

		String headerLine = null;

		//Process the request for needed information(host, agent, cookie...)
		System.out.println("***********request************");	
		while( (headerLine = br.readLine()).length() != 0 )
		{
			System.out.println( headerLine );
			//find the cookie value in the request header
			if( headerLine.contains("Host") )
			{
				tokens = new StringTokenizer( headerLine );
				tokens.nextToken();
				theHost = tokens.nextToken();
			}
			if( headerLine.contains("User-Agent") )
			{
				clientAgent = headerLine.substring( 11 );
			}
			if( headerLine.contains("ookie") )
			{
				findMyCookie( headerLine );
			}
		}
		System.out.println("******************************");	

		FileInputStream fis = null;
		boolean fileExists = true;
		try{
			fis = new FileInputStream( filename );
		}catch( FileNotFoundException e) {
			fileExists = false;
			System.out.println("file does not exist on server");
		}

		String statusLine = null;
		String contentTypeLine = null;
		String cookieLine = null;
		String entityBody = null;
		if( fileExists ) {
			//returning client request a legitimate file
			if( existingClient )
			{
				statusLine = "HTTP/1.0 200 OK" + CRLF;
				contentTypeLine = "Content-type: "+ contentType(filename)+CRLF;
			}
			//new client has requested a legitimate file
			else
			{
				statusLine = "HTTP/1.0 200 OK" + CRLF;
				contentTypeLine = "Content-type: "+ contentType(filename)+CRLF;
				cookieLine = "Set-Cookie: MicahsCookie="+getRandomId()+"; expires=Sun, 17-Jan-2009 19:12:07 GMT;"+CRLF;
				
			}
		}
		//the file is not on the server
		else {
			if( existingClient )
			{
				//returning client has requested ShowMyCookie
				if(filename.equalsIgnoreCase("./ShowMyCookie.html"))
				{
					statusLine = "HTTP/1.0 200 OK" + CRLF;
					contentTypeLine = "Content-type: "+ contentType(filename)+CRLF;
					entityBody = createShowMyCookie(true);
				}//if
				//returning client has requested a not found page
				else
				{
					statusLine = "HTTP/1.0 404 Not Found"+CRLF;
					contentTypeLine = "Content-type: text/html"+CRLF;
					entityBody = "<html><head><title>Page Not Found</title></head>"+
								"<body>404 Page Not Found</body></html>";
				}//else
			}//if
			//new customer to the site!!!
			else
			{
				//NEW client has requested ShowMyCookie
				if(filename.equalsIgnoreCase("./ShowMyCookie.html"))
				{
					statusLine = "HTTP/1.0 200 OK" + CRLF;
					contentTypeLine = "Content-type: "+ contentType(filename)+CRLF;
					cookieLine = "Set-Cookie: MicahsCookie="+getRandomId()+
							"; expires=Sun, 17-Jan-2009 19:12:07 GMT;"+CRLF;
					entityBody = createShowMyCookie(false);
				}//if
				//NEW client has requested a not found page
				else
				{
					statusLine = "HTTP/1.0 404 Not Found"+CRLF;
					contentTypeLine = "Content-type: text/html"+CRLF;
					cookieLine = "Set-Cookie: MicahsCookie="+getRandomId()+
						"; expires=Sun, 17-Jan-2009 19:12:07 GMT;"+CRLF;
					entityBody = "<html><head><title>Page Not Found</title></head>"+
								"<body>404 Page Not Found</body></html>";
				}//else
			}//else
		}

		os.writeBytes( statusLine );
		os.writeBytes( contentTypeLine );
		if( !existingClient )
			os.writeBytes( cookieLine );
		os.writeBytes( CRLF );

		if( fileExists )
		{	
			sendBytes( fis, os );
			fis.close();
		} else {
			os.writeBytes( entityBody );
			os.writeBytes( CRLF );
		}

		os.close( );
		br.close( );
		socket.close( );
	}

	public String contentType( String filename )
	{
		if( filename.endsWith( ".html" ) || filename.endsWith( ".htm" ) )
			return "text/html";
		if( filename.endsWith( ".png" ) )
			return "image/png";
		if( filename.endsWith( ".jpeg") )
			return "image/jpeg";
		if( filename.endsWith( ".jpg") )
			return "image/jpeg";
		if( filename.endsWith( ".gif") )
			return "image/gif";

		return "application/octet-stream";
	}
	
	private static void sendBytes( FileInputStream fis, OutputStream os)
		throws Exception
	{
		byte[] buffer = new byte[1024];
		int bytes = 0;

		while( (bytes = fis.read(buffer)) != -1 )
		{
			os.write( buffer, 0 , bytes );
		}
	}

	/**
 	* Searches for an existing customer the permanent storage file.
 	*
 	*/
	boolean checkForReturningCustomer(String value)
	{
		Scanner file = null;
		String token;

		try
		{
			file = new Scanner( new File("cookies.txt") );
			while( file.hasNext() )
			{
				token = file.nextLine();//.split(";")[0];
				System.out.println( "looking at: "+token+" for "+value );
				if( token.contains(value) )
				{
					clientCookie = "MicahsCookie="+value;
					originalIP = token.split(";")[1];
					System.out.println("checking cookie.txt: "+originalIP);
					return true;
				}
			}//while
			file.close();
		}
		catch(Exception e)
		{
			System.out.println("could not open file");
			//System.out.println( e.printStackTrace() );
			e.printStackTrace();
			return false;
		}
		return false;
	}//findInFile

	long getRandomId()
	{
		Random randy = new Random();
		long id = randy.nextLong();

		if( id < 0 )
			id=id*-1;

		storeCookieId(id);

		return id;
	}

	String createShowMyCookie(boolean existingClient)
	{
		String page;

		//returning client want to see ShowMyCookie
		if( !existingClient )
		{
			page = "<html><head><title>Show My Cookie</title></head>"+
					"<body>"+
						"<h2>New Visitor to <span>"+theHost+"</span></h2>"+
						"<br><b>You are from host:</b> "+clientIP+
						"<br><b>You are currently using:</b> "+clientAgent+
						"<br><b>A cookie has been assinged to you.</b>"+
						"<br><b>Your cookie is:</b> "+clientCookie+
					"</body></html>";

			return page;			
		}//if
		//NEW client wants to see ShowMyCookie
		else
		{
			page = "<html><head><title>Show My Cookie</title></head>"+
					"<body><h2>Welcome Back to "+theHost+"</h2>"+
					"<br><b>Your first visit was from host:</b> "+originalIP+
					"</body></html>";
		
			return page;
		}//else
	}

	/**
 	*  Stores information about the client, cookie value and ip.
 	*
 	*/ 
	void storeCookieId(long id)
	{
		FileWriter outToFile = null;
		String storeId = (new Long(id)).toString();		

		try
		{
			outToFile = new FileWriter( "cookies.txt", true );
			outToFile.write( storeId );
			outToFile.write( ";" );
			outToFile.write( clientIP );
			outToFile.write( "\n" );
			outToFile.close(); 
		}
		catch( Exception e )
		{
			System.out.println( "Could not save the cookie on server" );
		}
	}

	void findMyCookie(String cookies)
	{
		StringTokenizer tokens = new StringTokenizer( cookies );
		String cookie = "";
		String id = "";

		while( tokens.hasMoreTokens() )
		{
			cookie = tokens.nextToken();
			if( cookie.contains("MicahsCookie") )
				id = ( cookie.split("=") )[1];				
		}
		existingClient = checkForReturningCustomer( id );
	}
}
