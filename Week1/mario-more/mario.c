#include "cs50.h"
#include <stdio.h>

int main(void) 
{
    int height;

    do {
    height = get_int("Height: ");
    } while (height < 0 || height > 8);

    int write = height;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < write - 1; j++)
        {
            printf(" ");
        }
        for (int u = write - i; u < (write + 1) ; u++)
        {
            printf("#");
        }
        printf("  ");
        for (int sec = write - i; sec < (write + 1) ; sec++)
        {
            printf("#");
        }
        printf("\n");
        write--;
    }
}