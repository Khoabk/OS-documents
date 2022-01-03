#include <stdio.h>
#include "readline.h"
#include "factorial.h"





int main(int argc, char * argv[])
{

  char sth[100];

    if(read_line(sth))
  {


	int i=0;
	int accum=0;

	while(sth[i]!='\n')
	{
   accum = 10*accum + (int)sth[i]-48;
//		printf("%d\n", (int)sth[i]);

		i++;
	}

	printf("%d\n",factorial(accum));
   }
     else printf("%d\n",-1);

return 0;

}



