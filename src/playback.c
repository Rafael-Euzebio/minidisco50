#include <stdio.h>
#include <stdlib.h>
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/include/miniaudio.h"
#include "input.h"
#include "actions.h"

bool g_reached_end = false;

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) {
        return;
    }

    if (ma_data_source_read_pcm_frames(pDecoder, pOutput, frameCount, NULL) > frameCount)
    {
        g_reached_end = true;
    }

    (void)pInput;
}

int playback(char *path)
{
    ma_result result;
    ma_decoder decoder;
    ma_device_config deviceConfig;
    ma_device device;

    result = ma_decoder_init_file(path, NULL, &decoder);
    if (result != MA_SUCCESS) {
        return -2;
    }

    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate        = decoder.outputSampleRate;
    deviceConfig.dataCallback      = data_callback;
    deviceConfig.pUserData         = &decoder;

    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        ma_decoder_uninit(&decoder);
        return -3;
    }

    if (ma_device_start(&device) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        return -4;
    }

    while(1)
    {
        char pressed = check_key_pressed();
        
        switch (pressed) {

            case 'p':
                pause_song(&device);
                break;

            case 'r':
                restart_song(&decoder);
                break;

            case 'n':
                ma_decoder_uninit(&decoder);
                ma_device_uninit(&device);
                return 0;

            case 'l':
                loop_song(&decoder);
                break;

            case 'q':
                exit(EXIT_SUCCESS);

        }

        if(g_reached_end == true)
        {
            ma_device_uninit(&device);
            ma_decoder_uninit(&decoder);
            g_reached_end = false;
            return 0;
        }
    }
}

