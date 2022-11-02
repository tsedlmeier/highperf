#include "stdio.h"
#include "stdlib.h"

#define N 16
// N - Anzahl an 1er = Anzahl der Stellen
// z.B   1 1 4 --> 001110 --> 6-3 = 3 Stellen (1 1 4)

int main(void)
{
    int k=1,y=1,z=1;
    int n = 3;
    for (size_t i = 0; i < N ; i++)
    {
        for (size_t j = 0; j < n ; j++)
        {
            printf("%d ", k);
        }
        printf("%d %d", y,z);
        if( (z--) == 0 ) 
        {
            n--;
            y++;
        }
    printf("\n");
    }
}
