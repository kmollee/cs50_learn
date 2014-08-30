filename=
compiler:
	#gcc -v -std=c99 -I ../cs50lib $(filename).c cs50.c -o $(filename).exe
	gcc -Wall -Werror -ggdb3 -O0 -std=c99 -I../cs50lib $(filename).c -lcs50 -o $(filename).exe
	#gcc -Wall -Werror -ggdb3 -O0 $(filename).c -I../cs50lib -L../cs50lib -lcs50  -std=c99 -lcs50 -o $(filename).exe
run:
	./$(filename).exe

gdb:
	gdb ./$(filename)
clean:
	rm -f $(filename)
