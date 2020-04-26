#include <stdio.h>
#include <cs50.h>

char left_pyramid(int height);
char right_pyramid(int height);


int main(void)
{
    int height;
    do 
    {
        height = get_int("Height:\n");
    }while(height < 0 || height > 8);
    char left = left_pyramid(height);
    char right = right_pyramid(height);
    printf("%s,'  ', %s\n", left, right);
}

char left_pyramid(int height)
{
    for(int row = 0; row < height; row++)
    {
        for(int spaces = height - row; spaces > 1; spaces--)
        {
            if(height == 1)
            {
                break;
            }else
            {
                char spaces = (char " ") malloc(2);
                return spaces;
            }
        }
        for(int hashes = 0; hashes <= row; hashes++)
        {
            char hashes = (char "#") malloc(2);
            return hashes;
        }
        printf("\n");
    }
}

char right_pyramid(int height)
{
    for(int row = 0; row < height; row++)
    {
        for(int hashes = 0; hashes <= row; hashes++)
        {
            char hashes = (char "#") malloc(2);
            return hashes;
        }
    }
}

