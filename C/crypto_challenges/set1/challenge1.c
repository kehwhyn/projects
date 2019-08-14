#include ""
#include<stdio.h>
char const INPUT[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
char const SOLUTION[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

int main(int argc, char **argv){

    char const *solution1 = b64Encoder(hexDecoder(INPUT));
    if(!strcmp(SOLUTION,b64Encoder(hexDecoder(INPUT))
        printf("Passastes!");
    else
        printf("Errastes!");
    
    return 0;
}
