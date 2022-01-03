#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define batch 200




int count_val=5;



void * add(void *arg)
{

	printf("In add\n");
	printf("Count val%d\n", count_val);
	count_val++;
	return NULL;
}



void * sub(void *arg)
{
	printf("In sub\n");
	printf("Count val%d\n", count_val);
	count_val--;
	return NULL;
}



int main()
{
	pthread_t p1,p2,p3;
	

	pthread_create(&p1,NULL,add,NULL);
	pthread_create(&p2,NULL,sub,NULL);
	pthread_create(&p3,NULL,sub,NULL);


	pthread_join(p3,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	
	
	printf("Count val is: %d\n",count_val);

	return 0;

}
