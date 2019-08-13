#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {

    int dp = 0, ds = 0;

    for(int j = arr_columns-1, i = 0; j >= 0 && i < arr_rows; j--, i++)
        ds += arr[i][j];
	    dp += arr[i][i];

    return abs(dp - ds);
}

int main(void){


    
    return 0;
}
