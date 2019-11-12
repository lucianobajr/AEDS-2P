#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int valor;
}item;

typedef struct{
    item *itens_arquivo;
    int quantidade_arquivo;
}arquivo;

typedef struct{
    item *itens;
    int quantidade;
}selec;

void selecao(selec *alec);
void insere(arquivo *arq);
void imprime(arquivo *arq);
void imprime_ordenado(selec *alec);
void menu(arquivo *arq,selec *alec);
void inicia_bob(arquivo *arq,selec *alec);
void print_menu();