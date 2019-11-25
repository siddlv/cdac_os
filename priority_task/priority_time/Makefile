main: main.o push.o peek.o 
	gcc -o main main.o push.o peek.o

main.o: main.c
	gcc -o main.o -c main.c

push.o: push.c
	gcc -o push.o -c push.c

peek.o: peek.c
	gcc -o peek.o -c peek.c

clean:
	rm -rf *.o main
