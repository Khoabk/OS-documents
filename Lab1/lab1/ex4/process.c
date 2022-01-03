#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int main()
{


char ch, file_name[]={'i','n','p','u','t','.','t','x','t'};

FILE *fp;

fp = fopen(file_name,"r");


int arr[1000];

int i=0;
int accum=0;



while((ch = fgetc(fp)) != EOF && i < 1000)
{
    if(ch=='\n'){
	arr[i]=accum;
//	printf("%d\n",arr[i]);
	accum =0;
	 i++;

	continue;}
	accum= 10*accum + (int)ch-48;

	}


	int count=0;

	int id=fork();

	if(id<0)
	{
	printf("Error occurs\n");
	return -1;
	}
	if(id==0)
	{
	 

	for(int j=0; j <i; j++)
	{
			
		if(arr[j]%3==0)count++;
	//	printf("%d ,kkkk,   %d, ",arr[j],count);
	}

	printf("%d\n",count);

	}
	else{

         	for(int j=0; j <i; j++)
	{
		if(arr[j]%2==0)count++;
	}

	printf("%d\n",count);


	wait(NULL);
	}


	return 0;

}
