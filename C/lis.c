#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CONTAINER_SIZE 10

typedef struct {
	char character;
	int count;
} Container;

Container *characterOccurencesIn(char const *);
int characterIsIn(Container *, char const);

int main(int argc, char **argv) {

	Container *aux = characterOccurencesIn("banana");

	for(int i = 0; i < CONTAINER_SIZE; i++)
		printf("'%c' -> '%d', ", aux[i].character, aux[i].count);
	
	printf("\n");

	free(aux);  
	
	return 0;
}

Container *characterOccurencesIn(char const *word){

	Container *occurences = calloc(CONTAINER_SIZE, sizeof(Container));

	for(int i = 0, position = 0; i < strlen(word); i++){
		position = characterIsIn(occurences, word[i]);
		if(!position) {
			occurences[i].character = word[i];
			occurences[i].count++;
		} else  
			occurences[position].count++;
	}

	return occurences;
}

int characterIsIn(Container *occurences, char const character){
	for(int i = 0; i < CONTAINER_SIZE; i++)
		if(occurences[i].character == character)
			return i;
	
	return 0;
}
