#!/usr/bin/env python

import time
from collections import deque
from contextlib import contextmanager

FILE_PATH: int = 0
OFFSET: int = 1
VALUES: (str, int) = (
    ("T2/caso1_cohen.txt", 100),
    ("T2/caso2_cohen.txt", 200),
    ("T2/caso3_cohen.txt", 500),
    ("T2/caso4_cohen.txt", 1000),
    ("T2/caso5_cohen.txt", 2000),
    ("T2/caso6_cohen.txt", 5000),
    ("T2/caso7_cohen.txt", 20000),
)


@contextmanager
def timeit_context(name: str) -> None:
    start_time: float = time.time()
    yield
    elapsed_time: float = time.time() - start_time
    print('[{}] finished in {} ms'
          .format(name, int(elapsed_time * 1000)))
    print()


def main() -> None:
    print('Olá! :D')
    option: int = 0
    while option != 3:
        show_menu_options()
        option = read_user_input()
        if option == 1:
            choose_one_file()
        elif option == 2:
            process_all_files()
        elif option == 3:
            print('Bye! :D')
            break
        else:
            print()
            print('Opção inválida, tente novamente')


def show_menu_options() -> None:
    print('O que deseja fazer?')
    print('1 - Executar um único arquivo.')
    print('2 - Executar todos os arquivos.')
    print('3 - Terminar o programa.')


def read_user_input() -> int:
    return int(input('Digite o número da sua opção: '))


def choose_one_file() -> None:
    show_files_options()
    while True:
        chosen_file: int = read_user_input()
        if chosen_file < len(VALUES):
            process_one_file(chosen_file)
            break
        print('Por favor, digite um número válido.')


def show_files_options() -> None:
    print()
    print('Aqui estão os arquivos disponíveis:')
    for index, aux in enumerate(VALUES):
        file_name: str = aux[0].split('/')[1]
        print('{} - {}'.format(index, file_name))


def process_one_file(chosen_file: int) -> None:
    file_name: str = VALUES[chosen_file][FILE_PATH].split('/')[1]
    with timeit_context(file_name):
        maze: [str] = map_maze(VALUES[chosen_file][FILE_PATH])
        hero: int = maze.index('A')
        villain: int = maze.index('B')
        answer: int = shortest_path(
            maze,
            VALUES[chosen_file][OFFSET],
            hero,
            villain
        )
        print()
        print('>>> {} => {}'.format(file_name, answer))


def map_maze(file_path: str) -> [str]:
    with open(file_path, 'r') as file:
        tmp: [str] = [
            char
            for line in file
            for char in line
            if char != '\n'
        ]
    return tmp


def shortest_path(maze: [str], offset: int, source: int, destiny: int) -> int:
    queue: deque[int] = deque([source])
    w: int = 0
    maze[source] = 0
    while w != destiny:
        v: int = queue.popleft()
        for w in (v - offset, v - 1, v + offset, v + 1):
            if maze[w] != '#' and type(maze[w]) is not int:
                maze[w] = maze[v] + 1
                queue.append(w)
    return maze[w]


def process_all_files() -> None:
    print('This might take a while...')
    for chosen_file in range(len(VALUES)):
        process_one_file(chosen_file)


if __name__ == '__main__':
    main()
