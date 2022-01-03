#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double serial(int num)
{


	double count =0;
	for(int i=0; i< num; i++)
	{
		double x= 2*((double)rand()/(double)(RAND_MAX))-1;
		double y= 2*((double)rand()/(double)(RAND_MAX))-1;

		double dist= sqrt(x*x + y*y);

		if(dist<=1)count++;
	}

	return 4*(count)/(double)num ;

}



int main(int argc, char *argv[])
{

time_t start, end;


time(&start);

	double get= serial(atoi(argv[1]));

	printf("%f",get);

time(&end);

	double dif = difftime(end,start);

printf("total execution time is: %.6f\n ",dif);
return 0;
}
