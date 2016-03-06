#include <stdio.h>
#include <string.h>

#include <netdb.h>
#include <ctype.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main( int argc, char **argv )
{
	struct hostnet *hostp;
	struct servent *servp;
	struct sockaddr_in server;
	int sock, server_port, counter, buf_size;

	if( argc < 3 )
	{
		printf("Usage: %s hostip portnum\n", argv[0]);
		exit( -1 );
	}

	fd_set rmask, xmask, mask;
	char buf[100];
	
	if( (sock = socket( AF_INET, SOCK_STREAM, 0 )) < 0 )
	{
		perror("socket");
		exit( -1 );
	}

	hostp = gethostbyname( argv[1] );

	server_port = htons( (u_short) atoi (argv[2]) );

	bzero( &server, sizeof( server ) );

	server.sin_family = AF_INET;
	server.sin_port = server_port;
	inet_pton( AF_INET, argv[1], &server.sin_addr );	

	connect( sock, (struct sockaddr *)&server, sizeof( server ) < 0 );
	
	FD_ZERO( &mask );
	FD_SET( sock, &mask );
	FD_SET( fileno( stdin ), &mask );

	while( 1 )
	{
		rmask = mask;
		counter = select( FD_SETSIZE, &rmask, (fd_set *)0, (fd_set *)0, 1000);

		if( FD_ISSET( fileno( stdin ), &rmask ) )
		{
			fgets( buf, sizeof( buf ), stdin ); 
			write( sock, buf, strlen(buf) );
		}
		if( FD_ISSET( sock, &rmask ) )
		{
			buf_size = read( sock, buf, sizeof( buf ) );
			buf[buf_size] = '\0';
			printf("%s", buf);	
		}
	}
}
