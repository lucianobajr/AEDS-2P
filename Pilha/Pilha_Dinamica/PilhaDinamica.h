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
}elemento;

typedef elemento* pont;

typedef struct{
    pont topo;
    int quantidade;
}Pilha;

Pilha* cria_pilha();
int  insere_pilha(Pilha* pi);
int remove_pilha(Pilha* pi);
void tamanho_pilha(Pilha* pi);
void imprime_pilha(Pilha* pi);
void menu(Pilha* pi);