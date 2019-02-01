#include <stdio.h>
#include <cs50.h>


int main()
{
    long long cc = get_long_long("Number: ");
    int digit1 = 0, digit2 = 0, num = 0, sum_o = 0, sum_e = 0;

    while (cc > 0)
    {
        digit2 = digit1;
        digit1 = cc % 10;

        if (num % 2 == 0)
        {
            sum_e += digit1;
        }
        else
        {
            int multiple = 2 * digit1;
            sum_o += (multiple / 10) + (multiple % 10);
        }

        cc /= 10;
        num++;
    }

    bool is_valid = (sum_e + sum_o) % 10 == 0;
    int first_two_digits = (digit1 * 10) + digit2;

    if (digit1 == 4 && num >= 13 && num <= 16 && is_valid)
    {
        printf("VISA\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && num == 16 && is_valid)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && num == 15 && is_valid)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}