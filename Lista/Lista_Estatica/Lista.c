#include "ListaEstatica.c"

int main(){
    /*                          LISTA
    -Sequencia  de 0 ou mais elementos x1,x2,x3,...,xn.Em que xi é tipo do elemento e n é quantidade 
    de termos da lista
    -Alocação Estática(vetor-array):
        -O espaço de memória é alocado no momento da compilação
        -Delimitação de elementos da 'lista'
        -Acesso Sequencial:elementos consecutivos de memória
        -Quando usar:
            -Listas pequenas 
            -Inserção/Remoção apenas no final da lista
            -Tamanho máximo bem definido 
            -A busca é a operação mais frequente
    -Alocação Dinâmica: 
        -O espaço de memória é alocado em tempo de execução
        -Acesso encadeado:Os elementos podem estar em áreas distintas de memória.Para acessar um 
        elemento, é preciso percorrer todos os seus antecessores na 'Lista'
    */
    Lista* li;
    li=cria_lista();
    menu(li);
}
 