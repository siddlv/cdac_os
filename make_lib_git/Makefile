CC = gcc -O3

main: main.o add.o sub.o mul.o div.o
	$(CC) -o main main.o add.o sub.o mul.o div.o

main.o: main.c 
	$(CC) -o main.o -c main.c

add.o: add.c
	$(CC) -o add.o -c add.c

sub.o: sub.c
	$(CC) -o sub.o -c sub.c

mul.o: mul.c
	$(CC) -o mul.o -c mul.c

div.o: div.c
	$(CC) -o div.o -c div.c

clean: 
	rm -rf *.o main