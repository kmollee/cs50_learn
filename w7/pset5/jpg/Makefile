lib_path=../../../cs50lib/lib
head_path=../../../cs50lib/include
recover:recover.c
	clang -I$(head_path) -L$(lib_path) -ggdb3 -O0 -std=c99 -Wall -Werror -o recover recover.c -lcs50 -lm

clean:
	rm -f *.o *jpg recover
