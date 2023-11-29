#include <miniaudio/include/miniaudio.h>
#include <stdbool.h>
#define MINIAUDIO_IMPLEMENTATION

void pause_song(ma_device *device);
void loop_song(ma_decoder *decoder);
void restart_song(ma_decoder *decoder);
