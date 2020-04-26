#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            for(int j = i + 1; j < strlen(argv[1]); j++)
            {
                if(!isalpha(argv[1][i]) || argv[1][i] == argv[1][j])
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
                else
                {
                    if(strlen(argv[1]) != 26)
                    {
                        printf("Key must contain 26 characters.\n");
                        return 1;
                    }
                }
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string ptext = get_string("plaintext:\n");
    printf("ciphertext:");

    for(int i = 0; i < strlen(ptext); i++)
    {
        if(isalpha(ptext[i]))
        {
            if (isupper(ptext[i]))
            {
                // Convert ASCII to alphabetical index
                int alphaUpper = ptext[i] - 65;
                char upper_cipher = toupper(argv[1][alphaUpper]);
                printf("%c", upper_cipher);
            }
            else
            {
                // Convert ASCII to alphabetical index
                int alphaLower = ptext[i] - 97;
                char lower_cipher = tolower(argv[1][alphaLower]);
                printf("%c", lower_cipher);
            }

        }
        else
        {
            //print same character
            printf("%c", ptext[i]);
        }
    }
    printf("\n");
    //Success
    return 0;
}