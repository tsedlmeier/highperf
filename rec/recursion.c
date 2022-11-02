#include <stdint.h>
#include <stdio.h>

#define N 19

// globals
uint32_t A[N];
int count;

void rec(size_t j)
{
    if(j==N)
    {
        // for(uint32_t i = 0; i < N; ++i)
        // {
        //     std::cout << A[i];
        // }
        // std::cout << std::endl;
        count++;

        return;
    }
    for(size_t v = 0; v < 3; ++v)
    {
        // if( j!=0 && v==A[j-1] ) continue;
        A[j] = v;
        rec(j+1);
    }
}

int main(int argc, char* argv[])
{
    rec(0);
    printf("Count: %d\n", count);
}
