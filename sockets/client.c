// client.c

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>

int sock;

void handler(int sig);

int main(int argc, char* argv[])
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	signal(SIGINT, handler);
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9999);

	struct hostent * host;
	host = gethostbyname(argv[1]);

	if (!host)
	{
		printf("Host not found, exiting\n");
		exit(1);
	}

	if (sock == -1)
	{
		printf("Error creating socket. exiting\n");
		exit(1);
	}

	memcpy(&server.sin_addr, host->h_addr, host->h_length);

	if (connect(sock, (struct sockaddr*) &server, sizeof (struct sockaddr_in)) == -1)
	{
		printf("Error connecting the socket.\n");
		close(sock);
		exit(1);
	}

	char * input = calloc(100, sizeof(char));
	char data[256] = {};
	size_t readin = 100;
	while(1) 
	{
		getline(&input, &readin, stdin);
		write(sock, input, strlen(input) + 1);
		read(sock, data, 256);
		printf("Client recvd: %s\n", data);
	}
	close(sock);
	return 0;
}

void handler(int sig)
{
	close (sock);
	exit(0);
}

