import strutils
import sequtils
import deques
import algorithm
import times

const LO = 0
const HI = 1
const FILES_PATH: array[13, string] = [
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
    "ip_list_filter_test_cases/cohen12.txt",
]

template benchmark(benchmarkName: string, code: untyped) =
  block:
    let t0 = epochTime()
    code
    let elapsed = int((epochTime() - t0) * 1000)
    #let elapsedStr = elapsed.formatFloat(format = ffDecimal, precision = 3)
    echo "CPU Time [", benchmarkName, "] ", elapsed, " ms"

proc change_higher_value(interval_1: seq[int], interval_2: seq[int]): bool =
    return interval_2[LO] < interval_1[LO] and
           interval_1[LO] < interval_2[HI] and
           interval_2[HI] <= interval_1[HI]

proc is_contained(interval_1: seq[int], interval_2: seq[int]): bool =
    return interval_2[LO] < interval_1[LO] and
           interval_1[HI] < interval_2[HI]

proc get_ip_list(file_path: string): seq[seq[int]] =
    let file = open(file_path)
    defer: file.close()
    return file.readAll()
        .strip(chars = {'\n'})
        .split()
        .mapIt(
            it.split("-")
            .map(parseInt)
        )

proc least_possible_list_size(ip_list: seq[seq[int]]): int =
    var blocked_ranges = initDeque[seq[int]]()
    blocked_ranges.addLast(ip_list[0])

    for ip_pair in ip_list:
        let last_item = blocked_ranges.peekLast()
        if change_higher_value(ip_pair, last_item):
            var aux = blocked_ranges.popLast()
            aux[HI] = ip_pair[HI]
            blocked_ranges.addLast(aux)
        elif not is_contained(ip_pair, last_item):
            blocked_ranges.addLast(ip_pair)

    return blocked_ranges.len() - 1

proc process_single_file(chosen_file: int) =
    benchmark FILES_PATH[chosen_file].split("/")[1]:   
        let answer = least_possible_list_size(
            get_ip_list(FILES_PATH[chosen_file])
            .sortedByIt(it[LO])
        )
        echo ">>> ", FILES_PATH[chosen_file].split("/")[1], " => ", answer

proc run_all_files() =
    benchmark "all files":
        for index, file in FILES_PATH:
            process_single_file(index)

proc read_user_input(): int = 
    echo "Plese, enter the option number: "
    return readLine(stdin).parseInt()

proc show_files_options() = 
    for index, file in FILES_PATH:
        echo ">>> ", index, " => ", file.split("/")[1]

proc choose_one_file() = 
    show_files_options()
    while true:
        let chosen_file = read_user_input()
        if chosen_file < FILES_PATH.len():
            process_single_file(chosen_file)
            break
        echo "Please, enter a valid number"
 
proc show_menu_options() = 
    echo "What would you like to do?"
    echo "1 - Run single file"
    echo "2 - Run all files"
    echo "3 - Exit program"

proc main() =
    echo "Welcome! :D"
    while true:
        show_menu_options()
        var option = read_user_input()
        case option:
            of 1:
                choose_one_file()
            of 2:
                run_all_files()
                break
            of 3:
                echo "Bye! :D"
                break
            else:
                echo "Please, enter a valid option"
        
main()