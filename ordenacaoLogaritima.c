#include <stdio.h>
#include <stdlib.h>
#include "ordenacaoLogaritima.h"
#include "user_io.h"
#include <time.h>

////////////////////////////////////////////////////////////////////////////////
//Merge Sort
void merge(int vetor[], int inicio, int meio, int fim){
    int v1, v2, tam, tamAux, i, j;
    tam = (fim - inicio) + 1;
    int vAux[tam];
    
    v1 = inicio;
    v2 = meio + 1;
    tamAux = 0;
    
    while((v1 <= meio) && (v2 <= fim)){
        if(vetor[v1] < vetor[v2]){
            vAux[tamAux] = vetor[v1];
            v1++;
        } else {
            vAux[tamAux] = vetor[v2];
            v2++;
        }
        
        tamAux++;
    }
    
        while(v2 <= fim){
            vAux[tamAux] = vetor[v2];
            v2++;
            tamAux++;
        }
 
        while(v1 <= meio){
            vAux[tamAux] = vetor[v1];
            v1++;
            tamAux++;
        }
    
    j = 0;
    
    for(i = inicio; i <= fim; i++){
 
        vetor[i] = vAux[j];
        j++;
    }
    
}

void mergeSortT(int vetor[], int inicio, int fim){
    clock_t tempo;
    double final;
    
    tempo = clock();
    mergeSort(vetor,inicio,fim);
    
    tempo = clock() - tempo;
    final = (double)tempo/(double)CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %.100lf\n", final);
}

void mergeSort(int vetor[], int inicio, int fim){
    int meio; 
    int aux;
    
    meio = ((inicio + fim))/2;
    
    if( inicio < fim){

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
////////////////////////////////////////////////////////////////////////////////
//Quick Sort

int particiona(int vetor[], int inicio, int fim){
    int pivo, pos, i, aux;
    
    pivo = vetor[inicio];
    pos = inicio;
    
    for(i = inicio + 1; i <= fim; i++){
        if(vetor[i] < pivo){
            pos++;
            
            if(i != pos){
                aux = vetor[i];
                vetor[i] = vetor[pos];
                vetor[pos] = aux;
            }
        }
    }
    
    aux = vetor[inicio];
    vetor[inicio] = vetor[pos];
    vetor[pos] = aux;
    
    return pos;
}


void quickSort(int vetor[], int inicio, int fim){
    int pivo;
    
    if(inicio < fim){
        pivo = particiona(vetor, inicio, fim);
        
        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo +1, fim);
    }
}
