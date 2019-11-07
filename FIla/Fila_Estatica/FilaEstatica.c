#include "FilaEstatica.h"   

Fila* cria_Fila(){
    Fila *fi= (Fila*)  malloc(sizeof(aluno));
    if(fi != NULL){
        fi-> inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

int insere_fila(Fila* fi){
    if(&aux==NULL){
        return 0;
    }
    if (fila_cheia(&aux)){
        return 0;
    }
    printf("Digite o nome do aluno:");
    scanf("%s",aux.dados[aux.final].nome);
    printf("Digite o numero de matricula do aluno:");
    scanf("%d",&aux.dados[aux.final].matricula);
    printf("Digite o valor da primeira nota do aluno:");
    scanf("%f",&aux.dados[aux.final].nota[0]);
    printf("Digite o valor da segunda nota do aluno:");
    scanf("%f",&aux.dados[aux.final].nota[1]);
    printf("Digite o valor da terceira nota do aluno:");
    scanf("%f",&aux.dados[aux.final].nota[2]);
    aux.final=aux.final+1;
    aux.qtd++;
    menu(&aux);
}

void imprime_aluno(Fila* fi){
    int i;  
    for(i=0;i<aux.qtd;i++){
        printf("Dados dos alunos\n");
        printf("NOME = %s\n",aux.dados[i].nome);
        printf("MATRICULA = %d\n",aux.dados[i].matricula);
        printf("1ª NOTA = %0.f\n",aux.dados[i].nota[0]);
        printf("2ª NOTA = %0.f\n",aux.dados[i].nota[1]);
        printf("3ª NOTA = %0.f\n",aux.dados[i].nota[2]);
        printf("\n");
    }
    menu(&aux);   
} 

void menu(Fila* fi){
    int i,resposta=1;
    fputs(" ", stdout);
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|"); 
    for(i=0;i<80;i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for(i=0;i<79;i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|  ");
    printf("Digite (1) para fazer o cadastro de um novo aluno (2) para Imprimir os dados dos alunos (3) para Imprimir a quantidade de alunos cadastrados                     |");
    printf("\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("------------->");
    scanf("%d",&resposta);
    fflush(stdin);

    if(resposta==1){
       insere_fila(&aux);
    }
    if(resposta==2){
        imprime_aluno(&aux);
    }
    if(resposta==3){
        tamanho_fila(&aux);
    }
    if(resposta!=1||resposta!=2||resposta!=3){
        exit(0);    
    }
}

int tamanho_fila(Fila* fi){
    if(&aux==NULL){
        return -1;
    }
    printf("%d\n",aux.qtd);
    menu(&aux);
}

int fila_cheia(Fila* fi){
    if(&aux==NULL){
        return -1;
    }
    if(aux.qtd==MAX){
        return 1;
    }
    else{
        return 0;
    }
}