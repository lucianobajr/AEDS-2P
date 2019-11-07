#include "ListaEstatica.h"
Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li!=NULL){
       li->qtd=0;
       aux.maior=aux.qtd;
    }
    return li;
}

int insere_lista(Lista* li){
    int resposta,posicao=0;
    if(&aux==NULL){
        return 0;
    }
    if(aux.qtd==MAX){
        return 0;
    }
    printf("Digite (1) se deseja cadastrar em uma posição específica e (2) se deseja cadastrar sequencialmente:");
    scanf("%d",&resposta);
    if(resposta==1){
        printf("\n");
        printf("Digite a posição que deseja cadastrar:");
        scanf("%d",&posicao);
        printf("Digite o nome do aluno:");
        scanf("%s",aux.dados[posicao].nome);
        printf("Digite o numero de matricula do aluno:");
        scanf("%d",&aux.dados[posicao].matricula);
        printf("Digite o valor d primeira nota do aluno:");
        scanf("%f",&aux.dados[posicao].nota[0]);
        printf("Digite o valor da segunda nota do aluno:");
        scanf("%f",&aux.dados[posicao].nota[1]);
        printf("Digite o valor da terceira nota do aluno:");
        scanf("%f",&aux.dados[posicao].nota[2]);
    }
    else{
        printf("\n");
        printf("Digite o nome do aluno:");
        scanf("%s",aux.dados[aux.qtd].nome);
        printf("Digite o numero de matricula do aluno:");
        scanf("%d",&aux.dados[aux.qtd].matricula);
        printf("Digite o valor da primeira nota do aluno:");
        scanf("%f",&aux.dados[aux.qtd].nota[0]);
        printf("Digite o valor da segunda nota do aluno:");
        scanf("%f",&aux.dados[aux.qtd].nota[1]);
        printf("Digite o valor da terceira nota do aluno:");
        scanf("%f",&aux.dados[aux.qtd].nota[2]);
        aux.qtd++;
    }
    if(posicao>aux.maior){
        aux.maior=posicao;
    }
    if(resposta==2){
        if(aux.qtd>aux.maior){
             aux.maior=aux.qtd;
        }
    }
    aux.total++;
    menu(&aux);
}

void remove_lista(Lista* li){
    int aux_matricula,i=0;
    char aux_nome[4];

    printf("Digite o número de matricula do aluno que deseja remover da lista:");
    scanf("%d",&aux_matricula);
    while(aux_matricula!=aux.dados[i].matricula){
        i++;
    }
    printf("Precione espaço seguido de enter para efetivar a remoção.\n");
    strcpy(aux.dados[i].nome," ");
    aux.dados[i].matricula=0;
    aux.dados[i].nota[0]=0;
    aux.dados[i].nota[1]=0;
    aux.dados[i].nota[2]=0;
    aux.maior=aux.maior-i;
    aux.total--;
    menu(&aux);
}
void imprime_lista(Lista* li){ 
    int i;  
    for(i=0;i<=aux.maior;i++){
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

void imprime_aluno(Lista* li){
    int i=0,busca;
    printf("Digite o número da matricula do aluno que deseja imprimir os dados:");
    scanf("%d",&busca);
    while(i<aux.qtd){
        if(busca==aux.dados[i].matricula){
            printf("Dados dos alunos\n");
            printf("NOME = %s\n",aux.dados[i].nome);
            printf("MATRICULA = %d\n",aux.dados[i].matricula);
            printf("1ª NOTA = %0.f\n",aux.dados[i].nota[0]);
            printf("2ª NOTA = %0.f\n",aux.dados[i].nota[1]);
            printf("3ª NOTA = %0.f\n",aux.dados[i].nota[2]);
            printf("\n");
        }
        else{
            i++;
        }
    }
}

int tamanho_lista(Lista* li){
    if(li==NULL){
        return -1;
    }   
    else{
        printf("Há o total de %d aluno(s) registrado(s)\n",aux.total);
    }
    menu(&aux);
}


void libera_lista(Lista* li){
    free(li);
}

void menu(Lista* li){
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
    printf("      (4)  para remover um aluno cadastrado (5) para imprimir os dados de aluno específico e Qualquer número diferente dos anteriores para fechar o programa.");
    printf("      |\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("------------->");
    scanf("%d",&resposta);
    fflush(stdin);

    if(resposta==1){
       insere_lista(&aux);
    }
    if(resposta==2){
        imprime_lista(&aux);
    }
    if(resposta==3){
        tamanho_lista(&aux);
    }
    if(resposta==4){
        remove_lista(&aux);
    }
    if(resposta==5){
        imprime_aluno(&aux);
    }
    if(resposta!=1||resposta!=2||resposta!=3||resposta!=4||resposta!=5){
        exit(0);    
    }
}