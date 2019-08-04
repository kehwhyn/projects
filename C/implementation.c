/* Autor: Kevin Boucinha Fiorentin
 * email: kevinboucinha@gmail.com
 */

#include"prototype.h"

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#if VECTORS
void vetorComoArgumento1(const int vector[TAM]){
    for(int i = 0; i < TAM; i++)
	    printf("%d ", vector[i]);
	printf("\n");
}

void vetorComoArgumento2(const int vector[TAM]){
    for(int i = 0; i < TAM; i++)
	    printf("%d ", vector[i]);
	printf("\n");
}

void vetorComoArgumento3(const int *vector){
    for(int i = 0; i < TAM; i++)
	    printf("%d ", vector[i]);
	printf("\n");
}

void vetorComoArgumento4(const int *vector, const int vecLength){
    for(int i = 0; i < vecLength; i++)
	    printf("%d ", *(vector+i));
	printf("\n");
}

void exibindoVetorComoMatriz(const int *vector, const int row, const int col){
    for(int i = 0; i < row; i++){
	     for(int j = 0; j < col; j++)
	        printf("%d ", *((vector + i * col) + j));
	     printf("\n");
	}
}
#endif

#if MATRIXES
void matrizComoArgumento1(const int matrix[ROW][COL]){
    for(int i = 0; i < ROW; i++){
	    for(int j = 0; j < COL; j++)
	        printf("%d ", matrix[i][j]);
	    printf("\n");
	}
}

void matrizComoArgumento2(const int arr[][COL], const int row){
    for (int i = 0; i < row; i++){ 
        for (int j = 0; j < COL; j++) 
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void matrizComoArgumento3(const int *matrix){
    for(int i = 0; i < ROW; i++){
	    for(int j = 0; j < COL; j++)
	        printf("%d ", *((matrix + i * COL) + j));
	    printf("\n");
	}
}

void matrizComoArgumento4(const int *matrix, const int row, const int col){
    for(int i = 0; i < row; i++){
	     for(int j = 0; j < col; j++)
	        printf("%d ", *((matrix + i * col) + j));
	     printf("\n");
    }
}
#endif

#if SLA
int strCmp(const void *a, const void *b){

    const char *l = a;
    const char *r = b;

    return strcmp(l, r);
}
#endif

#if CURIOSIDADES
void commaOperatorTest(){

	bool aux = true;

	(aux) ? printf("\t1\n"), printf("\t3\n") : printf("2\n");
}

void testeShift(){

	printf("%08x - 1 << 10\n", 1 << 10);
	printf("%08x - 1 << 3\n", 1 << 3);
	printf("%08x -   |\n", (1 << 10) | (1 << 3));
	printf("%08x -   &\n", (1 << 10) & (1 << 3));
	printf("%08x -   +\n", (1 << 10) + (1 << 3));
	printf("%08x -   *\n", (1 << 10) * (1 << 3));
    printf("%08x -   ^\n", (1 << 10) ^ (1 << 3));
    //printf("%08x -   %\n", (1 << 10) % 10);
    printf("%08x -   /\n", (1 << 10) / 10);
}
#endif

