#include "lista.h"
#include <ctype.h>
#include <string.h>

/*struct nodo* crear_nodo (int a)
{
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->dato=a;
    nuevo->p=NULL;

    return nuevo;
};*/

void ModificarLista(struct nodo **a)
{
    struct nodo *nuevo, *aux;
    char marca[20];
    printf("Ingrese la marca de la moto: ");
    scanf("%s", marca);
    for(int i=0; marca[i] != '\0'; i++)
    {
        marca[i]=toupper(marca[i]);
    }
    aux=*a;
    /*if(aux==NULL)
    {
    nuevo=malloc(sizeof(struct nodo));
    memset(nuevo, 0, sizeof(struct nodo));
    strcpy(nuevo->marca, marca);
    nuevo->p=NULL;
    *a=nuevo;
    aux=*a;
    }*/
    
    while (aux->p != NULL && strcmp(aux->marca, marca) != 0)
    {
        aux=aux->p;
    }

    if(strcmp(aux->marca, marca) == 0)
    {
        int op;
        printf("La marca ya existe en la lista.\n");
        printf("Desea buscar modelo?\n1-Si/2-No\n");
        scanf("%d",&op);
        while(op<1 || op>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &op);
        }
        if(op==1)
        {
            AgregarMoto(&aux->moto);
        }
    }
    if(aux->p == NULL && strcmp(aux->marca, marca) != 0)
    {   
        int op;
        printf("La marca no existe. Desea agregarla? (1-Si / 2-No):\n ");
        scanf("%d", &op);
        while(op<1 || op>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &op);
        }
        if(op==1)
        {
        nuevo=malloc(sizeof(struct nodo));
        memset(nuevo, 0, sizeof(struct nodo));
        strcpy(nuevo->marca, marca);
        nuevo->p=NULL;
        aux->p=nuevo;
        }
        if(op==2)
        {
            return;
        }
    }
};

void AgregarMoto(struct moto **m)
{
    struct moto *nueva_moto, *aux;

}
