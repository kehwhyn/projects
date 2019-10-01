INCDIR = include/
SRCDIR = source/
OBJDIR = $(SRCDIR)/object/
TEST_DIR = test/
OUT = slamano

CC = gcc
CFLAGS = -c -I./

all: test main

test:
	make -C $(TEST_DIR)

test_clean:
	make -C $(TEST_DIR) clean

main: objects.o $(OBJDIR)
	$(CC) $(wildcard $^/*.o) -o $(OUT)

objects.o: $(INCDIR)
	$(CC) $(CFLAGS) $(SRCDIR)/*.c
	mv *.o $(OBJDIR)/

.PHONY: clean
clean:
	rm -rf $(OBJDIR)/*.o $(OUT)
