#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("How tall the pyramid should? :\n");

    } while (height <= 0 || height > 8);

    for(int row= 0; row < height; row++)
    {
        for(int spaces = height - row; spaces > 1; spaces--)
        {
            if(height == 1)
            {
                break;
            }else
            {
                printf(" ");
            }
        }
        for(int hashes = 0; hashes <= row; hashes++)
        {
            printf("#");
        }    
        printf("\n");
    }     
}