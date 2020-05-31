#!/usr/bin/env python3

'''
kevin.fiorentin@edu.pucrs.br
trabalho 1 de algoritmos e estruturas de dados 2
'''
import sys
import os
from pathlib import Path

# Umas constantes pra deixar um pouco mais legivel
LO = 0
HI = 1


def main(some_path):

    if os.path.isdir(some_path):
        files_path = get_files_path(some_path)
        answers = collect_answers_from(files_path)
        printt(answers)

    else:
        aux = some_path.strip().split("/")
        file_name = aux[len(aux) - 1]

        answer = least_possible_list_size(some_path)
        print(file_name, "->", answer)


def get_files_path(dir_path):
    return sorted(Path(dir_path).iterdir())


def collect_answers_from(files_path):
    return {file_path.name: least_possible_list_size(
        file_path) for file_path in files_path}


def least_possible_list_size(file_path):
    ip_list = process_file_contents(file_path)
    blocked_ranges = [ip_list.pop(0)]
    for ip_pair in ip_list:
        last_value_of = len(blocked_ranges) - 1

        if change_higher_value(ip_pair, blocked_ranges[last_value_of]):
            blocked_ranges[last_value_of][HI] = ip_pair[HI]

        elif not is_contained(ip_pair, blocked_ranges[last_value_of]):
            blocked_ranges.append(ip_pair)
    return last_value_of + 1


def process_file_contents(file_path):
    with open(file_path, "r") as file:
        return sorted(tuple(list(int(value) for value in line.strip().split("-")) for line in file))


def change_higher_value(interval_1, interval_2):
    return interval_2[LO] < interval_1[LO] \
        and interval_1[LO] < interval_2[HI] \
        and interval_2[HI] <= interval_1[HI]


def is_contained(interval_1, interval_2):
    return interval_2[LO] < interval_1[LO] and interval_1[HI] < interval_2[HI]


def printt(answers):
    for key, value in answers.items():
        print(f"{key} --> {value}")


if __name__ == '__main__':
    if len(sys.argv) == 1:
        print("Please specify path to directory or file.")
        print("Example:")
        print("python3 main.py /path/to/directory")
        sys.exit(0)
    main(sys.argv[1])
