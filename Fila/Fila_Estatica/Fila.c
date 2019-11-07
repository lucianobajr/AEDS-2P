#include "FilaEstatica.c"

int main(){
    /*            Fila-FIFO(First in First out)
    -É um tipo especial de "lista":
        -inserção e exclusão ocorrem nas extremidades da "lista"
    -Podemos fazer as seguintes operações dependendo do tipo de alocação de memória:
        -Inserção de um elemento no "final"
        -Remoção de um elemento no "inicio"
        -Acesso ao elemento do "inicio"
    -Alocação Estática:
        -Exige a definição do máximo de elementos
        -Acesso sequencial:elementos consecutivos de memória 
    -Alocação Dinâmica:    
        -Acesso encadeado logo para acessar um elemento devemos percorrer todos os anteriores
    */ 
    Fila *fi;
    fi = cria_Fila();
    menu(fi);
}