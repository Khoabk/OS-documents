#include <stdio.h>
#include "readline.h"


int read_line(char *str)
{

	char word[10000];

	fgets(word,sizeof(word),stdin);

	int i =0;

	int w_or_n =1;

	while(word[i]!='\0')
	{
		str[i]=word[i];

		if(w_or_n){

     		if(((int)str[i]<48||(int)str[i]>57)&&(str[i]!='\n'))
			w_or_n=0;
	          }
          i++;
	}

return w_or_n;
}
