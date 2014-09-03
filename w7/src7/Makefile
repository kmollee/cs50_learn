lib_path=../../cs50lib/lib
head_path=../../cs50lib/include
all:linked valgrind

linked: linked.c
	clang -I$(head_path) -L$(lib_path) -ggdb3 -O0 -std=c99 -Wall -Werror -o linked linked.c -lcs50 -lm
valgrind:
	valgrind --leak-check=full ./linked
clean:
	rm -f *.o linked
