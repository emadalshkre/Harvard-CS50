#include "cs50.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[]) 
{
    //check if Key valid or not

    if (argc != 2)
    {
        printf("use: ./program Key");
        return 1;
    }
    //
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters");
        return 1;
    }
    //
    for (size_t i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) != 0)
        {
            printf("Key must contain alphabetic characters");
        }
    }
    //
    for (size_t i = 0; i < strlen(argv[1]); i++)
    {
        for (size_t j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] + 32|| argv[1][i] == argv[1][j] - 32)
            {
                printf("Key must not contain repeated characters");
                return 1;
            }
        }
    }
    //end of validate
    
    //Encipher
    char *input= get_string("Enter Text:");
    size_t len = strlen(input);
    char cipher[len];
    for (size_t i = 0; i < len; i++)
    {
        if (isupper(input[i]) != 0)
        {
            cipher[i] = argv[1][input[i] - 65];
        }
        else if (islower(input[i]) != 0)
        {
            cipher[i] = tolower(argv[1][input[i] - 97]);
        }
        else 
        {
            cipher[i] = input[i];
        }
    }
    for (size_t i = 0; i < len; i++)
    {
        printf("%c", cipher[i]);
    }
}