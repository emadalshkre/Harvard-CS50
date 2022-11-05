#include "cs50.h"
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int liau(char *text);

int main(void) 
{
    char *text = get_string("Enter Your Text:");
    int grade = liau(text);
    if (grade < 2)
    {
        printf("grade: 1");
    }
    else if (grade > 16)
    {
        printf("grade: 16+");
    }
    else
    {
        printf("grade: %i", grade);
    }
}
int liau(char *text)
{
    float index = 0;
    int words = 1;
    int letters = 0;
    int sentences = 0;
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) != 0 || islower(text[i]) != 0)
        {
            letters++;
        }
        if (isspace(text[i]) != 0)
        {
            words++;
        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
        float L =  letters / floor(words) * 100;
        float S =  sentences / floor(words) * 100;
        index = 0.0588 * L - 0.296 * S - 15.8;
        int grade = round(index);
        return grade;
}