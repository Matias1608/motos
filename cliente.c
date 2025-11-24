#include "mysock.h" 
#include "lista.h"
#include <fcntl.h>

struct nodo* lista_motos=NULL;
    
void AutoguardarLista(int signal_number);


int main(void)
{
    FILE *datos_lista;
    int sockfd_cl;
    int puerto = 1608;
    int opcion;
    char buffer[100];
    memset(buffer, 0, sizeof(buffer)); 

    signal(SIGALRM, AutoguardarLista);

    while (1)
    {
        alarm(10); // Configura la alarma para 30 minutos
        pause(); // Espera a que llegue una señal
    }
     

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

    send(sockfd_cl, "Mensaje del cliente recibido correctamente", 42, 0);

    //lista_motos=NULL;
    

    datos_lista=fopen("stock.dat", "rb"); 
    if(datos_lista != NULL)
    {
        //Cargar lista desde archivo
        lista_motos=LeerLista(datos_lista);
        fclose(datos_lista);
    }
    else
    {
        printf("No se encontro el archivo stock.dat, se creara uno nuevo al guardar los datos.\n");
    }

    do
    {
        printf("--Menu--\n\n1-Buscar'\'modificar\n2-Listado\n3-Salir y guardar\n");
        scanf("%d", &opcion);
        while(opcion<1 || opcion>3)
        {
            perror("Error, ingrese una opcion valida (1-3)\n");
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
            //Listado   
            MostrarListado(lista_motos);
            break;

        case 3:
            //Salir y guardar
            GuardarLista(lista_motos);
            break;

        default:
            break;
        }
    }while(opcion!=3);

    return 0;
}

void AutoguardarLista(int signal_number)
{
    printf("Autoguardando lista de stock...\n");
    //Codigo para autoguardar la lista
    GuardarLista(lista_motos);

}
