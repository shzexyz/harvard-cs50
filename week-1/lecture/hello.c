#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string ("what's your name? ");
    string lastname = get_string ("what's your lastname? ");
    printf("hello, %s %s!\n", name, lastname);
}
