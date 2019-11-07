#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int matricula;
    char nome[30];
    float nota[3];
}registro;

typedef struct aux{
    registro reg;
    struct aux* prox; 
}elemento,*pont;

typedef struct{
    pont inicio;
    int quantidade; 
}Lista;

Lista* inicia_lista();
int  insere_lista(Lista* li);
void tamanho_lista(Lista* li);
void imprime_lista(Lista* li);
void menu(Lista* li);
int remove_lista(Lista* li);