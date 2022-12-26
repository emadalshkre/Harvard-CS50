#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

const int headsize = 512;

bool bitarith(uint8_t copy[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./recover card.raw\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        return 2;
    }

    uint8_t buffer[headsize];
    int time = 1;
    char filename[20];

    while (fread(buffer, 1, headsize,input) == headsize)
    {
        if (bitarith(buffer) == true)
        {
            sprintf(filename, "%03i.jpg", time);
            FILE *img = fopen(filename, "w");
            fwrite(buffer, 1, headsize, img);
            fread(buffer, 1, headsize, input);
            while(bitarith(buffer) == false)
            {   
                fwrite(buffer, 1, headsize, img);
                fread(buffer, 1, headsize, input);
            }
            fclose(img);
            time++;
        }
    }
    fclose(input);
}

bool bitarith(uint8_t copy[])
{
    if (copy[0] == 0xff && copy[1] == 0xd8 && copy[2] == 0xff && (copy[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}