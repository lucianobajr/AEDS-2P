#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50 

typedef struct{
    int matricula;
    char nome[30];
    float nota[3];
}aluno;

typedef struct{
    int topo,qtd;
    aluno dados[MAX];
}Pilha;

Pilha*  cria_Pilha();
void menu(Pilha* pi);
int tamanho_pilha(Pilha* pi);
int insere_pilha(Pilha* pi);
int remove_pilha(Pilha* pi);
void imprime_aluno(Pilha* pi);
Pilha aux;