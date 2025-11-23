#include "mysock.h" 
#include "lista.h"
#include <fcntl.h>

int main(void)
{
    int stockfd;
    int sockfd_cl;
    int puerto = 1608;
    char buffer[100];
    struct nodo* lista_motos, *aux;
    int opcion;

    memset(&lista_motos, 0, sizeof(lista_motos));
    memset(&aux, 0, sizeof(aux));

    stockfd=open("stock.dat", O_RDWR | O_CREAT, 0660);
    if(stockfd == -1)
    {
        perror("Error al abrir el archivo de stock");
        return -1;
    }
    printf("--Menu--\n\n1-Buscar\n2-Venta\n3-Ingreso\n4-Listado\n5-Salir\n");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>5)
    {
        perror("Error, ingrese una opcion valida (1-5)\n");
        while(getchar() != '\n')
        scanf("%d", &opcion);
    }
    switch (opcion)
    {
    case 1:
        //Buscar
        ModificarLista(&lista_motos);
        break;
    
    case 2:
        //Venta 

        break;
    
    case 3:
        //Ingreso

        break;
    
    case 4:
        //Listado   
        
        break;
    
    default:
        break;
    }


    memset(buffer, 0, sizeof(buffer));  

    sockfd_cl = ConectarServidor("localhost", puerto);

    if(sockfd_cl == -1)
    {
        perror("Error al conectar con el servidor");
        return -1;
    }

    if(sockfd_cl != -1)
    {
        printf("Conexion al servidor exitosa\n");
    }

   recv(sockfd_cl, buffer, sizeof(buffer)-1, 0);

   printf("Mensaje del servidor: %s\n", buffer);

    return 0;
}