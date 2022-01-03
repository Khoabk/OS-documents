all : mutex semaphore

mutex: mutex.c
	gcc -o mutex mutex.c -lm -pthread -time

semaphore : semaphore.c
	gcc -o semaphore semaphore.c -lm -lpthread -lrt -time

clean:
	rm -f *.o
