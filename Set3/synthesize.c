#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"
#include "wav.h"

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: synthesize FILE\n");
        return 1;
    }
    string filename = argv[1];
    song s = song_open(filename);
    while (true)
    {
        string line = get_string("");
        if (line == NULL)
        {
            break;
        }
        if (is_rest(line))
        {
            rest_write(s, 1);
        }
        else
        {
            string note = strtok(line, "@");
            string fraction = strtok(NULL, "@");
            note_write(s, frequency(note), duration(fraction));
        }
    }
    song_close(s);
}