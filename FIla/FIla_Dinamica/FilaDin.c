#include "FilaDin.h"

fila* inicia_fila(){
    fila *fi=(fila*) malloc(sizeof(registro));
    if(fi!=NULL){
        fi->inicio=NULL;
        fi->final=NULL;
        fi->quantidade=0;
    }
    return fi;
}

void tamanho_fila(fila* fi){
    printf("Há o total de %d aluno(s) registrado(s)\n",fi->quantidade);
    menu(fi);
}

void imprime_fila(fila* fi){
    pont end=fi->inicio;
    while(end!=NULL){
        printf("Dados dos alunos\n");
        printf("NOME = %s\n",end->reg.nome);
        printf("MATRICULA = %d\n",end->reg.matricula);
        printf("1ª NOTA = %0.f\n",end->reg.nota[0]);
        printf("2ª NOTA = %0.f\n",end->reg.nota[1]);
        printf("3ª NOTA = %0.f\n",end->reg.nota[2]);
        printf("\n");
        end=end->prox;
    }
    menu(fi);
}

int  insere_fila(fila* fi){
    pont novo=(pont) malloc(sizeof(elemento));
    registro copia;
    if(fi==NULL){
        return 0;
    }
    pont end=fi->inicio;
    printf("Digite o nome do aluno:");
    scanf("%s",copia.nome);
    printf("Digite o numero de matricula do aluno:");
    scanf("%d",&copia.matricula);
    printf("Digite o valor da primeira nota do aluno:");
    scanf("%f",&copia.nota[0]);
    printf("Digite o valor da segunda nota do aluno:");
    scanf("%f",&copia.nota[1]);
    printf("Digite o valor da terceira nota do aluno:");
    scanf("%f",&copia.nota[2]);
    while(end!=NULL){
        if(end->reg.matricula==copia.matricula){
            printf("Não é possível fazer o cadastro pois já há um aluno com este número de matrícula cadastrado.\n");
            printf("Forneça por favor os novos dados do aluno.\n");
            printf("Digite o nome do aluno:");
            scanf("%s",copia.nome);
            printf("Digite o numero de matricula do aluno:");
            scanf("%d",&copia.matricula);
            printf("Digite o valor da primeira nota do aluno:");
            scanf("%f",&copia.nota[0]);
            printf("Digite o valor da segunda nota do aluno:");
            scanf("%f",&copia.nota[1]);
            printf("Digite o valor da terceira nota do aluno:");
            scanf("%f",&copia.nota[2]);
            break;
        }
    }
    novo->reg=copia;
    novo->prox=NULL;
    if (fi->inicio==NULL){
        fi->inicio=novo;
    }
    else{
        fi->final->prox=novo;
    }
    fi->final=novo;
    fi->quantidade++;
    menu(fi);
}
int remove_fila(fila* fi){
    if(fi->inicio==NULL){
        return 0;   
    }
    pont apagar=fi->inicio;
    fi->inicio=fi->inicio->prox;
    free(apagar);
    if(fi->inicio==NULL){
        fi->final=NULL;
    }
    fi->quantidade--;
    menu(fi);
    return 1;
}

void menu(fila* fi){
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
    printf("|\n|           ");
    printf("Digite (1) para fazer o cadastro de um novo aluno (2) para Imprimir os dados dos alunos (3) para Imprimir a quantidade de alunos cadastrados            |");
    printf("\n");
    printf("|"); 
    for(i=0;i<27;i++){
        fputs(" ", stdout);
    }      
    printf("(4)  para remover um aluno cadastrado e Qualquer número diferente dos anteriores para fechar o programa.");
    for(i=0;i<32;i++){
        fputs(" ", stdout);
    }  
    printf("|\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("------------->");
    scanf("%d",&resposta);
    fflush(stdin);

    if(resposta==1){
       insere_fila(fi);
    }
    if(resposta==2){
        imprime_fila(fi);
    }
    if(resposta==3){
        tamanho_fila(fi);
    }
    if(resposta==4){
        remove_fila(fi);
    }
    if(resposta!=1||resposta!=2||resposta!=3||resposta!=4){
        exit(0);    
    }
}   