#include "stdio.h"
#include "stdlib.h"

#define N 16

int main(void)
{
    
    for(int  i = 0; i < N; i++)
    {
        int k = 1;
        for (int j = 4; j >= -1; j--) 
        {
            if( (i & (0x1<<j)) == 0 || j == -1)
            {
                printf("%d", k);
                k = 1;
            }
            else 
            {
                k++;
            }
        }
        printf("\n");
    }

    return 0;
}
