#!/usr/bin/env python

import time
from collections import deque
from contextlib import contextmanager

FILE_PATH = 0
OFFSET = 1
VALUES = (
    ("T2/caso1_cohen.txt", 100),
    ("T2/caso2_cohen.txt", 200),
    ("T2/caso3_cohen.txt", 500),
    ("T2/caso4_cohen.txt", 1000),
    ("T2/caso5_cohen.txt", 2000),
    ("T2/caso6_cohen.txt", 5000),
    ("T2/caso7_cohen.txt", 20000),
)


@contextmanager
def timeit_context(name):
    start_time = time.time()
    yield
    elapsed_time = time.time() - start_time
    print('[{}] finished in {} ms'
          .format(name, int(elapsed_time * 1000)))
    print()


def main():
    print('Olá! :D')
    option = 0
    while option is not 3:
        show_menu_options()
        option = read_user_input()
        if option is 1:
            choose_one_file()
        elif option is 2:
            process_all_files()
        elif option is 3:
            print('Bye! :D')
            break
        else:
            print()
            print('Opção inválida, tente novamente')


def show_menu_options():
    print('O que deseja fazer?')
    print('1 - Executar um único arquivo.')
    print('2 - Executar todos os arquivos.')
    print('3 - Terminar o programa.')


def read_user_input():
    return int(input("Digite o número da sua opção: "))


def choose_one_file():
    show_files_options()
    while True:
        chosen_file = read_user_input()
        if chosen_file < len(VALUES):
            process_one_file(chosen_file)
            break
        print("Por favor, digite um número válido.")


def show_files_options():
    print()
    print('Aqui estão os arquivos disponíveis:')
    for index, aux in enumerate(VALUES):
        file_name = aux[0].split('/')[1]
        print('{} - {}'.format(index, file_name))


def process_one_file(chosen_file):
    file_name = VALUES[chosen_file][FILE_PATH].split('/')[1]
    with timeit_context(file_name):
        maze = map_maze(VALUES[chosen_file][FILE_PATH])
        hero = maze.index('A')
        villain = maze.index('B')
        answer = shortest_path(
            maze,
            VALUES[chosen_file][OFFSET],
            hero,
            villain
        )
        print()
        print('>>> {} => {}'
              .format(file_name, answer))


def map_maze(file_path):
    with open(file_path, 'r') as file:
        tmp = ([
            char
            for line in file
            for char in line
            if char is not '\n'
        ])
    return tmp


def map_maze_as_matrix(file_path):
    tmp = []
    with open(file_path, 'r') as file:
        for row, line in enumerate(file):
            tmp.append([])
            for char in line:
                if char is not '\n':
                    tmp[row].append(char)
    return tmp


def shortest_path(maze, offset, source, destiny):
    visited = [False] * len(maze)
    dist_to = [0] * len(maze)
    queue = deque([source])
    while len(queue) is not 0:
        v = queue.popleft()
        for w in [v - offset, v - 1, v + offset, v + 1]:
            if maze[w] is not '#':
                if not visited[w]:
                    if w == destiny:
                        return dist_to[v] + 1
                    dist_to[w] = dist_to[v] + 1
                    visited[w] = True
                    queue.append(w)


def process_all_files():
    print('This might take a while...')
    for chosen_file in range(len(VALUES)):
        process_one_file(chosen_file)


def shortest_path_2(maze, offset, source, destiny):
    INDEX = 0
    VISITED = 1
    DIST_TO = 2
    all = [source, True, 0]
    queue = deque([all])
    while len(queue) is not 0:
        current_position = queue.popleft()
        print(current_position)
        for neighbor in [
            [current_position[INDEX] - offset, False, current_position[DIST_TO]],  # up
            [current_position[INDEX] - 1, False, current_position[DIST_TO]],  # left
            [current_position[INDEX] + offset, False, current_position[DIST_TO]],  # down
            [current_position[INDEX] + 1, False, current_position[DIST_TO]],  # right
        ]:
            if maze[neighbor[INDEX]] is not '#':
                # O objeto que entrou na fila tem que ser composto de uma lista == [index, visited, dist_to]
                # isso redux o uso de memória por alocar dois vetores
                # depois de usar o valor eliminar a tupla
                if not neighbor[VISITED]:
                    neighbor[DIST_TO] = current_position[DIST_TO] + 1
                    neighbor[VISITED] = True
                    queue.append(neighbor)
    return 0


def main_2():
    maze = map_maze('T2/caso0_cohen.txt') # 11 é a resposta certa
    hero = maze.index('A')
    villain = maze.index('B')
    answer = shortest_path(maze, 10, hero, villain)
    print(answer)


if __name__ == '__main__':
    main()
    #main_2()
