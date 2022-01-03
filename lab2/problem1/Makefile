CC=gcc
CFLAGS=-I.
DEPS = ex1.h
OBJ = main.o ex1.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o ex1.o
	$(CC) -o main main.o ex1.o


clean:
	rm main main.o ex1.o
