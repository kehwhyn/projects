/* Autor: Kevin Boucinha Fiorentin
 * e-mail: kevinboucinha@gmail.com
 */

// Formas alternativas de declarar o main
//  int main(){/*...*/}
//  int main(void){/*...*/}
//  int main(int argc, char *argv[]){/*...*/}
//  int main(int argc, char **argv){/*...*/}

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define TAM 10
#define ROW	2
#define COL	2

/*...........................................................................*/
void commaOperatorTest(){

	bool aux = true;

	(aux) ? printf("\t1\n"), printf("\t3\n") : printf("2\n");
}

void testeShift(){

	printf("%08x - 1 << 10\n", 1 << 10);
	printf("%08x - 1 << 3\n", 1 << 3);
	printf("%08x - or\n", (1 << 10) | (1 << 3));
	printf("%08x - and\n", (1 << 10) & (1 << 3));
	printf("%08x - +\n", (1 << 10) + (1 << 3));
	printf("%08x - *\n", (1 << 10) * (1 << 3));
}

/*...........................................................................*/
void mainVetores();
//Valor dentro dos colchetes é opcional
//void vetorComoArgumento1(const int vetor[]);
void vetorComoArgumento1(const int vetor[TAM]);
void vetorComoArgumento2(const int *);
void vetorComoArgumento3(const int *);
void vetorComoArgumento4(const int *, const int);

/*...........................................................................*/
void mainMatrizes();
void matrizComoArgumento1(const int matrix[ROW][COL]);
void matrizComoArgumento2(const int matrix[][COL], const int);
void matrizComoArgumento3(const int *);
void matrizComoArgumento4(const int *, const int, const int);

/*...........................................................................*/
void mainCompare();
int compare(const void*, const void*);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main(int argc, char *argv[]){

    mainVetores();
    
    return 0;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*...........................................................................*/
void mainCompare(){

    char *nome1 = "Kevin", *nome2 = "Yasmin";

    printf("%d\n", compare(nome1, nome2));
}

int compare(const void *a, const void *b){

    const char *l = a;
    const char *r = b;
    
    return strcmp(l, r);
}


/*...........................................................................*/
void mainVetores(){

    int vetor[TAM];
    
    for(int i = 0; i < TAM; i++)
        vetor[i] = i*2;
        
    vetorComoArgumento1(vetor);
    vetorComoArgumento2(vetor);
    vetorComoArgumento3(vetor);
    vetorComoArgumento4(vetor, TAM);
}

void vetorComoArgumento1(const int vector[TAM]){
    for(int i = 0; i < TAM; i++)
	    printf("%d\n", vector[i]);
}

void vetorComoArgumento2(const int vector[TAM]){
    for(int i = 0; i < TAM; i++)
	    printf("%d\n", vector[i]);
}

void vetorComoArgumento3(const int *vector){
    for(int i = 0; i < TAM; i++)
	    printf("%d\n", vector[i]);
}

void vetorComoArgumento4(const int *vector, const int vecLength){
    for(int i = 0; i < vecLength; i++)
	    printf("%d\n", *(vector+i));
}

/*...........................................................................*/
void mainMatrizes(){

    int matrix[ROW][COL];
    
    for(int i = 0; i < ROW; i++)
	    for(int j = 0; j < COL; j++)
	      matrix[i][j] = (i+j)*2;
	      
	matrizComoArgumento1(matrix);
	matrizComoArgumento2(matrix, ROW);
	matrizComoArgumento3((int*)matrix);
	matrizComoArgumento4((int*)matrix, ROW, COL);
}

void matrizComoArgumento1(const int matrix[ROW][COL]){
    for(int i = 0; i < ROW; i++)
	    for(int j = 0; j < COL; j++)
	      printf("%d ", matrix[i][j]);
}

void matrizComoArgumento2(const int arr[][COL], const int row){ 
    for (int i = 0; i < row; i++) 
      for (int j = 0; j < COL; j++) 
        printf("%d ", arr[i][j]); 
} 

void matrizComoArgumento3(const int *matrix){
    for(int i = 0; i < ROW; i++)
	     for(int j = 0; j < COL; j++)
	        printf("%d ", *((matrix + i * COL) + j));
}

void matrizComoArgumento4(const int *matrix, const int row, const int col){
    for(int i = 0; i < row; i++)
	     for(int j = 0; j < col; j++)
	        printf("%d ", *((matrix + i * col) + j));
}
