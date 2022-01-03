#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

#define batch 200


pthread_mutex_t lock;

int count_point=0;

int *buffer;



typedef struct{
	int idx;
	int data;
}Packet;



void *pi_thread(void * arg)
{


	 Packet*get = (Packet*)arg;
	
	int num = get->data;

	//int* iptr = (int*)malloc(sizeof(int));

//	*iptr = 0;

	for(int i=0; i< num; i++)
	{
		double x= 2*((double)rand()/(double)(RAND_MAX))-1;
		double y= 2*((double)rand()/(double)(RAND_MAX))-1;
		double dist= sqrt(x*x + y*y);



		if(dist<=1){ 
		
		
		
		pthread_mutex_lock(&lock);
		
		buffer[get->idx]++;

		pthread_mutex_unlock(&lock);
}
	}


	//return iptr;
}









int main(int argc, char *argv[])
{

time_t start, end;


time(&start);

	if(argc < 2)return 1;

	int num= atoi(argv[1]);
	int num2 =num;

	int count=0;

	while(num >batch)
	{
		count ++;
		num -= batch;
	}
	count++;


	pthread_t *ptr;

	ptr = malloc(sizeof(pthread_t)*count);
	buffer= (int*)calloc(count,sizeof(int));
	Packet *deliver= malloc(sizeof(Packet)*count);

	int sth= batch;

	for(int i=0; i<count; i++)
	{
	
	
	deliver[i].idx = i;
	deliver[i].data = (i==count-1)?num:sth;
	
		pthread_create(&ptr[i],NULL,pi_thread,&deliver[i]);
	}

	int sum=0;

	//int *result;


	for(int i=0; i<count; i++)
	{

		pthread_join(ptr[i],NULL);//(void**)&result);
		sum += buffer[i];


	}
	
	
	
	pthread_mutex_destroy(&lock);

	free(ptr);
	free(buffer);
	free(deliver);

	double sth2 = (double)sum/(double)num2;


	printf("%f\n",sth2*4);

time(&end);

double dif = difftime(end,start);

	printf("Total time is %.6f\n",dif);

return 0;

}
