#!/usr/bin/env ruby

puts "Welcome to the Guessing Game ^_~"

number = rand(100)

guess = 0
until guess == number

    puts "Type a number between 0 and 100:"
    #chomp remove the '\n' form the end of the string
    guess = gets.chomp.to_i

    if guess < number
        puts "Too small."
    elsif guess > number
        puts "Too big."
    else
        puts "You guess it!"
    end

end