#include "quick.h"


void swap (quick *nesquik,int i,int j){
    int t;
    t=nesquik->itens[i].valor;
    nesquik->itens[i].valor=nesquik->itens[j].valor;
    nesquik->itens[j].valor=t;
}

int partition (quick *nesquik, int low, int high){ 
    int pivot = nesquik->itens[high].valor;    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++)  
    { 
        // If current element is smaller than the pivot 
        if (nesquik->itens[j].valor < pivot) { 
            i++;    // increment index of smaller element 
            swap(nesquik,i, j); 
        } 
    } 
    swap(nesquik,i + 1,high); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */

void quickSort(quick *nesquik,int low, int high) { 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(nesquik, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(nesquik, low, pi - 1); 
        quickSort(nesquik, pi + 1, high); 
    } 
} 

void insere(arquivo *arq){
    FILE *teste;
    int tamanho_vet, i = 0, cont = 0;
    char nome[30];
    item copia;
    printf("Digite o nome do arquivo para o caso de teste (Na mesma pasta e com .txt) = ");
    fgets(nome, 30, stdin);
    nome[strlen(nome) - 1] = '\0';
    teste = fopen(nome, "r");
    if (teste == NULL){
        printf("dando erro");
    }
    else{
        fscanf(teste, "%d", &tamanho_vet);
        item *aux = (item *)malloc(tamanho_vet * sizeof(item));
        if (aux == NULL){
            printf("ERRO");
        }

        while (!feof(teste)){
            fscanf(teste, "%d", &copia.valor);
            aux[i].valor = copia.valor;
            i++;
        }
        arq->itens_arquivo = aux;
        arq->quantidade_arquivo = tamanho_vet;
        fclose(teste);
        i--;
    }
}

void menu(arquivo *arq,quick *nesquik){
    int resposta=1;
    insere(arq);
    inicia_nesquik(arq, nesquik);
    int left = nesquik->quantidade;
    do{
        print_menu();
        scanf("%d", &resposta);
        if(resposta==1||resposta==2){
            if (resposta == 1){
                imprime(arq);
            }
            if (resposta == 2){
                quickSort(nesquik,0,left-1);
                imprime_ordenado(nesquik);
            }
        }
        else{
            break;
        }
    }
    while(resposta==1||resposta == 2);
}

void imprime(arquivo *arq){
    int i;
    printf("ITENS\n");
    for (i = 0; i < arq->quantidade_arquivo; i++){
        printf("valor = %d\n", arq->itens_arquivo[i].valor);
    }
}

void imprime_ordenado(quick *nesquik){
    int i;
    printf("ITENS ORDENADOS\n");
    for (i = 0; i < nesquik->quantidade; i++){
        printf("valor = %d\n", nesquik->itens[i].valor);
    }
}

void inicia_nesquik(arquivo *arq, quick *nesquick){
    nesquick->itens = arq->itens_arquivo;
    nesquick->quantidade = arq->quantidade_arquivo;
}

void print_menu(){
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 21; i++){
        fputs(" ", stdout);
    }
    printf("Digite (1) para Imprimir os valores inseridos  (2)  para Imprimir os valores ordenadas");
    for (i = 0; i < 45; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 42; i++){
        fputs(" ", stdout);
    }
    printf("  e Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 53; i++){
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("------------->");
    fflush(stdin);
}