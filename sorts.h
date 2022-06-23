#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

unsigned int n;


float segundos[6];

void defineN();
void bubble();
void selection();
void inserction();

void defineN(const unsigned int x){
    n = x;
}

void bubble(){

	int *vetor, i, j, aux, k = n;  	//aux é a variável auxiliar para a troca de valores no vetor 
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));   
																		
	srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		vetor[i] = rand()%100;
		
   	
     tinicio = time(NULL);  	
    
	// Algoritmo Bubble Sort
	for (i=0;i<n;i++){
	   for (j=0;j<k-1;j++){
	   	    if (vetor[j] > vetor[j+1]){		// compara se um elemento é maior do que o subsequente, se for, realiza a troca
			 aux = vetor[j];
			 vetor[j]= vetor[j+1];
			 vetor[j+1] = aux;
		
		   }	
		}
		k--; 					// otimização do bubble sorte para a cada iteração reduzir em 1 o tamanho do vetor a ser ordenado. 
	}
	
	tfim = time(NULL);
    tempo = (tfim - tinicio);		
    
	// Fim												
	
	printf ("\n\n** Vetor ordenado ***\n\n{ ");
	
	for(i=0; i<n; i++)
       printf ("%d ", vetor[i]);
    
   	printf ("}\n\n");
	
	
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	free(vetor);

    segundos[0] += tempo;
}

void selection(){
    int *vetor, i, j, aux;				//aux é a variável auxiliar para a troca de valores no vetor
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
    
    srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		   vetor[i] = rand()%100;
   	
    tinicio = time(NULL);  	
     
    //Algoritmo Insertion Sort
	for (i = 1; i < n; i++) {
        aux = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = aux;
    }
																
	tfim = time(NULL);
    tempo = (tfim - tinicio);
             
	// Fim
	
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	
	free(vetor);
    segundos[1] = tempo;
}

void inserction(){
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



