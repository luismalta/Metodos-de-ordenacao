/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Luis Malta
 *
 * Created on 10 de Março de 2017, 17:37
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenacaoQuadratica.h"
#include "ordenacaoLogaritima.h"
#include "user_io.h"
#include <time.h>

void menu(int vetor[], int tam){
    int opcao;
    
    while(opcao){
        opcao = 1;
        printf("\n---------------MENU------------------\n");
        printf("\nEscolha um metodo de ordenação:\n");
        printf("1) Imprimir vetor.\n");
        printf("2) Bubble Sort\n");
        printf("3) Bubble Sort Otimizado\n");
        printf("4) Selection Sort\n");
        printf("5) Insertion Sort\n");
        printf("6) Merge Sort\n");
        printf("7) Quick Sort\n");
        printf("8) Shell Sort\n");
        printf("9) Nicolas Shell Sort\n");
        printf("0) Sair\n\n");

        scanf("%d", &opcao);
        
        switch(opcao){
        case 1:
            imprimir(vetor, tam);
            break;
        case 2:
            bolhaNormal(vetor, tam);
            break;
        case 3:
            bolhaOtimizada(vetor, tam);
            break;
        case 4:
            selecao(vetor, tam);
            break;
        case 5:
            insercao(vetor, tam);
            break;
        case 6:
            mergeSortT(vetor, 0, tam - 1);
            break;
        case 7:
            quickSort(vetor, 0, tam -1);
            break;
        case 8:
            shellSort(vetor, tam);
            break;
        case 9:
            shellSortN(vetor, tam);
            break;
            
        case 10:
            gerarArquivo();
            tam = abrirArquivo(vetor);
            break;
        case 11:
            tam = abrirArquivo(vetor);
            break;
        case 0:
            opcao = 0;
            break;
        default:
            printf("Escolha uma opção valida.\n");
        }
    }
    
    
}

int main(int argc, char** argv) {
    int vetor[100000];
    int tam,i;
    
    //gerarArquivo();
    tam = abrirArquivo(vetor);
    menu(vetor, tam);

    return (EXIT_SUCCESS);}

