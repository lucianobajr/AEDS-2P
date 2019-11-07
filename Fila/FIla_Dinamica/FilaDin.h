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
    pont final;
    int quantidade; 
}fila;

fila* inicia_fila();
int  insere_fila(fila* fi);
void tamanho_fila(fila* fi);
void imprime_fila(fila* fi);
void menu(fila* fi);
int remove_fila(fila* fi);