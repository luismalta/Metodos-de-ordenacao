#include <stdio.h>
#include <stdlib.h>
#include "ordenacaoQuadratica.h"
#include <time.h>

int contComp, contMov;



int acharMenor(int vetor[], int inicio, int tam){
    int menor, indiceMenor,i;
    
    
    indiceMenor = inicio;
    menor = vetor[inicio];
    for(i = inicio; i < tam; i++){
        if(vetor[i] < vetor[indiceMenor]){
            menor = vetor[i];
            indiceMenor = i;
        }
    }
    
    return indiceMenor;
}

void selecao(int vetor[], int tam){
    int i, marcador, indice, aux, inicio;
    
    clock_t tempo;
    double final;
    
    tempo = clock();
    
    marcador = 0;
    contComp = 0;
    contMov = 0;
    
    
    for(i = 0; i < tam -1; i++){
        indice = acharMenor(vetor, marcador + 1,tam);
        contComp++;
        if(vetor[marcador] > vetor[indice]){
            contMov++;
            aux = vetor[marcador];
            vetor[marcador] = vetor[indice];
            vetor[indice] = aux;
        }
        
        marcador++;
        
    } 
    
    tempo = clock() - tempo;
    final = (double)tempo/(double)CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %.30lf\n", final);
    printf("Numeros de comparações: %d\n", contComp);
    printf("Numeros de movimentações: %d\n\n", contMov);
}

void bolhaNormal(int vetor[], int tam){
    int i, j, aux;
    
    clock_t tempo;
    double final;
    
    contComp = 0;
    contMov = 0;
    
    tempo = clock();
    
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            contComp++;
            if(vetor[j] > vetor[j+1]){
                contMov++;
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    
    tempo = clock() - tempo;
    final = (double)tempo/(double)CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %.30lf\n", final);
    printf("Numeros de comparações: %d\n", contComp);
    printf("Numeros de movimentações: %d\n\n", contMov);
    
}

void bolhaOtimizada(int vetor[], int tam){
    int i, j, aux, passou;
    
    contComp = 0;
    contMov = 0;
    
    
    clock_t tempo;
    double final;
    
    tempo = clock();
    
    passou = 0;
    
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            contComp++;
            if(vetor[j] > vetor[j+1]){
                contMov++;
                passou = 1;
                
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
        if(passou == 0){
            break;
        }
        
        passou = 0;
    }
    
    tempo = clock() - tempo;
    final = (double)tempo/(double)CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %.30lf\n", final);
    printf("Numeros de comparações: %d\n", contComp);
    printf("Numeros de movimentações: %d\n\n", contMov);
}


void insercao(int vetor[], int tam){
    int marcador, pos, aux;
    
    contComp = 0;
    contMov = 0;
    
    clock_t tempo;
    double final;
    
    tempo = clock();
    
    for(marcador = 1; marcador < tam; marcador++ ){
        pos = marcador - 1;
        aux = vetor[marcador];
        contComp++;
        while((pos >= 0) && (aux < vetor[pos])){
            contMov++;
            vetor[pos+1] = vetor[pos];
            pos--;
        }
        vetor[pos + 1] = aux;
    }
    
    tempo = clock() - tempo;
    final = (double)tempo/(double)CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %.50lf\n", final);
    printf("Numeros de comparações: %d\n", contComp);
    printf("Numeros de movimentações: %d\n\n", contMov);
    
}

void shellSort(int vetor[], int tam){
    int i, j, value;
    int h;
    
    contComp = 0;
    contMov = 0;
    
    clock_t tempo;
    double final;
    
    tempo = clock();
    
    h = 1;
    
    while(h < tam){
        h = 3 * h + 1;
    }
    
    while(h > 1){
        h /= 3;
        for(i = h; i < tam; i++){
            value = vetor[i];
            j = i - h;
            
            while(j >= 0 && value < vetor[j]){
                vetor[j + h] = vetor[j];
                j -=h;
            }
            vetor[j + h] = value;
        }
    }
    
    tempo = clock() - tempo;
    final = (double)tempo/(double)CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %.100lf\n", final);
    printf("Numeros de comparações: %d\n", contComp);
    printf("Numeros de movimentações: %d\n\n", contMov);
}


void shellSortN(int vet[], int tam)
{
    int marca,posAtual,espAux;
    int j=0,i,aux;
    
    
    contComp = 0;
    contMov = 0;
    
    clock_t tempo;
    double final;
    
    tempo = clock();
    
    int vetEspKnu[20] = {1743392200,581130733,193710244,64570081,21523360,7174453,2391484,797161,265720,88573,29524,9841,3280,1093,364,121,40,13,4,1};
    //Vetor feito com os termos da serie de Knuth 
				    
    for(j=0;j<20;j++)				//Varia os termos da série de forma decrementativa
    {
    	if(vetEspKnu[j]<tam)		//Acha o 1º termo da série menor que o tamanho do vetor	chamado de "Espaço"
    	{
    		
			espAux = vetEspKnu[j];	//Inicia com o esse "Espaço"
			
			
		    for(marca = espAux ; marca < tam; marca++)		//Faz o insertion normal, mas onde incrementava ou decrementava "1", 
		    {												//Agora incrementa ou decrementa "Espaço"
		        
		        aux = vet[marca];
		        posAtual = marca - espAux;
		        
		        
		            while(posAtual >= 0  && aux<vet[posAtual])
		            {
		            	
		                vet[posAtual+espAux] = vet[posAtual];
		                posAtual-=espAux;
		                
		            }
		
		        vet[posAtual+espAux] = aux;
		    }
		}
	}
    
    
    tempo = clock() - tempo;
    final = (double)tempo/(double)CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %.100lf\n", final);
    printf("Numeros de comparações: %d\n", contComp);
    printf("Numeros de movimentações: %d\n\n", contMov);
}