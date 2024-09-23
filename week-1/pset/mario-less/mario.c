#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;
    // prompt the user for the pyramid's height (only positive integers)
    do
        height = get_int("Height: ");
    while (height < 1);

    // print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1; j > i; j--)
            printf(" ");
        for (int h = 0; h <= i; h++)
            printf("#");
        printf("\n");
    }
}
