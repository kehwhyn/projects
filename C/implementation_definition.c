/* Autor: Kevin Boucinha Fiorentin
 * email: kevinboucinha@gmail.com
 */

#include "prototype_declaration.h"
//implementam umas definições e macros que eu achei massa
#include <iso646.h>
#include <stdbool.h>
#include <regex.h>

#include <time.h>
//time()
#include <stdio.h>
//printf(), scanf()
#include <string.h>
//strcmp()
#include <stdlib.h>
//srand(), rand(), calloc(), free(), abs()

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

void matrizCriada(){

    int **matrix = calloc(ROW, sizeof(int*));

    srand(time(NULL));

    for (int i = 0; i < ROW; i++)
            matrix[i] = calloc(COL, sizeof(int*));

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            matrix[i][j] = rand()%100 + 1;
    
    //must return 15
    printf("%d\n", diagonalDifference(ROW, COL, matrix));
    
    for (int i = 0; i < ROW; i++)
        free(matrix[i]);
    free(matrix);
}

int diagonalDifference(int const arr_rows, int const arr_columns, int const **arr){
    int dp = 0, ds = 0;

    for(int i = 0, j = arr_columns - 1; i < arr_rows; i++, j--){
        dp += arr[i][i];
        ds += *(*(arr + i) + j);
    }

    return abs(dp - ds);
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
void commaOperatorTest(void){

	bool aux = true;

	(aux) ? printf("\t1\n"), printf("\t3\n") : printf("2\n");
}

void testeShift(void){

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

void testeRegex(void){

    regex_t reg;

    regcomp(&reg, "[A-F;a-f;0-9]",REG_EXTENDED|REG_NOSUB);
    if(!regexec(&reg, "ZKevin", 0, (regmatch_t*)NULL,0))
        printf("Okay\n");
    else
        printf("Erro\n");
}

void tamanhos(void){

    printf("SIGNED\n");
    printf("%zu char\n", sizeof(char));
    printf("%zu short\n", sizeof(short));
    printf("%zu int\n", sizeof(int));
    printf("%zu long\n", sizeof(long));
    printf("%zu long long\n", sizeof(long long));
    printf("%zu float\n", sizeof(float));
    printf("%zu double\n", sizeof(double));
    printf("%zu long double\n", sizeof(long double));
    printf("UNSIGNED\n");
    printf("%zu pointer size\n", sizeof(int*));
    printf("%zu char\n", sizeof(unsigned char));
    printf("%zu short\n", sizeof(unsigned short));
    printf("%zu int\n", sizeof(unsigned));
    printf("%zu long\n", sizeof(unsigned long));
    printf("%zu long long\n", sizeof(unsigned long long));
}
#endif

