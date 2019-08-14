#include <stdio.h>

int main() {

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
    printf("%zu char\n", sizeof(unsigned char));
    printf("%zu short\n", sizeof(unsigned short));
    printf("%zu int\n", sizeof(unsigned));
    printf("%zu long\n", sizeof(unsigned long));
    printf("%zu long long\n", sizeof(unsigned long long));
}
