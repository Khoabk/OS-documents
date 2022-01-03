#include "ex1.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	void *p;
	void *p1;
	p = aligned_malloc(3, 8);
	
	p1 = aligned_malloc(4,2);
	
	printf("size is : %ld\r\n", (long unsigned int)(sbrk(0)-p));
	printf("Address of p` : %ld\r\n", (long unsigned int)(p));

	p = aligned_free(p);


	printf("Address of p1 : %ld\r\n", (long unsigned int)(p1));
	printf("Address of sbrk(0) : %ld\r\n", (long unsigned int)(sbrk(0)));

	if(p!=NULL)printf("%p\r\n",sbrk(0));

return 0;

}



