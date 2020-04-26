#include <stdio.h>
#include <cs50.h>

int collatz(int n);
int steps = 0;
int main(void)
{
    int n = get_int("Give me a positive int:\n");

    collatz(n);
    printf("number of steps: %i\n ", steps);
}

int collatz(int n)
{
    if(n == 1)
    {
        printf("%i\n", n);
        return 0;
    }
    else if (n % 2 == 0)
    {
        steps++;
        printf("%i ", n);
        return collatz(n/2);
        
    }
    else
    {
        steps++;
        printf("%i ", n);
        return collatz(3*n + 1);
        
    }
}