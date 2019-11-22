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
}shel;

void shell(shel *vpower);
void insere(arquivo *arq);
void imprime(arquivo *arq);
void imprime_ordenado(shel *vpower);
void menu(arquivo *arq,shel *vpower);
void inicia_bob(arquivo *arq,shel *vpower);
void print_menu();