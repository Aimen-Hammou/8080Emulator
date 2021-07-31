CC = gcc
CCFLAGS = -Wall -g


run:
	clear
	./8080


build: 8080.c
	$(CC) 8080.c $(CCFLAGS) -o 8080


	
