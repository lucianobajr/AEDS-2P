
#include "PilhaEstatica.h"
Pilha* cria_Pilha(){
    Pilha *pi= (Pilha*)  malloc(sizeof(aluno));
    if(pi != NULL){
        pi->topo=-1;
    }    
    return pi;
}

int insere_pilha(Pilha* pi){
    if(&aux==NULL){
        return 0;
    }
    if(aux.topo>=MAX-1){
        return 0;
    }
    aux.topo=aux.topo+1;
    printf("Digite o nome do aluno:");
    scanf("%s",aux.dados[aux.topo].nome);
    printf("Digite o numero de matricula do aluno:");
    scanf("%d",&aux.dados[aux.topo].matricula);
    printf("Digite o valor da primeira nota do aluno:");
    scanf("%f",&aux.dados[aux.topo].nota[0]);
    printf("Digite o valor da segunda nota do aluno:");
    scanf("%f",&aux.dados[aux.topo].nota[1]);
    printf("Digite o valor da terceira nota do aluno:");
    scanf("%f",&aux.dados[aux.topo].nota[2]);
    aux.qtd++;
    menu(&aux);
}

int remove_pilha(Pilha* pi){
    if(&aux==NULL || aux.qtd==0){
        return 0;
    }
    aux.dados[aux.topo]=aux.dados[aux.topo-1];
    pi->qtd--;
    menu(&aux);
    return 1;
}
void imprime_aluno(Pilha* pi){
    int i;
    if(aux.qtd==0){
        printf("Não há nenhum aluno cadastrado.\n");
        printf("\n");
        menu(&aux);
    }
    else{
        for(i=aux.topo;i>0;i--){
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
}

int tamanho_pilha(Pilha* pi){
    if(&aux==NULL){
        return -1;
    }
    printf("%d\n",aux.qtd);
    menu(&aux);
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
        imprime_aluno(pi);
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