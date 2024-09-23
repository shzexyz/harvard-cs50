#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("type a number ");
    int y = get_int("type another number ");

    if(x < y)
    {
        printf("x (%i) is less than y (%i) \n", x, y);
        return 0;
    }
    else if(x > y)
    {
        printf("x (%i) is bigger than y (%i) \n", x, y);
        return 0;
    }
    printf("x (%i) and y (%i) are equal\n", x, y);
}
