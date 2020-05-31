use std::{
    collections::BTreeMap,
    fs::File,
    path::Path,
    time::Instant,
    io::{BufRead, BufReader, Lines, Result},
};

const HI: usize = 1;
const LO: usize = 0;
const FILES_PATH: [&str;13] = [
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen00.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen01.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen02.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen03.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen04.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen05.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen06.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen07.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen08.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen09.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen10.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen11.txt",
    "/home/kehwhyn/Documentds/data/alest_2/T1/cohen12.txt"
];
const FILES_NAME: [&str;13] = [
    "cohen00.txt",
    "cohen01.txt",
    "cohen02.txt",
    "cohen03.txt",
    "cohen04.txt",
    "cohen05.txt",
    "cohen06.txt",
    "cohen07.txt",
    "cohen08.txt",
    "cohen09.txt",
    "cohen10.txt",
    "cohen11.txt",
    "cohen12.txt"
];

fn main() {
    loop {
        if menu() == 3 {
            break;
        }
    }
}

fn menu () -> usize {
    show_options();
    let option = read_user_input();
    match option {
        1 => {
            let start = Instant::now();
            process_one_file();
            let duration = start.elapsed();
            println!("Time to process file: {:?}", duration);
        },
        2 => {
            let start = Instant::now();
            process_all_files();
            let duration = start.elapsed();
            println!("Time to process all files: {:?}", duration);
        },
        3 => {
            println!();
            println!(">>> Bye ^_~");
        },
        _ => {
            println!();
            println!("Opção inválida, tente novamente.");
        },
    }
    option
}

fn show_options () {
    println!();
    println!("1 - Executar um único arquivo.");
    println!("2 - Executar todos os arquivos.");
    println!("3 - Encerrar.");
}

fn read_user_input () -> usize {
    println!();
    println!("Digite o número da sua opção:");

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    match input.trim().parse::<usize>() {
        Ok(parsed_string) => parsed_string,
        Err(_) => 13,
    }
}

fn process_one_file () {
    println!("Estes são os arquivos disponiveis:");
    show_file_options();
    loop {
        let index = read_user_input();
        if index < 13 {
            let ip_list = read_file(FILES_PATH[index]);
            let file_name = FILES_NAME[index];
            let length = least_possible_list_size(ip_list);
            println!();
            println!(">>> {} => {}", file_name, length);
            break;
        }
        println!("Por favor digite um número válido.");
    }
}

fn show_file_options () {
    println!();
    println!("0 - cohen00.txt");
    println!("1 - cohen01.txt");
    println!("2 - cohen02.txt");
    println!("3 - cohen03.txt");
    println!("4 - cohen04.txt");
    println!("5 - cohen05.txt");
    println!("6 - cohen06.txt");
    println!("7 - cohen07.txt");
    println!("8 - cohen08.txt");
    println!("9 - cohen09.txt");
    println!("10 - cohen10.txt");
    println!("11 - cohen11.txt");
    println!("12 - cohen12.txt");
}

fn read_file (file_path: &str) -> Vec<Vec<i32>> {
    let mut ip_list = Vec::<Vec<i32>>::new();
    let file_path = Path::new(file_path);
    for line in read_lines(file_path).unwrap() {
        ip_list.push(
            line.unwrap()
                .split('-')
                .collect::<Vec<&str>>()
                .into_iter()
                .map(|string| string.parse::<i32>().unwrap())
                .collect(),
        );
    }
    ip_list.sort();
    ip_list
}

fn read_lines (filename: &Path) -> Result<Lines<BufReader<File>>> {
    let file = File::open(filename).expect("Error opening file.");
    Ok(BufReader::new(file).lines())
}

fn least_possible_list_size (ip_list: Vec<Vec<i32>>) -> usize {
    let mut blocked_ranges = Vec::<Vec<i32>>::new();
    let mut last_element: usize = 0;
    
    for ip_pair in ip_list {
        if blocked_ranges.is_empty() {
            blocked_ranges.push(ip_pair);
        } else if change_higher_value(&ip_pair, &blocked_ranges[last_element]) {
            blocked_ranges[last_element][HI] = ip_pair[HI];
        } else if !contained(&ip_pair, &blocked_ranges[last_element]) {
            blocked_ranges.push(ip_pair);
            last_element += 1;
        }
    }
    blocked_ranges.len()
}

fn change_higher_value (interval_1: &Vec<i32>, interval_2: &Vec<i32>) -> bool {
    return interval_2[LO] < interval_1[LO]
        && interval_1[LO] < interval_2[HI]
        && interval_1[HI] >= interval_2[HI];
}

fn contained (interval_1: &Vec<i32>, interval_2: &Vec<i32>) -> bool {
    return interval_2[LO] < interval_1[LO] 
        && interval_1[HI] < interval_2[HI];
}

fn process_all_files () {
    println!();
    println!("Computando as respostas...");

    let mut answers = BTreeMap::<&str, usize>::new();
    for (index, path) in FILES_PATH.iter().enumerate() {
        let ip_list = read_file(path);
        let file_name = FILES_NAME[index];
        let length = least_possible_list_size(ip_list);
        answers.insert(file_name, length);
    }

    println!();
    for (file_name, length) in answers {
        println!(">>> {} => {}", file_name, length);
    }
}