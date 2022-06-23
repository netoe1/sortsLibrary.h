#include <stdio.h>
#include <stdlib.h>   // 
#include <time.h>
#define n 1000     // constante que define o tamanho do vetor

float segundos[6]; /*0- Bubble*/




void selection(){
    int *vetor, i, j, aux, min;		//aux é a variável auxiliar para a troca de valores no vetor, min é a variável que armazena o menor valor do vetor
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
    
    srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		vetor[i] = rand()%100;
		   
   	
   	
    tinicio = time(NULL);  	
    
    //Algoritmo Selection Sort
	for (i = 0; i < n-1; i++) 
  {
     min = i;
     for (j = (i+1); j < n; j++) {
       if(vetor[j] < vetor[min]) 
         min = j;
     }
     if (i != min) {
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;
     }
  }
																
	tfim = time(NULL);
    tempo = (tfim - tinicio);
            
	// Fim
	
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	free(vetor);

    segundos[2] = tempo;
}

void