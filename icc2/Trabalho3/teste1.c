#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, int  argv[])
{
    
    for(int i = 1; i < argc; i++)
    {
        printf("numero: %d\n", argv[i]);
    }
    return 0;
}
