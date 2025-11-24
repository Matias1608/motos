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
    int sel;
    struct nodo *nuevo, *aux;
    char marca[20];
    printf("Ingrese la marca de la moto: ");
    scanf("%s", marca);
    printf("Ingreso: %s\n¿Es correcto? (1-Si / 2-No):\n", marca);
    scanf("%d", &sel);
    while(sel<1 || sel>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &sel);
        }
    while(sel==2)
    {
        printf("Ingrese la marca de la moto: ");
        scanf("%s", marca);
        printf("Ingreso: %s\n¿Es correcto? (1-Si / 2-No):\n", marca);
        scanf("%d", &sel);
    }

    for(int i=0; marca[i] != '\0'; i++)
    {
        marca[i]=toupper(marca[i]);
    }
    aux=*a;
    if(aux==NULL)
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
        *a=nuevo;
        aux=*a;
        printf("Desea agregar un modelo?\n1-Si/2-No\n");
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
        if(op==2)
        {
            return;
        }
 
    }
    else
    {
    while (aux->p != NULL && strcmp(aux->marca, marca) != 0)
    {
        aux=aux->p;
    }

    if(strcmp(aux->marca, marca) == 0)
    {
        int op;
        printf("La marca ya existe en la lista.\n");
        printf("Desea buscar un modelo?\n1-Si/2-No\n");
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
        printf("Desea agregar un modelo?\n1-Si/2-No\n");
        scanf("%d",&op);
        while(op<1 || op>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &op);
        }
        if(op==1)
        {
            AgregarMoto(&nuevo->moto);
        }
        }
        if(op==2)
        {
            return;
        }
    }
    }
};

void AgregarMoto(struct moto **m)
{
    int sel;
    struct moto *nueva_moto, *aux;
    char modelo[20];
    printf("Ingrese modelo:\n");
    scanf("%s", modelo);
    printf("Ingreso: %s\n¿Es correcto? (1-Si / 2-No):\n", modelo);
    scanf("%d", &sel);
    while(sel<1 || sel>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &sel);
        }
    while(sel==2)
    {
        printf("Ingrese modelo:\n");
        scanf("%s", modelo);
        printf("Ingreso: %s\n¿Es correcto? (1-Si / 2-No):\n", modelo);
        scanf("%d", &sel);
        while(sel<1 || sel>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &sel);
        }
    }

    for(int i=0; modelo[i] != '\0'; i++)
    {
        modelo[i]=toupper(modelo[i]);
    }
    aux=*m;
    if(aux==NULL)
    {
        int op;
        printf("Modelo no encontrado. Desea agregarlo? (1-Si / 2-No):\n ");
        scanf("%d", &op);
        
        while(op<1 || op>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &op);
        }
        
        if(op==1)
        {
            int stock, precio;
            precio=0;
            stock=0;
            nueva_moto=malloc(sizeof(struct moto));
            memset(nueva_moto, 0, sizeof(struct moto));
            strcpy(nueva_moto->modelo, modelo);
            nueva_moto->m=NULL;
            *m=nueva_moto;
            aux=*m;
            printf("Ingrese stock:");
            scanf("%d",&stock);
            aux->stock=stock;
            printf("Ingrese precio:$");
            scanf("%d",&precio);
            aux->precio=precio;
        }
        
        if(op==2)
        {
            return;
        }
 
    }
    else
    {
        while (aux->m != NULL && strcmp(aux->modelo, modelo) != 0)
        {
            aux=aux->m;
        }

        if(strcmp(aux->modelo, modelo) == 0)
        {
            int op;
            printf("Modelo encontrado.\n");
            printf("Desea modificar?\n1-Si/2-No\n");
            scanf("%d",&op);
            while(op<1 || op>2)
            {
                printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
                while(getchar() != '\n');
                scanf("%d", &op);
            }
            if(op==1)
            {
            int mod; 
            printf("Modificar:\n1-Stock\n2-Precio\n");
            scanf("%d", &mod);
            while(mod<1 || mod>2)
            {
                printf("Opcion invalida. Ingrese 1 para stock o 2 para precio:\n");
                while(getchar() != '\n');
                scanf("%d", &mod);
            }
            switch(mod)
            {
                case 1:
                    int stock;
                    printf("Stock actual:%d\n", aux->stock);
                    printf("Ingrese nuevo stock:");
                    scanf("%d",&stock);
                    aux->stock=stock;
                    break;
                case 2:
                    int precio;
                    printf("Precio actual:$%d\n", aux->precio);
                    printf("Ingrese precio:$");
                    scanf("%d",&precio);
                    aux->precio=precio;
                    break;
                default:
                    break;
            }
        }
    }
    if(aux->m == NULL && strcmp(aux->modelo, modelo) != 0)
    {   
        int op;
        printf("Modelo no encontrado. Desea agregarlo? (1-Si / 2-No):\n ");
        scanf("%d", &op);
        
        while(op<1 || op>2)
        {
            printf("Opcion invalida. Ingrese 1 para Si o 2 para No:\n");
            while(getchar() != '\n');
            scanf("%d", &op);
        }
        
        if(op==1)
        {   int stock, precio;
            nueva_moto=malloc(sizeof(struct moto));
            memset(nueva_moto, 0, sizeof(struct moto));
            strcpy(nueva_moto->modelo, modelo);
            nueva_moto->m=NULL;
            aux->m=nueva_moto;
            aux=nueva_moto;
            printf("Ingrese stock:");
            scanf("%d",&stock);
            aux->stock=stock;
            printf("Ingrese precio:$");
            scanf("%d",&precio);
            aux->precio=precio;
        }
        
        if(op==2)
        {
            return;
        }
 
    }                                                                        
    }
}

void GuardarLista(struct nodo *a)
{
    FILE *archivo_lista=fopen("stock.dat", "wb");

    if(archivo_lista==NULL)
    {
        perror("Error al crear stock.dat");
        return;
    }
    struct nodo *aux=a;
    while(aux !=NULL)
    {
        int contador=0;
  
        struct moto *temp = aux->moto;
        while (temp!=NULL)
        {
            contador++;
            temp=temp->m;
        }

        fwrite(aux->marca,sizeof(char),20,archivo_lista);
        fwrite(&contador, sizeof(int),1, archivo_lista);

        temp=aux->moto;

        while (temp!=NULL)
        {
            fwrite(temp, sizeof(struct moto),1, archivo_lista);
            temp=temp->m;
        }
        aux=aux->p;
    }

    fclose(archivo_lista);
    printf("Stock guardado en stock.dat");
}

struct nodo* LeerLista(FILE *fd)
{
    struct nodo *head, *actual, *prev;
    struct moto *nueva, *previa;
    char marca[20];
    int nmot;
    head=malloc(sizeof(struct nodo));
    head->moto=NULL;
    while(fread(&marca, sizeof(marca),1,fd)>0)
    {
        actual=malloc(sizeof(struct nodo));
        strcpy(actual->marca, marca);
        fread(&nmot,sizeof(int),1,fd);
        for(int i=0; i<nmot; i++)
        {   
            nueva=malloc(sizeof(struct moto));
            fread(nueva, sizeof(struct moto),1,fd);
            if(actual->moto==NULL)
            {
                actual->moto=nueva;
                nueva->m=NULL;
            }
            else
            {
                previa->m=nueva;
                nueva->m=NULL;
            }
            previa=nueva;   
        }
        if(head==NULL)
        {
            head=actual;
        }
        else
        {
            prev->p=actual;
        }
        prev = actual;
       
    }
     return head;
}
