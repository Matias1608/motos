#ifndef LISTA_H
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


struct nodo
{
    char marca[20];
    struct moto *moto;
    struct nodo *p;
};

struct moto
{
    char modelo[20];
    int anio;
    float precio;
    int stock;
    struct moto*m;
};

struct nodo* crear_nodo (int a);

struct nodo* insert_end (struct nodo *a, int b);

void ModificarLista(struct nodo **a);

#endif // LISTA_H