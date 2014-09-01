filename=
compiler:
	#gcc -v -std=c99 -I ../cs50lib $(filename).c cs50.c -o $(filename).exe
	gcc -Wall -Werror -ggdb3 -O0 -std=c99 -I../cs50lib $(filename).c -lcs50 -o $(filename).exe
	#gcc -Wall -Werror -ggdb3 -O0 $(filename).c -I../cs50lib -L../cs50lib -lcs50  -std=c99 -lcs50 -o $(filename).exe
factorial:
	gcc -Wall -Werror -ggdb3 -O0 -std=c99 -I../cs50lib factorial.c -lcs50 -o factorial
trainer:
	gcc -Wall -Werror -ggdb3 -O0 -std=c99 -I../cs50lib trainer.c -lcs50 -o trainer
my_trainer:
	gcc -Wall -Werror -ggdb3 -O0 -std=c99 -I../cs50lib my_trainer.c -lcs50 -o my_trainer
merge_sort:
	gcc -Wall -Werror -ggdb3 -O0 -std=c99 -I../cs50lib merge_sort.c -lcs50 -o merge_sort
pointers:
	gcc -Wall -Werror -ggdb3 -O0 -std=c99 -I../cs50lib pointers.c -lcs50 -o pointers
clean:
	rm -f *.o factorial trainer my_trainer merge_sort pointers

