#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string args[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    int k = atoi(args[1]) % 26;
    string text = get_string("text: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            continue;
        }
        int ascii_offset = isupper(text[i]) ? 65 : 97;
        int pi = text[i] - ascii_offset;
        int ci = (pi + k) % 26;
        printf("%c", ci + ascii_offset);
    }
    printf("\n");
    return 0;
}