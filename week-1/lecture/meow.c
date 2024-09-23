#include <stdio.h>
#include <cs50.h>

void sayItNtime(string word, int n);

int main(void)
{
    sayItNtime("meow",5);
}

void sayItNtime(string word, int n)
{
    for(int i = 0; i < n; i++)
        printf("%s\n", word);
}

