all : cond_usg no_synch

cond_usg : cond_usg.c
	gcc -o cond_usg cond_usg.c -pthread

no_synch : no_synch.c
	gcc -o no_synch no_synch.c -pthread

clean:
	rm -f *.o
