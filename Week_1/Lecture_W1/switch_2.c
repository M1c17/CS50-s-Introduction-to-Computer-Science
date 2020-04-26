#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = scanf("%d", &x);

    switch(x)
    {
        case 1:
            printf("One!\n");
        case 2:
            printf("Two!\n");
        case 3:
            printf("Three!\n");
        default:
            printf("Sorry!\n");
    }
}