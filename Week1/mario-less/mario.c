#include "cs50.h"
#include <stdio.h>

int main(void) 
{
    int height ;
    do {
        height = get_int("Height: ");
    } 
        while (height < 1 || height > 8);

    int io = height;

    for (int i = 0; i < height; i++)
    {
        for (int space = 0; space < io - 1; space++)   
        {
            printf(" ");
        }
        for (int hash = io - i; hash < io + 1; hash++)
        {
            printf("#");
        }
        io--;
        printf("\n");
    }
}