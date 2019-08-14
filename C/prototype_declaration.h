/* Autor: Kevin Boucinha Fiorentin
 * email: kevinboucinha@gmail.com
 *
 * Neste arquivo devem permanecer só 
 * os protótipos das funções, macros
 * e estruturas de dados.
 */

#ifndef FUNCOES_H_
#define FUNCOES_H_
#endif

// macros para comentar blocos de código
#define VECTORS 0
#define MATRIXES 0
#define SLA 0
#define CURIOSIDADES 0

#if VECTORS

#define TAM 10

//Valor dentro dos colchetes é opcional
//void vetorComoArgumento1(const int vetor[]);
void vetorComoArgumento1(const int vetor[TAM]);
void vetorComoArgumento2(const int *);
void vetorComoArgumento3(const int *);
void vetorComoArgumento4(const int *, const int);
//Dá pra usar macros também
//void exibindoVetorComoMatriz(const int *);
void exibindoVetorComoMatriz(const int *, const int, const int);
#endif

#if MATRIXES

#define ROW 3
#define COL 3

void matrizComoArgumento1(const int matrix[ROW][COL]);
void matrizComoArgumento2(const int matrix[][COL], const int);
void matrizComoArgumento3(const int *);
void matrizComoArgumento4(const int *, const int, const int);
int diagonalDifference(int const arr_rows, int const arr_columns, int const **arr);
void diferencaDiagonal();
#endif

#if SLA
int strCmp(const void*, const void*);

#endif

#if CURIOSIDADES
void commaOperatorTest(void);
void testeShift(void);
void testeRegex(void);
void tamanhos(void);
#endif
