#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;
    // prompt the user for the pyramid's height (between 1 and 8)
    do
        height = get_int("Height: ");
    while (height < 1 || height > 8);

    // print 2 piramid
    for (int i = 0; i < height; i++)
    {
        // print the first piramid
        for (int ii = height - 1; ii > i; ii--)
            printf(" ");
        for (int iii = 0; iii <= i; iii++)
            printf("#");

        // space between piramids
        printf("  ");

        // print the second piramid
        for (int iv = 0; iv <= i; iv++)
            printf("#");

        printf("\n");
    }
}
