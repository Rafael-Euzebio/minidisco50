#include <stdbool.h>
#include "miniaudio/include/miniaudio.h"
#define MINIAUDIO_IMPLEMENTATION

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
