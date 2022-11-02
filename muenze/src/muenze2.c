#include "stdio.h"
#include "stdlib.h"

#define N 16
#define LEN 6
// N - Anzahl an 1er = Anzahl der Stellen
// z.B   1 1 4 --> 001110 --> 6-3 = 3 Stellen (1 1 4)
int A[LEN] = {1,1,1,1,1,1};

void print(int *a)
{
    for (size_t i = 0; i < sizeof(A)/sizeof(int) ; i++)
    {
        printf("%d ", a[i]);
    }
}
void shift(int *a)
{
    for (size_t i = LEN; i > 0 ; i--)
    {
        if (a[i]==0) {
            break;
        }
        a[i-1] = a[i];
    }
}

int main(void)
{
    int *y = &A[LEN-2];
    int *z = &A[LEN-1];
    for (size_t i = 0; i < N ; i++)
    {
        print(A);
        if( *z == 1 ) 
        {
            (*z)++; 
            shift(A);
        }
        else {
        }
    printf("\n");
    }
}
