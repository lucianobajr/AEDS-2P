
#include "PilhaDinamica.h"

Pilha* cria_pilha(){
    Pilha *pi=(Pilha*) malloc(sizeof(registro));
    if(pi!=NULL){
        pi->topo=NULL;
        pi->quantidade=0;
    }
    return pi;
}

int insere_pilha(Pilha* pi){
    pont novo=(pont) malloc(sizeof(elemento));
    registro copia;
    if(pi==NULL){
        return 0;
    }
    pont end=pi->topo;
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
        end=end->prox;
    }
    novo->reg=copia;
    novo->prox=pi->topo;
    pi->topo=novo;
    pi->quantidade++;
    menu(pi);
}

int remove_pilha(Pilha* pi){
    if(pi->topo==NULL){
        return 0;   
    }
    pont apagar=pi->topo;
    pi->topo=pi->topo->prox;
    free(apagar);
    pi->quantidade--;
    menu(pi);
    return 1;
}

void imprime_pilha(Pilha* pi){
    pont end=pi->topo;
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
    menu(pi);
}

void tamanho_pilha(Pilha* pi){
    printf("Há o total de %d aluno(s) registrado(s)\n",pi->quantidade);
    menu(pi);
}

void menu(Pilha* pi){
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
       insere_pilha(pi);
    }
    if(resposta==2){
        imprime_pilha(pi);
    }
    if(resposta==3){
        tamanho_pilha(pi);
    }
    if(resposta==4){
        remove_pilha(pi);
    }
    if(resposta!=1||resposta!=2||resposta!=3||resposta!=4){
        exit(0);    
    }
}   