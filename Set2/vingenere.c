#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

bool check(string k)
{
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            return false;
        }
    }

    return true;
}

int main(int argc, string args[])
{
    if (argc != 2 || !check(args[1]))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string k = args[1];
    string text = get_string("text: ");
    int l = strlen(k);

    printf("ciphertext: ");

    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            continue;
        }

        int off = isupper(text[i]) ? 65 : 97;

        int pi = text[i] - off;
        int kj = toupper(k[j % l]) - 65;
        int ci = (pi + kj) % 26;
        j++;

        printf("%c", ci + off);
    }

    printf("\n");
    return 0;
}