#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

void error(char *msg)
{
	perror(msg);
	exit(0);
}	

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	char *buffer[1024];
	struct sockaddr_in serv_addr;
	struct hostent *server;

	if(argc < 3)
	{
		fprintf(stderr,"ERROR, no port provided\n");
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
	{
		error("ERROR opening socket");
	}
	
	bzero((char *) &serv_addr, sizeof(serv_addr));

	portno = atoi(argv[2]);

	server = gethostbyname(argv[1]);

	if(server == NULL)
	{
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0)
	{
		error("ERROR on binding");
	}
	
	printf("please enter the message: ");

	bzero(buffer, 1024);
	fgets(buffer, 1023, stdin);
	n = write(sockfd, buffer, strlen(buffer));

	if (n < 0)
	{
		error("ERROR writing to socket");
	}
	bzero(buffer, 1024);

	n = read(sockfd, buffer, 1023);

	if(n < 0)
	{
		error("ERROR reading from socket");
	}
	
	printf("%s\n", buffer);
	return 0;

}


