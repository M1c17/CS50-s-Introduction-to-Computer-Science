#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float L; // average # of letters per 100 words
    float S; //average # of sentences per 100 words
    int count_letter = 0;
    int count_sentences = 0;
    int count_words = 1;

    string text = get_string("Text:\n");

    for(int i=0; i < strlen(text); i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count_letter++;
        }
        else if(text[i] == ' ')
        {
            count_words++;
        }
        else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences++;
        }
    }
    //printf("%i\n", count_letter);
    //printf("%i\n", count_words);
    //printf("%i\n", count_sentences);

        L = (float) count_letter / (float) count_words * 100;
        S = (float) count_sentences / (float) count_words * 100;
        float index = 0.0588 * L - 0.296 * S - 15.8;
    if(index <= 16 && index >= 0)
    {
        printf("Grade %d\n", (int) round(index)) ;
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}