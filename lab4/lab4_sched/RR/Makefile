all : sched sched_debug

sched : sched.o queue.o
	gcc -o sched sched.o queue.o -lpthread


sched_debug : sched.o queue.o
	gcc -g -o sched_debug sched.o queue.o -lpthread

sched.o : sched.c queue.h
	gcc -c sched.c -lpthread

queue.o : queue.c queue.h
	gcc -c queue.c -lpthread
	
	



		
clean:
	rm -f *.o
