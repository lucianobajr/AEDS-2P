#include "shell.h"

void shell(shel *vpower){
    int i , j , value;
    int h = 1;
    while(h < vpower->quantidade) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < vpower->quantidade; i++) {
            value = vpower->itens[i].valor;
            j = i;
            while (j > h-1 && value <= vpower->itens[j - h].valor){
                vpower->itens[j].valor = vpower->itens[j - h].valor;
                j = j - h;
            }
            vpower->itens[j].valor = value;
        }
        h = h/3;
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

void menu(arquivo *arq,shel *vpower){
    int resposta=1;
    insere(arq);
    inicia_bob(arq, vpower);
    do{
        print_menu();
        scanf("%d", &resposta);
        if(resposta==1||resposta==2){
            if (resposta == 1){
                imprime(arq);
            }
            if (resposta == 2){
                shell(vpower);
                imprime_ordenado(vpower);
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

void imprime_ordenado(shel *vpower){
    int i;
    printf("ITENS ORDENADOS\n");
    for (i = 0; i < vpower->quantidade; i++){
        printf("valor = %d\n", vpower->itens[i].valor);
    }
}

void inicia_bob(arquivo *arq, shel *vpower){
    vpower->itens = arq->itens_arquivo;
    vpower->quantidade = arq->quantidade_arquivo;
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