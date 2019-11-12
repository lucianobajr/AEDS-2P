 
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
}bubble;

void bolha(bubble * bob);
void insere(arquivo *arq);
void imprime(arquivo *arq);
void imprime_ordenado(bubble *bob);
void menu(arquivo *arq,bubble *bob);
void inicia_bob(arquivo *arq,bubble *bob);
void print_menu();