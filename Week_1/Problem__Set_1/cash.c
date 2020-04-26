#include <stdio.h>
#include <cs50.h>

//which coins and
//how many of each to hand to the customer
int main(void)
{
    int quarters = 25, dimes = 10, nickels = 5, pennies = 1;
    int min_coins = 0;
    double change;

    do
    {
        change = get_double("How much change is owned?\n");
    }
    while (change <= 0);

    double cents = change * 100;

    while (cents > 0)
    {
        min_coins ++;
        if (cents >= quarters)
        {
            cents -= quarters;
        }
        else if (cents >= dimes)
        {
            cents -= dimes;
        }
        else if (cents >= nickels)
        {
            cents -= nickels;
        }
        else
        {
            cents -= pennies;
        }
    }
    printf("%i\n", min_coins);
}