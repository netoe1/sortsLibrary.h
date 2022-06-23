#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

unsigned int n;


float segundos[6];

void defineN();
void start_bubble();
void start_selection();
void start_inserction();
void start_merge();
void start_quick();
void start_heap();

void merge(int vetor[], int comeco, int meio, int fim);
void mergeSort(int vetor[], int comeco, int fim);
void quickSort(int b[],int i, int s);
void heapsort(int vetor[], int tam);

void defineN(const unsigned int x){
    n = x;
}

void start_bubble(){

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

void start_selection(){
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

void start_inserction(){
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

void merge(int vetor[], int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void start_merge(){
    int *vetor, i;  
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
																		
	srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
	  vetor[i] = rand()%100;
		   
    tinicio = time(NULL);  	
    
    mergeSort(vetor,0,n);
	tfim = time(NULL);
	
    tempo = (tfim - tinicio);		
    
	// Fim										
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	free(vetor);
    segundos[3] = tempo;
}

void quickSort(int b[],int i, int s)
{
   int e=i, d=s;
   int item = b[ ((e+d)/2) ];
   while ( e <= d )
   {
     while ( b[e] < item ) { e++; }
     while ( b[d] > item ) { d--; }
     if ( e <= d )
     {
       int aux; // Variavel auxiliar para as trocas
       aux      = b[e];
       b[e] = b[d];
       b[d] = aux;
       d--;
       e++;
     }
   }
   if ( d-i > 0 ) quickSort(b,i,d);
   if ( s-e > 0 ) quickSort(b,e,s);
 }

void start_quick(){
    int *vetor, i;  	
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
																		
	srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		   vetor[i] = rand()%100;
		   
	printf ("** Vetor original ***\n\n{ ");
	
	for(i=0; i<n; i++)
       printf ("%d  ", vetor[i]);
    
   	printf ("}\n\n");
   	
    tinicio = time(NULL);  	
    
    quickSort(vetor, 0, n);
    
	tfim = time(NULL);
    tempo = (tfim - tinicio);		
    
	// Fim												
	
	printf ("\n\n** Vetor ordenado ***\n\n{ ");
	
	for(i=0; i<n; i++)
       printf ("%d ", vetor[i]);
    
   	printf ("}\n\n");
	
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	free(vetor);

    segundos[4] = tempo;
}

void heapsort(int vetor[], int tam){
       int i = tam / 2, pai, filho, t;
   while(tam>0) {
      if (i > 0) {
          i--;
          t = vetor[i];
      } else {
          tam--;
          if (tam <= 0) return;
          t = vetor[tam];
          vetor[tam] = vetor[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < tam) {
          if ((filho + 1 < tam)  &&  (vetor[filho + 1] > vetor[filho]))
              filho++;
          if (vetor[filho] > t) {
             vetor[pai] = vetor[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      vetor[pai] = t;
   }

}

void start_heap(){
    int *vetor, i;  	
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
																		
	srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		   vetor[i] = rand()%100;
		   
	/*printf ("** Vetor original ***\n\n{ ");
	
	for(i=0; i<n; i++)
       printf ("%d  ", vetor[i]);
    
   	printf ("}\n\n");
   	*/
    tinicio = time(NULL);  	
    
    heapsort(vetor, n);
    
	tfim = time(NULL);
    tempo = (tfim - tinicio);		
    
	// Fim												
	
	/*printf ("\n\n** Vetor ordenado ***\n\n{ ");
	
	for(i=0; i<n; i++)
       printf ("%d ", vetor[i]);
    
   	printf ("}\n\n");
	*/
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	free(vetor);

    segundos[5] = tempo;
}