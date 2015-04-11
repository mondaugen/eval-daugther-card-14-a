#ifndef WAVETABLES_H
#define WAVETABLES_H 
#include <stddef.h>
#include "mm_sample.h" 
#include "i2s_setup.h"

#define WAVTABLE_LENGTH_SAMPLES (1000000)//(8192) 
#define SHORT_WAVTABLE_LENGTH_SAMPLES 4096 

#define WAVTABLE_FREQ ((MMSample)CODEC_SAMPLE_RATE / (MMSample)WAVTABLE_LENGTH_SAMPLES)

#define WAVTABLE_NUM_PARTIALS   1

extern MMSample *WaveTable;

MMSample WaveTable_midiNumber(void);
void WaveTable_init(void);
void WaveTable_init_sin(size_t length);

#endif /* WAVETABLES_H */
