lib_path=../../../cs50lib/lib
head_path=../../../cs50lib/include
resize:resize.c
	clang -I$(head_path) -L$(lib_path) -ggdb3 -O0 -std=c99 -Wall -Werror -o resize resize.c -lcs50 -lm
copy: copy.c
	clang -I$(head_path) -L$(lib_path) -ggdb3 -O0 -std=c99 -Wall -Werror -o copy copy.c -lcs50 -lm
valgrind:
	valgrind --leak-check=full ./copy
clean:
	rm -f *.o copy resize
