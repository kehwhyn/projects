use std::{
    fs::File,
    path::Path,
    io::{BufRead, BufReader, Lines, Result},
    collections::VecDeque,
};

const SIZE: usize = 7;
const VALUES: [(&str, usize); SIZE] = [
    ("./T2/caso1_cohen.txt", 100),
    ("./T2/caso2_cohen.txt", 200),
    ("./T2/caso3_cohen.txt", 500),
    ("./T2/caso4_cohen.txt", 1_000),
    ("./T2/caso5_cohen.txt", 2_000),
    ("./T2/caso6_cohen.txt", 5_000),
    ("./T2/caso7_cohen.txt", 20_000),
];
const FILE_NAMES: [&str; SIZE] = [
    "caso1_cohen.txt",
    "caso2_cohen.txt",
    "caso3_cohen.txt",
    "caso4_cohen.txt",
    "caso5_cohen.txt",
    "caso6_cohen.txt",
    "caso7_cohen.txt",
];

fn main() {
    println!("Welcome! :D");
    loop {
        if menu() == 3 {
            break
        }
    }
}

fn menu() -> usize {
    show_menu_options();
    let option = read_user_input();
    match option {
        1 => exec_time(choose_one_file),
        2 => exec_time(process_all_files),
        3 => println!("Bye! :D"),
        _ => {
            println!();
            println!("Invalid option. Please, try again.");
        }
    }
    option
}

fn show_menu_options() {
    println!("What would you like to do?");
    println!("1 - Run one file.");
    println!("2 - Run all files.");
    println!("3 - Finish program.");
}

fn read_user_input() -> usize {
    println!();
    println!("Enter your option:");
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    match input.trim().parse::<usize>() {
        Ok(parsed_string) => parsed_string,
        Err(_) => 8,
    }
}

fn exec_time(f: fn()) {
    let start = std::time::Instant::now();
    f();
    let duration = start.elapsed();
    println!("Time to process one/all file(s): {:?}", duration);
}

fn choose_one_file() {
    show_files_options();
    loop {
        let chosen_file = read_user_input();
        if chosen_file <= SIZE {
            process_one_file(chosen_file);
            break;
        }
        println!("Please, enter a valid number between 1 and 7");
    }
}

fn show_files_options() {
    println!();
    println!("Here are all the available files:");
    for (index, name) in FILE_NAMES.iter().enumerate() {
        println!("{} - {}", index, name);
    }
}

fn process_one_file(chosen_file: usize) {
    let file_name =  FILE_NAMES[chosen_file];
    let (mut maze, hero, villain) = map_maze(VALUES[chosen_file].0, VALUES[chosen_file].1);
    let answer = shortest_path(
        &mut maze, 
        VALUES[chosen_file].1, 
        hero,
        villain);
    println!();
    println!(">>> {} => {}", file_name, answer);
}

fn map_maze (file_path: &str, size: usize) -> (Vec<(char, usize)>, usize, usize) {
    let mut maze = Vec::with_capacity(size * size);
    let mut source: usize = 0;
    let mut destiny: usize = 0;
    let file_path = Path::new(file_path);
    for (index, character) in read_lines(file_path).unwrap().flat_map(|line| line.unwrap().chars().collect::<Vec<char>>()).enumerate() {
        maze.push((character, 0));
        if character == 'A' {
            source = index;
        }
        if character == 'B' {
            destiny = index;
        }
    }
    (maze, source, destiny)
}

fn read_lines (filename: &Path) -> Result<Lines<BufReader<File>>> {
    let file = File::open(filename).expect("Error opening file.");
    Ok(BufReader::new(file).lines())
}

fn shortest_path(maze: &mut Vec<(char, usize)>, offset: usize, source: usize, destiny: usize) -> usize {
    let mut queue = VecDeque::new();
    queue.push_back(source);
    let mut aux: usize = 0;
    while aux != destiny {
        let curr_pos = queue.pop_front().unwrap();
        for next_pos in vec![curr_pos - offset, curr_pos - 1, curr_pos + offset, curr_pos + 1] {
            aux = next_pos;
            let (c, d) = maze[next_pos];
            if c != '#' && d == 0 {
                maze[next_pos] = (c, d + 1);
                queue.push_front(next_pos);
            }
        }
    }
    maze[destiny].1
}

fn process_all_files() {
    println!("This might take a while...");
    for chosen_file in 0..=SIZE {
        process_one_file(chosen_file);
    }
}