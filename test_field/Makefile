

all: hello sth2


hello: hello_world.o sth.o
	gcc hello_world.o sth.o -o hello


hello_world.o: hello_world.c hello_world.h sth.h 
	gcc -c hello_world.c



sth.o: sth.c hello_world.h
	gcc -c sth.c



sth2: sth2.o sth.o
	gcc sth2.o sth.o -o sth2
	

sth2.o: sth2.c hello_world.h sth.h
	gcc -c sth2.c	




clean:
	rm *.o hello sth2
	
