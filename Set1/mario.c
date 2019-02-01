#include <stdio.h>
#include <cs50.h>

void repeat(char c, int times)
{
    while (--times >= 0)
    {
        printf("%c", c);
    }
}

int main()
{
    int height, width;
    do
    {
        h= get_int("Height: ");
        w= h+ 1;
    }
    while (h< 0 || h> 23);
    for (int i = 1; i <= height; i++)
    {
        int has = i + 1;
        int spa = w- has;

        repeat(' ', spa);
        repeat('#', has);
        printf("\n");
    }
}