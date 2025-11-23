#include "mysock.h"

int CrearSocket(int puerto)
{
    int socket_fd;
    struct sockaddr_in serv_dir;
    
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1)
    {
        perror("Error al crear el socket");
        return -1;  
    }

    memset(&serv_dir, 0, sizeof(serv_dir));
    serv_dir.sin_family = AF_INET;
    serv_dir.sin_addr.s_addr = INADDR_ANY;
    serv_dir.sin_port = htons(puerto);

    bind(socket_fd, (struct sockaddr *)&serv_dir, sizeof(serv_dir));

    if(socket_fd == -1)
    {
        perror("Error en bind");
        close(socket_fd);
        return -1;  
    }

    listen(socket_fd, BACKLOG);

    if(socket_fd == -1)
    {
        perror("Error en listen");
        close(socket_fd);
        return -1;  
    }

    return socket_fd;
}

int AceptarConexion(int socket_fd, struct DatosCliente *d)
{
    int cli_sock;
    struct sockaddr_in cli_dir;
    socklen_t cli_len = sizeof(cli_dir);

    cli_sock = accept(socket_fd, (struct sockaddr *)&cli_dir, &cli_len);
    if(cli_sock == -1)
    {
        perror("Error al aceptar la conexion");
        return -1;  
    }
    strcpy(d->dir_ip, inet_ntoa(cli_dir.sin_addr));
    d->cli_sock = cli_sock;

    return 0;
}

int ConectarServidor(char *h, int puerto)
{
    int socket_fd;
    struct hostent *he;
    struct sockaddr_in serv_dir;

    if((he=gethostbyname((const char *)h))==NULL)
    {
        perror("Error en gethostbyname");
        return -1;  
    }

    if ((socket_fd=socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error al crear el socket");
        return -1;
    }
    memset(&serv_dir, 0, sizeof(serv_dir));
    serv_dir.sin_family = AF_INET;
    serv_dir.sin_port = htons(puerto);
    memcpy(&serv_dir.sin_addr, he->h_addr_list[0],he->h_length);
    //serv_dir.sin_addr = *((struct in_addr *)he->h_addr_list[0]);

    if(connect(socket_fd,(struct sockaddr *) &serv_dir, sizeof(serv_dir)) == -1)
    {
        perror("Error en connect");
        close(socket_fd);
        return -1;  
    }

    return socket_fd;
}

