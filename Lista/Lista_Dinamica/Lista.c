#include "ListaEncadeada.c"

int main(){
    /*              LISTA ENCADEADA

    -Cada elemento aponta para o seu sucessor na 'lista'.Usa-se um ponteiro especial para o
    primeiro elemento da lista e uma indicação de final de lista.
    -Cada elemento é tratado como um ponteiro que é alocado dinamicamente,a medida que os dados 
    são inseridos
    -Para guardar o primeiro elemento usamos um "ponteiro para ponteiro"
               
    */

   Lista* li;
   li=inicia_lista();
   menu(li);
}
