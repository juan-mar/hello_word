all: main.o
	gcc main.c -o main.o -std=c90

clean:
	rm main.o

