filename=
compiler:
	#gcc -v -std=c99 -I ../cs50lib $(filename).c cs50.c -o $(filename).exe
	gcc $(filename).c -I../cs50lib -L../cs50lib -lcs50  -std=c99 -lcs50 -o $(filename).exe
	#gcc -std=c99 $(filename).c ../cs50lib/cs50.o -o $(filename).exe
run:
	./$(filename).exe

gdb:
	gdb ./$(filename)
clean:
	rm -f $(filename)
