#!/usr/bin/env ruby 

myString = "Hello, World!"
puts "#{myString}"

myString.gsub!("World", "Ruby")
puts "#{myString}"

index = myString.index("Ruby")
puts "#{index}"

digits = (0..9)
digits.each do |digit|
    puts "In loop #{digit}"
end

text = "A regular expression is a sequence of characters that define a search pattern."
matches = text.match(/character/)
p matches
#Let’s say we want to find all the words that start with a vowel. 
p text.scan(/\b[aeiou][a-z]*\b/)

for x in (0..9) do
    puts "Kevin"
end

for x in (1..10) do
    puts "This is sentence number #{x}"
end