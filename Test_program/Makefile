cc = gcc
obj = countter.o test_program.o
libs = countter.h

test_program : $(obj)
	cc -o test_program $(obj)


test_program.o : test_program.c $(libs)
	cc -c test_program.c

countter.o : countter.c
	cc -c countter.c	

	 	
	
clean :
	rm test_program $(obj)


