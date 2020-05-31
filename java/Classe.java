//autor kevin boucinha fiorentin
//email kevinboucinha@gmail.com

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class Classe {
    final static int LO = 0;
    final static int HI = 1;

    public static void main(final String[] args) {
        var files_path = get_files_path();
        var answers = collect_answers_from(files_path);
        write_in_file(answers);
    }

    public static ArrayList<String> get_files_path() {
        return (ArrayList<String>) Stream.of(new File("../cohen/").listFiles()).map(File::toString)
                .collect(Collectors.toList());
    }

    public static TreeMap<String, Integer> collect_answers_from(final ArrayList<String> files_path) {
        var answers = new TreeMap<String, Integer>();

        for (var file_path : files_path) {
            var size = least_possible_list_size(file_path);
            var name = file_path.split("/");
            answers.put(name[2], size);
        }
        return answers;
    }

    public static int least_possible_list_size(final String file_path) {
        var blocked_ranges = new ArrayDeque<ArrayList<Integer>>();

        final var ip_list = process_file_contents(file_path);
        ip_list.sort((tmp_1, tmp_2) -> tmp_1.get(LO) - tmp_2.get(LO));

        ip_list.stream().forEach(ip_pair -> {
            if (blocked_ranges.isEmpty()) {
                blocked_ranges.push(ip_pair);
            } else if (change_higher_value(ip_pair, blocked_ranges.peek())) {
                blocked_ranges.peek().set(HI, ip_pair.get(HI));
            } else if (!contained(ip_pair, blocked_ranges.peek())) {
                blocked_ranges.push(ip_pair);
            }
        });

        return blocked_ranges.size();
    }

    public static ArrayList<ArrayList<Integer>> process_file_contents(final String file_path) {
        var ret = new ArrayList<ArrayList<Integer>>();
        final var file = new File(file_path);

        try (final var file_reader = new FileReader(file);
                final var buffered_reader = new BufferedReader(file_reader)) {

            var line = new String();
            while ((line = buffered_reader.readLine()) != null) {
                final var tmp = (ArrayList<Integer>) Arrays.asList(line.split("-")).stream().map(Integer::valueOf)
                        .collect(Collectors.toList());
                ret.add(tmp);
            }
        } catch (IOException exception) {
            System.out.println(exception.getMessage());
        }

        return ret;
    }

    public static boolean change_higher_value(final ArrayList<Integer> interval_1,
            final ArrayList<Integer> interval_2) {
        return interval_2.get(LO) < interval_1.get(LO) && interval_1.get(LO) < interval_2.get(HI)
                && interval_2.get(HI) <= interval_1.get(HI);
    }

    public static boolean contained(final ArrayList<Integer> interval_1, final ArrayList<Integer> interval_2) {
        return interval_2.get(LO) < interval_1.get(LO) && interval_1.get(HI) < interval_2.get(HI);
    }

    public static void write_in_file(final TreeMap<String, Integer> answers) {
        final var file = new File("./answer.txt");
        try (final var file_writer = new FileWriter(file);
                final var buffered_writer = new BufferedWriter(file_writer);) {
            for (var entry : answers.entrySet()) {
                buffered_writer.write(String.format("%s -> %d \n", entry.getKey(), entry.getValue()));
            }
        } catch (IOException exception) {
            System.out.println(exception.getMessage());
        }
    }
}
