#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string ar[])
{
    if (argc != 2)
    {
        printf("Usage: crack <h>\n");
    }
    const int n = 57;
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string h = ar[1];
    char s[3];
    memcpy(s, h, 2);
    s[2] = '\0';
    char key[6] = "\0\0\0\0\0\0";
    for (int e = 0; e < n; e++)
    {
        for (int d = 0; d < n; d++)
        {
            for (int c = 0; c < n; c++)
            {
                for (int b = 0; b < n; b++)
                {
                    for (int a = 1; a < n; a++)
                    {
                        key[0] = letters[a];
                        key[1] = letters[b];
                        key[2] = letters[c];
                        key[3] = letters[d];
                        key[4] = letters[e];

                        if (strcmp(crypt(key, s), h) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Password kho qua");
    return 2;
}