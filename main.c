#include <stdio.h>

#include "spd.h"

int main(int argc, char* argv[]) {

    // make sure it's only one argument 

    if (argc != 2) {
        printf("invalid arguments\n");
        return 0;
    }

    char* filepath = argv[1];
    audio_data_t data = read_audio_file(filepath);

    printf("sample rate: %i\n", data.sample_rate);
    printf("bitrate: %i\n", data.bitrate);
    printf("has metadata: %s\n", data.has_metadata ? "true" : "false");

    if (valid_spd(data)) {
        printf("yup it's valid\n");
    } else {
        printf("nah it ain't\n");
    }
    
    return 0;
}