#include "heap.h"

int main(){
   int tamanho_vetor, *vetor,contador,contador2=0,maior,cont,sair=0,menu1;
   int aux;
   
   while(sair==0){
      printf("\n\t\t--------------------------------------\n");
      printf("\n\t\t\tORDENACAO USANDO HEAP SORT\n\n\t\t\t1-GERAR NOVO VETOR\n\t\t\t2-SAIR\n\t\t\t>>>>>");
      printf("\n\t\t--------------------------------------\n");
      scanf("%d",&menu1);
      system("cls");
      
      switch(menu1){
         
         case 1:
            printf("\nINSIRA O TAMANHO DO VETOR:\n");
            scanf("%d",&tamanho_vetor);
            
            vetor = malloc(sizeof(int)* (tamanho_vetor)); 
            srand(time(NULL));
         
            //gerando vetores aleatorios
            for(contador = 0; contador < tamanho_vetor; contador++){
               vetor[contador]= rand()%100;   
            }
            
            //exibindo desordenado
            for(contador2=0; contador2 < tamanho_vetor; contador2++){
               printf("numero %d: %d\n",contador2,vetor[contador2]);
            }
            
            printf("\n\n--------------------------------------\n\n");
            
            clock_t hora_inicial = clock();
            heap_sort(vetor, tamanho_vetor);
                        
            cont = tamanho_vetor-1;
                              
            while(cont >= 0 ){
               //mandando o maior para o começo
               heap_sort(vetor, cont);
               //mandando maior para o final
               for(contador = 0; contador < cont; contador++){
                  
                  aux = vetor[contador];
                  vetor[contador] = vetor[contador+1];
                  vetor[contador+1] = aux;
                                 
               }
               
               heap_sort(vetor, cont);   
               cont--;
            }
            clock_t hora_final = clock();
            
            //exibindo organizado            
            for(contador2 = 0; contador2 < tamanho_vetor; contador2++){
               printf("numero %d: %d\n",contador2, vetor[contador2]);
               
            }
            double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
               printf("TEMPO GASTO USANDO HEAP SORT: %lf s\n", tempo_gasto);
            
            system("pause");
            system("cls");
         break;
         
         case 2:
            printf("\nATE LOGO...");
            sair=1;
            
         break;
            
      }
   }
}