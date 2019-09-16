#!/bin/bash

echo "Bem vindx ao jogo da adivinhação"

RANGE=100
number=$(($RANDOM%RANGE))

guess=0
while [ $guess -ne $number ];
do
    echo "Digite um número entre 0 e 100:"
    read guess

    if [ $guess -lt $number ]; then
        echo "Muito pequeno."

    elif [ $guess -gt $number ]; then
        echo "Muito grande."
    else
        echo "Adivinhastes!"
    fi
done

