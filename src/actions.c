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
char *get_filename_ext(const char *filename);
bool check_valid_song(char *filetype);

void check_action(int argc, char *argv[])
{
    char flag_indicator = '-';
    char *option = argv[1];
    
    if (flag_indicator == option[0])
    {
    }
    else
    {
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
