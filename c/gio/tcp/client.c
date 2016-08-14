#include <stdio.h>
#include <string.h>
#include <gio/gio.h>

int main(int argc, char *argv[]) {
	GSocket *conn;
	GError *error = NULL;
	GSocketAddress *addr;
	conn = g_socket_new(G_SOCKET_FAMILY_IPV4, G_SOCKET_TYPE_STREAM, G_SOCKET_PROTOCOL_TCP, &error);
	addr = g_inet_socket_address_new_from_string("107.191.40.174", 80);
	g_socket_connect(conn, addr, NULL, &error);

	char *msg = "GET / HTTP/1.1\r\nHost: www.neelc.org\r\n\r\n";
	g_socket_send(conn, msg, strlen(msg), NULL, &error);

	char xbuffer[2048];
	g_socket_receive(conn, xbuffer, 2048, NULL, &error);
	puts(xbuffer);

	g_socket_close(conn, &error);
	return 0;
}
