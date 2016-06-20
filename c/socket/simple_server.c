#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>

const int REUSEADDR = 1;

int main(int argc, char *argv[]) {
	int serv_sock, client_sock;
	struct sockaddr_in serv_addr;

	serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));

	setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &REUSEADDR, sizeof(REUSEADDR));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(8888);

	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	listen(serv_sock, 0);

	while (1) {
		client_sock = accept(serv_sock, (struct sockaddr*)NULL, NULL);

		write(client_sock, "Hi!\n", 4);

		close(client_sock);

	}

	close(serv_sock);
	return 0;
}
