#include <string.h>
#include <math.h> 
#include "wavetables.h"
#include "fmc.h" 

MMSample *WaveTable;

MMSample sramWaveTable[SHORT_WAVTABLE_LENGTH_SAMPLES];

MMSample WaveTable_midiNumber(void)
{
    return 12. * log2(CODEC_SAMPLE_RATE / (WAVTABLE_LENGTH_SAMPLES * 440.0)) + 69.;
}

void WaveTable_init(void)
{
    WaveTable = (MMSample*)SDRAM_BANK_ADDR;
}

void WaveTable_init_sram(void)
{
    WaveTable = sramWaveTable;
}

void WaveTable_init_sin(size_t length)
{
    WaveTable_init();
    size_t i,j;
    memset(WaveTable,0,sizeof(MMSample) * length);
    for (i = 0; i < length; i++) {
        for (j = 0; j < WAVTABLE_NUM_PARTIALS; j++) {
            WaveTable[i] += sin((MMSample)i / (MMSample)length 
                    * (j + 1) * M_PI * 2.) / (MMSample)(j + 1);
        }
    }
}
