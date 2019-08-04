/* Autor: Kevin Boucinha Fiorentin
 * email: kevinboucinha@gmail.com
 */

// Formas alternativas de declarar o main
//  int main(){/*...*/}
//  int main(void){/*...*/}
//  int main(int argc, char *argv[]){/*...*/}
//  int main(int argc, char **argv){/*...*/}

#if 0
    // alterar para 1 pra ver o que é
    
    /* flumuxiation

    silly();
    if(foo)
    bar();
    /* baz is a flumuxiation */
    baz = fib+3;
    
    */

#endif

#include"prototype.h"

#if VECTORS
int main(int argc, char *argv[]){

    int vetor[TAM], row = 2, col = 5;

    for(int i = 0; i < TAM; i++)
        vetor[i] = i*2;

    vetorComoArgumento1(vetor);
    vetorComoArgumento2(vetor);
    vetorComoArgumento3(vetor);
    vetorComoArgumento4(vetor, TAM);
    exibindoVetorComoMatriz(vetor, row, col);
}
#endif

#if MATRIXES
int main(int argc, char *argv[]){

    int matrix[ROW][COL];

    for(int i = 0; i < ROW; i++)
	    for(int j = 0; j < COL; j++)
	        matrix[i][j] = (i+j)*2;
	
	matrizComoArgumento1(matrix);
	matrizComoArgumento2(matrix, ROW);
	matrizComoArgumento3((int*)matrix);
	matrizComoArgumento4((int*)matrix, ROW, COL);

}
#endif

#if SLA
int main(int argc, char *argv[]){

    printf("%d\n", compare("Kevin", "Micaelle"));
}
#endif

#if CURIOSIDADES
int main(int argc, char *argv[]){

    commaOperatorTest();
    testeShift();
}
#endif
