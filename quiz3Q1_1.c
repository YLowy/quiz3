#include <stdio.h>
int asr_i(signed int m, unsigned int n)
{
    const int logical = (((int) -1) >> 1) > 0;
    if(logical)
    	puts("logical = 1\n");
    unsigned int fixu = -(logical & (m));
    int fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
} 

int main(){
	int shift = 4;
	unsigned int x = 0xFFFFFFF0;
	// undefined behavior 
	printf("%x >> %d = %x \n",x,shift,x>>shift);
	
	printf("%x >> %d = %x \n",x,shift,asr_i(x,shift));
}
