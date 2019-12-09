CC=gcc
main:main.o create.o destroy.o free_block.o get_block.o 
	$(CC) -o main main.o create.o destroy.o free_block.o get_block.o -lpthread

main.o:main.c
	$(CC) -o main.o -c main.c -lpthread

create.o:create.c
	$(CC) -o create.o -c create.c

destroy.o:destroy.c 
	$(CC) -o destroy.o -c destroy.c

free_block.o: free_block.c
	$(CC) -o free_block.o -c free_block.c -lpthread

get_block.o:get_block.c 
	$(CC) -o get_block.o -c get_block.c -lpthread

clean:
	rm -rf *.o main

libmemory:
	ar -crv -o libmemory.a create.o destroy.o