#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float do;
    int co;

    do
    {
        do = get_float("Change owed: ");
        co = round(do * 100);
    }
    while (co <= 0);

    int q = co / 25;
    int d = (co % 25) / 10;
    int n = ((co % 25) % 10) / 5;
    int p = ((co % 25) % 10) % 5;

    printf("%d\n", q + d + n + p);
}