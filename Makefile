bsq: main.o file_input.o parse.o solve.o
	gcc -Wall -Werror -Wextra main.o file_input.o parse.o solve.o -o bsq

main.o: main.c
	gcc -c -Wall -Werror -Wextra main.c

file_input.o: file_input.c
	gcc -c -Wall -Werror -Wextra file_input.c

solve.o: solve.c
	gcc -c -Wall -Werror -Wextra solve.c

parse.o: parse.c
	gcc -c -Wall -Werror -Wextra parse.c

clean:
	rm *.o bsq