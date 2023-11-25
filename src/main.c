#include <stdio.h>
#include "play_song.h"

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: [Path]\n");
        return 1;
    }
    else {
        play_song(argv[1]);
    }
}
