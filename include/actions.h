#include <miniaudio/include/miniaudio.h>
#include <stdbool.h>
#define MINIAUDIO_IMPLEMENTATION

void check_action(int argc, char *arguments[]);
int play_song(char *song_file);
void pause_song(ma_device *device);
void loop_song(ma_decoder *decoder);
void restart_song(ma_decoder *decoder);
void read_playlist(char *path);
void read_folder(char *path);
const char *get_filename_ext(const char *filename);
int add_to_playlist(int argc, char argv[]);
