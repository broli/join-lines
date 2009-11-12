CFLAGS=-ggdb -Wall -Wextra -pedantic 

LIBS=

objects = obj/main.o 

all : $(objects)
	gcc  $(CFLAGS) $(LIBS) $(objects) -o bin/join-lines

obj/main.o : main.c 
	gcc -c $(CFLAGS) main.c -o obj/main.o

clean :
	rm obj/* 
	rm bin/*

