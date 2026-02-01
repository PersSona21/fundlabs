CC = clang
CFLAGS = -Wall -Wextra -std=c11 -g -fsanitize=address

all:
	$(CC) $(CFLAGS) src/*.c -Iinclude -o main

clean:
	rm -f main *.o src/*.o
	rm -rf ./main.dSYM

run: all
	./main