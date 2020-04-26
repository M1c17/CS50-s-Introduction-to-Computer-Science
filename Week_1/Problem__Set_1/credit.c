#include <stdio.h>
#include <cs50.h>

/**
 * Example:
 *
 * 4003600000000014
 *  - - - - - - -
 *
 * 1*2 + 0*2 + 0*2 + 0*2 + 0*2 + 6*2 + 0*2 + 4*2 = 13
 *
 * 4003600000000014
 * - - - - - - - -
 *
 * 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 7
 *
 * 13 + 7 = 20
 *
 * 20 % 10 == 0 / VALID CARD
 *
 */

int main()
{
    long long number_card = get_long_long("credit card number:\n");
    int number_digits = 0;
    int sum_evens = 0, sum_odds = 0;
    int digit_1 = 0, digit_2 = 0;


    while(number_card > 0)
    {
        digit_2 = digit_1;
        digit_1 = number_card % 10; //return the rightmost digit

        if(number_digits % 2 == 0)
        {
            sum_evens += digit_1;
        }
        else
        {
            int mult = digit_1 * 2;
            sum_odds += (mult / 10) + (mult % 10);
        }
        number_card /=10;
        number_digits ++;
    }

    bool is_valid_card = (sum_evens + sum_odds) % 10 == 0;
    int first_two_digits = (digit_1 * 10) + digit_2;

    if(number_digits == 15 && (first_two_digits == 34 || first_two_digits == 37) && is_valid_card)
    {
        printf("AMEX\n");
    }
    else if(number_digits == 16 && (first_two_digits >= 51 && first_two_digits <= 55) && is_valid_card)
    {
        printf("MASTERCARD\n");
    }
    else if((number_digits >= 13 && number_digits <= 16) && digit_1 == 4 && is_valid_card)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}



