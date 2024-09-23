#include <cs50.h>
#include <stdio.h>

void get_name(string name, string lastname);

int main(void)
{
    get_name("hermes", "trismegisto");
}

void get_name(string name, string lastname)
{
    printf("%s %s\n", name, lastname);
}
