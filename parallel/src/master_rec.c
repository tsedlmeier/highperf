#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PREFIX 2

// globals
uint32_t A[PREFIX];
int count;

void print_rec(uint32_t* A)
{
    for (size_t i = 0; i < PREFIX; i++)
    {
        printf("%d", A[i]);
    }
        printf("\n");
    return;

}

void rec(size_t j)
{
    if(j==PREFIX)
    {
        print_rec(A);
        return;
    }
    // Calculate PREFIX
    for(size_t v = 0; v < 3; ++v)
    {
        A[j] = v;
        rec(j+1);
    }
}

int main(int argc, char* argv[])
{
    // Generate prefix and write to file
    rec(0);
}
