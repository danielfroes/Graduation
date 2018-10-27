all: main.c system.c a.out
	gcc main.c system.c
	./a.out