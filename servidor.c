#include "mysock.h"
#include <fcntl.h>
#include <signal.h>

int socket_fd;

void *AtenderCliente(void *arg)
{
    struct DatosCliente *datos_cliente = (struct DatosCliente *)arg;

    printf("Cliente conectado desde IP: %s\n", datos_cliente->dir_ip);
    
    send(datos_cliente->cli_sock, "Hola desde el servidor!\n", 23, 0);

    return NULL;
}
int main(void)
{
    
    struct DatosCliente datos_cliente;
    int puerto = 1608;

    socket_fd = CrearSocket(puerto);
    if(socket_fd == -1)
    {
        return -1;
    }   

    while (1)
    {
    
    AceptarConexion(socket_fd, &datos_cliente);

    pthread_t hilo_cliente;

    if(pthread_create(&hilo_cliente, NULL, AtenderCliente, (void *)&datos_cliente) != 0)
    {
        perror("Error al crear el hilo para atender al cliente");
        close(datos_cliente.cli_sock);

    }
    }
    
    return 0;
}