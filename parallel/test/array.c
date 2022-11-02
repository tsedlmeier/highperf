#include <stdint.h>
#include <stdio.h>

int main(void)
{
    char chars[3] = {'1','2','3'};
    int ints[3] = {1,2,3};
    for(int i=0; i < 3; ++i)
    {
        printf("%d\n", ints[i]);
    }

    for(int i=0; i < 3; ++i)
    {
        printf("%c\n", chars[i]);
    }
    return 0;

}
