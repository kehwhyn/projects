#include <stdio.h>
#include <stdlib.h>

int main(void){

    int const row = 3, col = 3;
    int **matrix = calloc(row, sizeof(int*));

    printf("%zu\n%zu\n%zu\n", sizeof(int**),sizeof(int*),sizeof(int));
    return 0;
}
