FLAGS=-Wall -Werror -Wextra

bsq: main.o file_input.o parse.o solve.o
	gcc $(FLAGS) main.o file_input.o parse.o solve.o -o bsq

%.o:%.c bsqstructs.h
	gcc -c $(FLAGS) $<
clean:
	rm *.o bsq