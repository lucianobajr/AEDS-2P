#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define MAX 100

typedef struct{
    int matricula;
    char nome[30];
    float nota[3];
}aluno;

typedef struct{
    int inicio, final, qtd;
    aluno dados[MAX];
}Fila;

Fila*  cria_Fila();
void menu(Fila* fi);
int tamanho_fila(Fila* fi);
int fila_cheia(Fila* fi);
int insere_fila(Fila* fi);
void imprime_aluno(Fila* fi);
Fila aux;