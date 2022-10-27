#include "cs50.h"
#include <stdio.h>

int main(void)
    {
        string name = get_string("ENTER YOUR NAME: "); 
        printf("Hello, %s", name);
    }