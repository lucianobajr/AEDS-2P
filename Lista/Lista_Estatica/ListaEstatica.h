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
    int total;
    int qtd;
    int maior;
    aluno dados[MAX];
}Lista;

Lista* cria_lista();
void menu(Lista* li);
void  libera_lista(Lista* li);
void imprime_lista(Lista* li);
void imprime_aluno(Lista* li);
void remove_lista(Lista* li);
int tamanho_lista(Lista* li);
int insere_lista(Lista* li);
Lista aux;