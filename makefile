


main: main.o RPS.o
	gcc -o main main.o RPS.o -Wall -Wextra

main.o: main.c RPS.h RPS.c
	gcc -c main.c -Wall -Wextra

RPS.o: RPS.c RPS.h
	gcc -c RPS.c -Wall -Wextra

clean:
	rm *.o