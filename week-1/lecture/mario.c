#include <cs50.h>
#include <stdio.h>

// mario function to print a brick
void marioBrick(int height, int width);

int main(void)
{
    int x, y;
    // prompt only positive integer
    do x = get_int("height: "); while (x < 1);
    do y = get_int("width: "); while (y < 1);

    marioBrick(x, y);
}

void marioBrick(int height, int width)
{   // iterate height times
    for(int i = 0; i < height; i++)
    {   // iterate width times
        for(int j = 0; j < width; j++)
            printf("#");
        printf("\n");
    }
}
