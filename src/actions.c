#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "playback.h"
#include "miniaudio/include/miniaudio.h"
#define MINIAUDIO_IMPLEMENTATION

void check_action(int argc, char *argv[]);
int play_song(char *song_file);
void pause_song(ma_device *device);
void loop_song(ma_decoder *decoder);
void restart_song(ma_decoder *decoder);
int add_to_playlist(int argc, char *argv[]);
char *get_filename_ext(const char *filename);
bool check_valid_song(char *filetype);

void check_action(int argc, char *argv[])
{
    char flag_indicator = '-';
    char *option = argv[1];
    
    if (flag_indicator == option[0])
    {
        if (strcmp(option, "-a") == 0 || strcmp(option, "--add") == 0)
        {
            add_to_playlist(argc, argv);
        }
    }
    else
    {
        printf("[p]ause - [l]oop - [r]estart - [q]uit\n");
        play_song(argv[1]);
    }
}

int play_song(char *song_file)
{
    char *filetype = get_filename_ext(song_file);

    if (check_valid_song(filetype) == true)
    {
        playback(song_file);
    }
    else
    {
        return 1;
    }
}

void pause_song(ma_device *device)
{
    if (ma_device_is_started(device) == true)
    {
        ma_device_stop(device);
    }
    else
    {
        ma_device_start(device);
    }
}

bool g_is_looping = false;
void loop_song(ma_decoder *decoder)
{
    g_is_looping = !g_is_looping;
    ma_data_source_set_looping(decoder, g_is_looping);
}

void restart_song(ma_decoder *decoder)
{
    ma_data_source_seek_to_pcm_frame(decoder, 0);
}


int add_to_playlist(int argc, char *argv[])
{
    char *output_file_extension = get_filename_ext(argv[argc - 1]);

    if (strcmp(output_file_extension, "m3u") == 0)
    {
        char *playlist_filename = argv[argc - 1];
        FILE *file_stream;

        file_stream = fopen(playlist_filename, "a");

        for (int i = 2; i < argc - 1; i++)
        {
            char *path = realpath(argv[i], NULL);
            fprintf(file_stream, "%s\n", path); 
        }
    }
    else {
        printf("Playlist file must be a '.m3u' file\n");
        return 1;
    }
     
}

char *get_filename_ext(const char *filename) {
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}


bool check_valid_song(char *filetype) {
    int wav_file = strcmp(filetype, "wav");
    int mp3_file = strcmp(filetype, "mp3");
    int flac_file = strcmp(filetype, "flac");

    if (wav_file == 0 || mp3_file == 0 || flac_file == 0)
    {
        return true;
    }
    else
    {
        printf("Incompatible file type\n");
        return false;
    }
}
