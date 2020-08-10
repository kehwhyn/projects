#!/usr/bin/env python3

'''
kevin.fiorentin@edu.pucrs.br
trabalho 1 de algoritmos e estruturas de dados 2
'''
import time
from contextlib import contextmanager
from collections import deque

# Umas constantes pra deixar um pouco mais legivel
LO = 0
HI = 1
FILES_PATH = (
    "ip_list_filter_test_cases/casoenunciado.txt",
    "ip_list_filter_test_cases/cohen01.txt",
    "ip_list_filter_test_cases/cohen02.txt",
    "ip_list_filter_test_cases/cohen03.txt",
    "ip_list_filter_test_cases/cohen04.txt",
    "ip_list_filter_test_cases/cohen05.txt",
    "ip_list_filter_test_cases/cohen06.txt",
    "ip_list_filter_test_cases/cohen07.txt",
    "ip_list_filter_test_cases/cohen08.txt",
    "ip_list_filter_test_cases/cohen09.txt",
    "ip_list_filter_test_cases/cohen10.txt",
    "ip_list_filter_test_cases/cohen11.txt",
    "ip_list_filter_test_cases/cohen12.txt"
)


@contextmanager
def timeit_context(name: str) -> None:
    start_time: float = time.time()
    yield
    elapsed_time: float = time.time() - start_time
    print(f'[{name}] finished in {int(elapsed_time * 1000)} ms')
    print()


def main():
    print("Welcome! :D")
    while True:
        show_menu_options()
        option = read_user_input()
        if option == 1:
            choose_one_file()
        elif option == 2:
            run_all_files()
        elif option == 3:
            print("Bye! :D")
            break
        else:
            print("Please, enter a valid number.")


def show_menu_options():
    print("What would you like to do?")
    print("1 - Run a single file.")
    print("2 - Run all files.")
    print("3 - Exit program.")


def choose_one_file():
    show_files_options()
    while True:
        chosen_file = read_user_input()
        if chosen_file < len(FILES_PATH):
            process_single_file(chosen_file)
            break
        print("Please, enter a valid number.")


def show_files_options():
    for index, file_path in enumerate(FILES_PATH):
        print(">>> ", index, " => ", file_path.split("/")[1])


def read_user_input():
    return int(
        input("Please, enter the option number: ")
    )


def process_single_file(chosen_file):
    file_name = FILES_PATH[chosen_file].split("/")[1]
    with timeit_context(file_name):
        answer = least_possible_list_size(
            get_sorted_ip_list(FILES_PATH[chosen_file])
        )
        print(">>>", file_name, "=>", answer)


def least_possible_list_size(ip_list):
    blocked_ranges = deque([ip_list.popleft()])
    while len(ip_list) != 0:
        ip_pair = ip_list.popleft()
        last_added = len(blocked_ranges) - 1

        if change_higher_value(ip_pair, blocked_ranges[last_added]):
            blocked_ranges[last_added][HI] = ip_pair[HI]

        elif not is_contained(ip_pair, blocked_ranges[last_added]):
            blocked_ranges.append(ip_pair)

    return len(blocked_ranges)


def get_sorted_ip_list(chosen_file_path):
    with open(chosen_file_path, "r") as file:
        return deque(
            sorted(
                [int(value) for value in line.strip().split("-")]
                for line in file
            )
        )


def change_higher_value(interval_1, interval_2):
    return interval_2[LO] < interval_1[LO] and \
        interval_1[LO] < interval_2[HI] and \
        interval_2[HI] <= interval_1[HI]


def is_contained(interval_1, interval_2):
    return interval_2[LO] < interval_1[LO] and \
        interval_1[HI] < interval_2[HI]


def run_all_files():
    with timeit_context("All files"):
        for index in range(len(FILES_PATH)):
            process_single_file(index)


if __name__ == "__main__":
    main()
