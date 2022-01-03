all : serial multi

serial : pi_serial.c
	gcc -o serial pi_serial.c -lm -pthread -time

multi : pi_multi_thread.c
	gcc -o multi pi_multi_thread.c -lm -pthread -time

clean:
	rm -f *.o
