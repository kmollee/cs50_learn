#
# Makefile
#
# Computer Science 50
# Problem Set 3
#
lib_path=../../../cs50lib/lib
head_path=../../../cs50lib/include

all: find generate

find: find.c helpers.c helpers.h
	clang -I$(head_path) -L$(lib_path) -ggdb3 -O0 -std=c99 -Wall -Werror -o find find.c helpers.c -lcs50 -lm

generate: generate.c
	clang -I$(head_path) -L$(lib_path) -ggdb3 -O0 -std=c99 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core find generate
