use std::collections::HashMap;

fn character_occurences_in(word : String) -> HashMap<char, i32> {

    let mut occurences = HashMap::new();
    let mut times = 0;

    for character in word.chars() {

        println!("{}", {character});
    }




    occurences
}

fn main() {
    let string = String::from("banana");

    let aux = characterOccurencesIn(string);
    return;
}
