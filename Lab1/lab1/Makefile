
all: hello.o sth.o
	gcc hello.o sth.o -o hello

hello.o: hello.c sth.h
	gcc -c hello.c

sth.o: sth.c sth.h
	gcc -c sth.c

clean:
	rm -f *.o hello
