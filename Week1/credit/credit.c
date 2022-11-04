#include "cs50.h"
#include <string.h>
#include <stdio.h>

int checksum(long long credit);
void type(long long credit);
int main(void) {
    long long credit = get_long_long("enter your credit: ");
    int check = checksum(credit);
    if (check % 10 != 1)
    {
        return 1;
    }
    type(credit);
}

int checksum(long long credit){
    int length = 0;
    int digites = 0;
    long long credit2 = credit;
    int cash = 0;
    credit /= 10;
    while (credit > 0)
    {
        length++;
        cash = credit % 10 * 2;
        if (cash > 9)
        {
            cash %= 10;
            cash++;
        }
        digites += cash;
        credit /= 10;
        credit /= 10;
    }
    while (credit2 != 0)
    {
        length++;
        digites += credit2 % 10;
        credit2 /= 10;
        credit2 /= 10;
    }
    return digites + 1;
}
void type(long long credit)
{
    long long no = credit;
    int length = 0;
    while (credit != 0)
    {
        length++;
        credit /= 10;
    } 
    while (no > 99 )
    {
        no /= 10;
    }
    if (length == 15 && no > 33 && no < 38)
    {
        printf("American Express");
    }
    if (length == 16 && no > 50 && no < 56)
    {
        printf("MasterCard");
    }
    if(length == 13 || length == 16 && no > 39 && no < 50)
    {
        printf("Visa");
    }
}