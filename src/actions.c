#include <stdbool.h>
#include "miniaudio/include/miniaudio.h"
#define MINIAUDIO_IMPLEMENTATION

bool g_is_looping = false;
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

void loop_song(ma_decoder *decoder)
{
    g_is_looping = !g_is_looping;
    ma_data_source_set_looping(decoder, g_is_looping);
}
