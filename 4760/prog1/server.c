#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(int argc, char **argv)
{
		int sock, port, s, e, alen;
		struct sockaddr_in saddr, caddr;
		char buf[100];
		
		if(argc < 2) {
			printf("Usage: %s portnum\n\n", argv[0]);
			exit(-1);
		}
		
		port = atoi (argv[1]);
		
		sock = socket(PF_INET, SOCK_STREAM, 0);
		/* check for error */
		
		saddr.sin_addr.s_addr = INADDR_ANY;
		saddr.sin_port = htons (port);
		saddr.sin_family = AF_INET;
		
		e = bind( sock, (struct sockaddr *) &saddr, sizeof(saddr) );
		if( e<0 ){
			perror("bind");
			exit(-2);
		}
		
		listen( sock, 0 );
		
		s = accept( sock, (struct sockaddr *) &caddr, &alen );
		/*check to see if s is a valid return*/
		
		while( recv (s, buf, 100, 0) ){
			printf("%s\n", buf);
		}
		
		close(s);
		close(sock);
		return 0;
}
