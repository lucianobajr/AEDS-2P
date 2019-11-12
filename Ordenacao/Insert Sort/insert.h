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
}insert;

void insercao(insert *croquete);
void insere(arquivo *arq);
void imprime(arquivo *arq);
void imprime_ordenado(insert *croquete);
void menu(arquivo *arq,insert *croquete);
void inicia_croc(arquivo *arq,insert *croquete);
void print_menu();