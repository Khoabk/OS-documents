#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

#define batch 200


pthread_mutex_t lock;

int count_point=0;



void *pi_thread(void * arg)
{

	int *get = (int*)arg;
	
	int num= *get;
	

	for(int i=0; i< num; i++)
	{
		double x= 2*((double)rand()/(double)(RAND_MAX))-1;
		double y= 2*((double)rand()/(double)(RAND_MAX))-1;
		double dist= sqrt(x*x + y*y);

		if(dist<=1){ 
		
		pthread_mutex_lock(&lock);
		
		count_point++;		

		pthread_mutex_unlock(&lock);
}
	}


}









int main(int argc, char *argv[])
{

time_t start, end;


time(&start);

	if(argc < 2)return 1;

	int num= atoi(argv[1]);
	int num2 =num;

	int count=0;
	
	int *idx;

	while(num >batch)
	{
		count ++;
		num -= batch;
	}
	count++;


	pthread_t *ptr;

	ptr = malloc(sizeof(pthread_t)*count);
	
	idx = malloc(sizeof(int)*count);


	for(int i=0; i<count; i++)
	{	

		if(i==count-1)idx[i]=num;
		else idx[i]=batch;
		pthread_create(&ptr[i],NULL,pi_thread,(void*)&idx[i]);
	}

	

	

	for(int i=0; i<count; i++)
	{
		pthread_join(ptr[i],NULL);
	}
	
	
	
	pthread_mutex_destroy(&lock);

	free(ptr);
	free(idx);

	double sth2 = (double)count_point/(double)num2;


	printf("%f\n",sth2*4);

time(&end);

double dif = difftime(end,start);

	printf("Total time is %.6f\n",dif);

return 0;

}
