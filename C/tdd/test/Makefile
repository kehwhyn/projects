include = -I../../../../usr/include/CppUTest/

all: main
	./main1

main: objects.o
	g++ *.o -o main1

objects.o:
	g++ -c main.cpp test.cpp -I$(include)

clean:
	rm -rf main1 *.o
