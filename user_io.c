/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "user_io.h"
#include <time.h>

int abrirArquivo(int vetor[]){
    FILE *arqEnt;
    char *nomeArq;
    int i, entrada;
    
    nomeArq = (char*) calloc (20, sizeof(char));
    
    i= 0;
    
    printf("Entre com o nome do arquivo:\n");
    scanf("%s", nomeArq);
    
    arqEnt = fopen(nomeArq, "r");
    
    if(!arqEnt){
        printf("Arquivo nao encontrado.\n");
        exit(0);
    }

    while(!feof(arqEnt)){
        fscanf(arqEnt, "%d", &entrada);
        vetor[i] = entrada;
        i++;
        
    }
    return i;
}


void imprimir(int vetor[], int tam){
    int i;
    
    
    printf("Vetor: [ ");
    for(i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("]\n");
    
}

void gerarArquivo(void){
    FILE *arqEnt;
    char *nomeArq;
    int i, entrada, quantidade, range;
    
    nomeArq = (char*) calloc (20, sizeof(char));
    
    
    printf("Entre com o nome do arquivo a ser gerado:\n");
    scanf("%s", nomeArq);
    
    arqEnt = fopen(nomeArq, "w");
    
    printf("Entre com a quantidade de numeros a ser gerado: \n");
    scanf("%d", &quantidade);
    
    printf("Entre com o rage maximo: \n");
    scanf("%d", &range);
    
    srand(time(NULL));
    
    for(i = 0; i < quantidade; i++){
        entrada = rand()%range;
        
        fprintf(arqEnt, "%d ", entrada);
    }
    
    fclose(arqEnt);
    
    
    
}