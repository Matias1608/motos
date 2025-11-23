#ifndef MY_SOCK_H
#define MY_SOCK_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <netdb.h>

#define BACKLOG 10

struct DatosCliente
{
    char dir_ip[30];
    int cli_sock;
};

int CrearSocket(int puerto);

int AceptarConexion(int sockfd, struct DatosCliente *datos_cliente);

int ConectarServidor(char *h, int puerto);

#endif // SOCKETS_H 
