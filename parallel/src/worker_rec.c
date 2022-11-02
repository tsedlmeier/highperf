#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 17
#define PREFIX 2

// globals
int count;
uint32_t A[N];

void print_rec(uint32_t* Arr)
{
    for (size_t i = 0; i < (sizeof(A)/sizeof(uint32_t)); i++)
    {
        printf("%d", Arr[i]);
    }
    printf("\n");
    return;
}
void print_pref(char* pref)
{
    printf("%s", pref);
}

void rec(size_t j, char* pref)
{
    if(j==N)
    {
        // print_pref(pref);
        // print_rec(A);
        return;
    }
    // Calculate N
    for(size_t v = 0; v < 3; ++v)
    {
        A[j] = v;
        rec(j+1, pref);
    }

}

int main(int argc, char* argv[])
{
    char* prefixchar = argv[1];
    rec(0,prefixchar);
}
