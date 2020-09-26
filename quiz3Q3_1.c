#include <stdio.h>
int numberOfSteps (int num)
{
    return num ? __builtin_popcount(num)+ 31 - __builtin_clz(num): 0;
}

int main(){
	unsigned int x = 0x0000000F;
	
	printf("%x >> %d \n",x,numberOfSteps(x));
}
