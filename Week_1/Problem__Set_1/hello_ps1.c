#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    string answer = get_string("What is your name:\n");
    while(true)
        printf("hello, %s\n", answer);

}

int main(void)
{   
    string answer = get_string("What is your name:\n");
    for(int i = 0; i < 4; i++)
        printf("hello, %s\n", answer);

}



