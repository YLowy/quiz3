#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
 
size_t naive(uint64_t *bitmap, size_t bitmapsize, uint32_t *out)
{
    size_t pos = 0;
    for (size_t k = 0; k < bitmapsize; ++k) {
        uint64_t bitset = bitmap[k];
        size_t p = k * 64;
        for (int i = 0; i < 64; i++) {
            if ((bitset >> i) & 0x1)
                out[pos++] = p + i;
        }
    }
    return pos;
}
int main(){
	uint64_t bitmap[8];
	/*for(int i =0;i<=8;i++){
			bitmap[i] = (i%2==0)?0x00000001:0;
	}*/
	bitmap[0] = 0x0000000f;
	bitmap[1] = 0x00001000;
	bitmap[2] = 0x00000000;
	bitmap[3] = 0x00000000;
	bitmap[4] = 0x00000000;
	bitmap[5] = 0x00000000;
	bitmap[6] = 0x00000000;
	bitmap[7] = 0x00000000;
	uint32_t output[1000] ;
	
	size_t count = naive(bitmap,sizeof(bitmap)/sizeof(uint64_t),output);
	printf("pos = %d\n",count);
		printf("-------------------------\n");
	for(int j = 0;j<count;j++)
		printf("output[%d] = %d\n",j,output[j]);
	return 0;
}
