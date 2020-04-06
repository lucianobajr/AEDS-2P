#include"heap.h"

int heap_sort(int *vetor, int tamanho){
   
   int pai_direita, pai_esquerda, aux, contador;

   
   for(contador = tamanho-1;  contador >= 0;  contador-- ){
      
      //descobrindo o a raiz de cada galho
      pai_direita  = (contador / 2) - 1;
      pai_esquerda = (contador - 2) / 2;
      
      //trocando caso a raiz seja manor que o galho da direita
       if(vetor[contador] > vetor[pai_direita]){
         
         aux = vetor[contador];
         vetor[contador] = vetor[pai_direita];
         vetor[pai_direita] = aux;         
         
      }
      
      //trocando caso a raiz seja menor que o galhp da esquerda
      else if (vetor[contador-1] > vetor[pai_esquerda] ){

         aux = vetor[contador-1];
         vetor[contador-1] = vetor[pai_esquerda];
         vetor[pai_esquerda] = aux;
         
      }

   }
}