#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    if (argc == 2)
    {
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            if(!isdigit(argv[1][i]))
            {
                printf("Usage ./caesar key\n");
                return 1;
            }
        }
        printf("Success\n")
    }
    else
    {
        printf("Usage ./caesar key\n");
        return 1;
    }
    return 0;
}