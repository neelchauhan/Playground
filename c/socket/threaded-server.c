#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <pthread.h>

const int REUSEADDR = 1;

void *handle_socket(void *sock_void_ptr) {
	int sock = *(int*)sock_void_ptr;
	write(sock, "Hi!\n", 4);
	char buffer[1024];
	int size = recv(sock, buffer, 512, 0);
	buffer[size] = '\0';
	write(sock, buffer, size);
	close(sock);

	return NULL;
}

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
		pthread_t client_sock_thr;
		client_sock = accept(serv_sock, (struct sockaddr*)NULL, NULL);
		pthread_create(&client_sock_thr, NULL, handle_socket, (void*)&client_sock);
	}

	close(serv_sock);
	return 0;
}
