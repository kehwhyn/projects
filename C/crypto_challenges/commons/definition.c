#include "declaration.h"

#include <stdio.h>
//printf(), scanf(), sprintf(), sscanf()
#include <regex.h>
//
#include <string.h>
//strlen(), strchr()
#include <stdlib.h>
//calloc()
#include <stdbool.h>
//bool, true, false
#include <ctype.h>
//isxdigit()

char const BASE64_VALUES[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

bool valid(char const *string){
    if(!string || !strlen(string)) return false;
    else return true;
}

bool isHex(char const *string){
    if(!valid(string) || (strlen(string) % 2 != 0)) return false;

    for(int i = 0; i <= strlen(string); i++)
        if(not isxdigit(string[i])) return false;

    return true;
}

bool isBase64(char const* string){
    if(!valid(string) || (strlen(string) % 4 != 0)) return false;

    for(int i = 0; i < strlen(string); i++)
        if(!strchr(BASE64_VALUES, string[i])) return false;

    return true;
}

// 2 hex digits == 1 ascii character
char *hexDecoder(char const *string){

    if(!isHex(string)) return NULL;

    int const SIZE = strlen(string)/2;
    char *decoded = calloc(SIZE + 1, sizeof(char));
    if(!decoded) return decoded;

    for(int i = 0; i < SIZE; i++)
        sscanf(string + (2 * i), "%2hhx", &decoded[i]);

    decoded[SIZE + 1] = '\0';
    return decoded;
}

char *hexEncoder(char const *string){

    if(!valid(string)) return NULL;

    int const SIZE = strlen(string) * 2;
    char *encoded = calloc(SIZE + 1, sizeof(char));
    if(!encoded) return encoded;

    for(int i = 0; i < SIZE/2; i++)
        sprintf(encoded + (2 * i), "%02x", string[i]);

    encoded[SIZE + 1] = '\0';
    return encoded;
}

// 4 values in b64 == 3 values in ascii
char *b64Encoder(char const *string){

    if(!valid(string)) return NULL;

    int const SIZE = strlen(string) * 4 / 3;
    char *encoded = calloc(SIZE + 1, sizeof(char));
    if(!encoded) return encoded;

    int iter = 0;
    for(int i = 0; i < strlen(string); i+=3){
        int concat = (string[i] << 16) | (string[i+1] << 8) | string[i+2];
        int index1 = (concat & 0xFC0000) >> 18;
        int index2 = (concat & 0x03F000) >> 12;
        int index3 = (concat & 0x000FC0) >> 6;
        int index4 = (concat & 0x00003F);

        strncpy(encoded + iter++, &BASE64_VALUES[index1], sizeof(char));
        strncpy(encoded + iter++, &BASE64_VALUES[index2], sizeof(char));
        strncpy(encoded + iter++, &BASE64_VALUES[index3], sizeof(char));
        strncpy(encoded + iter++, &BASE64_VALUES[index4], sizeof(char));
    }

    int const PADDING = strlen(string) % 3;
    if(PADDING == 1)
        strncpy(encoded + iter - 2, "==", sizeof(char)*3);
    else if(PADDING == 2)
        strncpy(encoded + iter - 1, "=", sizeof(char)*2);

    encoded[SIZE + 1] = '\0';
    return encoded;
}
