#!/usr/bin/env ruby
puts "Bem vindo ao jogo da adivinhação"

number = rand(100)

guess = 0
until guess == number
    puts "Digite um número entre 0 e 100" 
    guess = gets.chomp.to_i

    if guess < number
        puts "Muito pequeno."
    elsif guess > number 
        puts "Muito alto."
    else
        puts "Adivinhou!"
    end
end

