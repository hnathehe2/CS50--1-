#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "trie.h"
#include "dictionary.h"

trie_t root = NULL;

unsigned long words = 0;

bool check(const char *word)
{
    return trie_find(root, word);
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    root = trie_create();
    if (root == NULL)
    {
        return false;
    }

    char buffer[LENGTH];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        if (!trie_insert(root, buffer))
        {
            unload();
            break;
        }

        words++;
    }

    fclose(file);

    return true;
}

unsigned int size(void)
{
    return words;
}

bool unload(void)
{
    trie_free(root);

    return true;
}