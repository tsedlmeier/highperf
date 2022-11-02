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
		if(a[i]==0) break;
        printf("%d ", a[i]);
    }
}

int main(void)
{
	int n = 4;	//n vorletzte Stelle (y)
    //for (size_t i = 0; i < N ; i++)
	while(A[0] <= 6)
    {
			print(A);
			if(A[n+1]==1)
			{
				A[n] = A[n] + 1; 
				A[n+1] = 0;	
				n--;
			}
			else
			{
				A[n] = A[n] + 1;
        		//printf("A[n]=%d \n", A[n]);

				int sum = 0;
				for(int i=0; i<=n; i++)
				{
					sum += A[i];
				}
        		//printf("%d \n", sum);
				
				int j=n;
				for(j=n+1; sum<LEN; j++)
				{
					A[j] = 1;	
					sum++;
				}
				n = j-2;
        		//printf("n=%d \n", n);
			}
			printf("\n");
    }
}
