#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "hello_world.h"
#include "sth.h"


#define OFFSET_LEN 10


typedef char BYTE;

int k;

int ss;






struct sth{


	int sth1;
	
	int sth2;

};




int main()
{


	int i= 0;
	
	
	
	if(fork()==0)
	{
	 
	 i++;
	
	printf("This is child process %d\n",i);
	
	
	if(fork()==0)
	{
	
	i++;
	printf("This is child process %d\n",i);
	
	exit(2);
	
	}
	
	
	wait(&i);
	
	printf("Status: %d\n", WEXITSTATUS(i));
	
	
	exit(1);
	
	}
	
	
	wait(&i);
	
	
	
	printf("Status: %d\n", WEXITSTATUS(i));
	
	
	
	
	int n = 5;
	
	int status;
	
	for(int i=0; i < n; i++)
	{
	
		if(fork()==0)
		{
			printf("Child process: %d\n",i);
			
			exit(i);
		}
	
		wait(&status);
		
		printf("Status: %d\n", WEXITSTATUS(status));
		

	}
	


return 0;
}
