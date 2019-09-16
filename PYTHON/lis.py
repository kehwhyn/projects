#!/usr/bin/env python3

def characterOccurencesIn(word):

    occurences = dict()
    for character in word:
        if character not in occurences:
            occurences[character] = 1
        else:
            occurences[character] += 1

    return occurences

print(characterOccurencesIn("Micaelle"))
