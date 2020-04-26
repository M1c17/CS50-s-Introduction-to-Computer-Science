// Abstraction with parameterization

#include <stdio.h>

void cough(int n); // proto type

int main(void)
{
    cough(3);
}

// Cough some number of times
// implementation detail
void cough(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("cough\n");
    }
}