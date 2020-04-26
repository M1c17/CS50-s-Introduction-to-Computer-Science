#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height:\n");
    } while (height <= 0 || height > 8);
    
    for(int row = 0; row < height; row++)
    {
        for(int space = height - row; space > 1; space--)
        {
            if(height == 1)
            {
                break;
            }else
            {
                printf(" ");
            }
        }
        for(int left_hashes = 0; left_hashes <= row; left_hashes++)
        {
            printf("#");
        }    
        printf("  ");

        for(int right_hashes = 0; right_hashes <= row; right_hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}