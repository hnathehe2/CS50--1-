#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"
#include "wav.h"

const string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#", "A", "A#", "B"
                       };


#define OCTAVE 4

int main(int argc, string argv[])
{
    int octave = OCTAVE;
    if (argc == 2)
    {
        octave = atoi(argv[1]);
        if (octave < 0 || octave > 8)
        {
            fprintf(stderr, "Invalid octave\n");
            return 1;
        }
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Usage: notes [OCTAVE]\n");
        return 1;
    }
    song s = song_open("notes.wav");
    for (int i = 0, n = sizeof(NOTES) / sizeof(string); i < n; i++)
    {
        char note[4];
        sprintf(note, "%s%i", NOTES[i], octave);
        int f = frequency(note);
        printf("%3s: %i\n", note, f);
        note_write(s, f, 1);
    }
    song_close(s);
}