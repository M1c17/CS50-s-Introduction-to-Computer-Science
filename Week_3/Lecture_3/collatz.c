// The Collatz conjecture applies to positive integers
//speculates that it is always possible to get "back to 1"
//if follow this steps:
//if n ==1 stop
//otherwise is n is even, repeat this process on n/2
//otherwise is n is odd, repeat this process on 3n + 1
//Write a recursive function collatz(n) that calculates how
//many steps it takes to get to 1 if you start from n and recurse 

#include <stdio.h>
#include <cs50.h>

void collatz(int n);
int steps = 0;

int main(void)
{
    int n = get_int("Give me a positive int:\n");

    collatz(n);
    printf("number of steps: %i\n ", steps);
}

void collatz(int n)
{
    while(n > 1)
    {
        if(n == 1)
        {
            printf("%i ", n);
        }
        else if ((n % 2) == 0)
        {
            n = n/2;
            printf("%i ", n);
        }
        else
        {
            n = 3*n + 1;
            printf("%i ", n);
        }
    printf("\n");
    steps++;
    }
}
