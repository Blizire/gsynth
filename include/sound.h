#ifndef SOUND_H
#define SOUNG_H

#include "portaudio.h"

int patestCallback(const void *input,
                        void *output,
                        unsigned long frameCount,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags,
                        void *userData );

int PaPlaySound();

#endif