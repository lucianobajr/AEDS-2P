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
}quick;

void insere(arquivo *arq);
void menu(arquivo *arq,quick *nesquik);
void print_menu();
void imprime(arquivo *arq);
void imprime_ordenado(quick *nesquik);
void inicia_nesquik(arquivo *arq,quick *nesquik);
void quickSort(quick *nesquik,int low, int high);
void swap (quick *nesquik,int i,int j);
int partition (quick *nesquik, int low, int high);