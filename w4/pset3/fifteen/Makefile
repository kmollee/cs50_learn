#
# Makefile
#
# Computer Science 50
# Problem Set 3
#
lib_path=../../../cs50lib/lib
head_path=../../../cs50lib/include

fifteen: fifteen.c
	clang -I$(head_path) -L$(lib_path) -ggdb3 -O0 -std=c99 -Wall -Werror -o fifteen fifteen.c -lcs50 -lm

clean:
	rm -f *.o a.out core fifteen
