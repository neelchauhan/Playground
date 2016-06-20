#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
	int sock;
	struct sockaddr_in server;
	char message[] = "GET / HTTP/1.0\nHost: www.neelc.org\n\n";

	sock = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_addr.s_addr = inet_addr("107.191.40.174");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	connect(sock, (struct sockaddr *)&server, sizeof(server));

	send(sock, message, strlen(message), 0);

	while (1) {
		char buffer[1024];
		int size = recv(sock, buffer, 512, 0);
		if (size == 0) break;
		buffer[size] = '\0';
		printf("%s", buffer);
	}
	
	close(sock);
	printf("\n");
	return 0;
}
