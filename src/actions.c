#include <stdbool.h>
#include <stdio.h>
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
    char *song_file_extension = get_filename_ext(song_file);

    int wav_file = strcmp(song_file_extension, "wav");
    int mp3_file = strcmp(song_file_extension, "mp3");
    int flac_file = strcmp(song_file_extension, "flac");

    if (wav_file == 0 || mp3_file == 0 || flac_file == 0)
    {
        playback(song_file);
    }
    else
    {
        printf("Incompatible file type\n");
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

