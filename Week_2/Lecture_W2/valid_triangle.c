#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    float x = get_float("x:\n");
    float y = get_float("y:\n");
    float z = get_float("z:\n");
    bool result = valid_triangle(x, y, z);
    printf("%d\n", result);
}

bool valid_triangle(float x, float y, float z)
{
    //positives values and sums
    if ((x >= 0 || y >= 0 || z >= 0) && ((x + y >= z) && (x + z >= y) && (z + y >= x)))
    {
        return true;
    }

    return false;
}
