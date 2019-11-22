main: main.o pop.o push.o isfull.o isempty.o display.o
	 gcc -o main main.o pop.o push.o isfull.o isempty.o display.o
main.o: main.c
		gcc -o main.o -c main.c
pop.o: pop.c
		gcc -o pop.o -c pop.c
push.o: push.c
		gcc -o push.o -c push.c
isfull.o: isfull.c
		gcc -o isfull.o -c isfull.c
isempty.o: isempty.c
		gcc -o isempty.o -c isempty.c
display.o: display.c
		gcc -o display.o -c display.c
clean: 
	rm -rf *.o main