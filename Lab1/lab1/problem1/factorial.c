#include "factorial.h"




int factorial(const int num)
{


	if(num<0)return -1;

	if(num ==0 )return 1;

	return num*factorial(num-1);


}
