#!/bin/bash
echo "Welcome to the name game!"
echo "Please enter your name:"

read name

echo "$name!"
echo "$name, $name, bo B${name:1}"
echo "banana fana, fo F${name:1}"
echo "fee fy, mo M${name:1}"
echo "$name!"

