#include "../../include/declaration.h"

#include <stdio.h>
//printf(), scanf(), sprintf(), sscanf()
#include <string.h>
//strlen(), strchr()
#include <stdlib.h>
//calloc()
#include <ctype.h>
//isxdigit()

char const BASE64_VALUES[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

bool valid(char const *string){
    if(!string || !strlen(string)) return false;
    else return true;
}

bool isHex(char const *string){
    if(!valid(string) || strlen(string) % 2) return false;
    
    for(int i = 0; i < strlen(string); i++)
        if(!isxdigit(string[i])) return false;

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
    if(!isHex(string)) return NULL; //aqui jaz o probs
    
    int const SIZE = strlen(string) / 2 + 1;
    char *decoded = calloc(SIZE, sizeof(char));
    if(!decoded) return decoded;

    for(int i = 0; i < SIZE; i++)
        sscanf(string + (2 * i), "%2hhx", &decoded[i]);

    decoded[SIZE] = '\0';
    return decoded;
}

char *hexEncoder(char const *string){
    if(!valid(string)) return NULL;

    int const SIZE = strlen(string) * 2 + 1;
    char *encoded = calloc(SIZE, sizeof(char));
    if(!encoded) return encoded;

    for(int i = 0; i < SIZE/2; i++)
        sprintf(encoded + (2 * i), "%02x", string[i]);

    encoded[SIZE] = '\0';
    return encoded;
}

// 4 values in b64 == 3 values in ascii
char *b64Encoder(char const *string){
    if(!valid(string)) return NULL;

    int const SIZE = strlen(string) * 4 / 3 + 1;
    char *encoded = calloc(SIZE, sizeof(char));
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
    encoded[SIZE] = '\0';
    return encoded;
}

char *Base64Decoder(char const *string){
    
    if(!isBase64(string)) return NULL;

    // For every 4 base64 characters, we need 3 bytes to store it.
    int const SIZE = strlen(string) / 3 * 4 + 1;

    char *result = calloc(SIZE, sizeof(char));
    if(!result) return result;

    int numWrote = 0;
    for(int i = 0; i < SIZE; i += 4){

        // Divide the chunk into 4 6 bit blocks based on the encoding values.
        char const *currentChunk = string + i;
        int block1 = strchr(BASE64_VALUES, currentChunk[0]) - BASE64_VALUES;
        int block2 = strchr(BASE64_VALUES, currentChunk[1]) - BASE64_VALUES;
        int block3 = 0;
        int block4 = 0;
        if(currentChunk[2] == '='){
            block2 = block2 & 0xFC;
            block3 = 0x00;
            block4 = 0x00;
        } else if(currentChunk[2] == '='){
            block3 = block3 & 0xF3;
            block4 = 0x00;
        } else {
            block3 = strchr(BASE64_VALUES, currentChunk[2]) - BASE64_VALUES;
            block4 = strchr(BASE64_VALUES, currentChunk[3]) - BASE64_VALUES;
        }

        char char1 = (block1 << 2) | (block2 >> 4);  // byte1 consists of block1 [5, 4, 3, 2, 1, 0] and block2 [5, 4]
        char char2 = (block2 << 4) | (block3 >> 2);  // byte2 consists of block2 [3, 2, 1, 0] and block3 [5, 4, 3, 2]
        char char3 = (block3 << 6) | (block4 >> 0);  // byte3 consists of block3 [1, 0] and block4 [5, 4, 3, 2, 1, 0]

        // Write the bytes to the result.
        result[numWrote++] = char1;
        result[numWrote++] = char2;
        result[numWrote++] = char3;
    }
    result[SIZE] = '\0';

    return result;
}