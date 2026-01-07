#include "afdx.h"
#include <stdio.h>

int build_afdx_trame(uint8_t * buffer, afdx_payload_t* payload );

int main(){

    uint8_t buffer[2048];
    afdx_payload_t pl = {
        .payload_size = 20,
        .vl_id = 3
    };
    for(int i = 0; i < pl.payload_size; i++){
        pl.payload[i] = i;
    }

    int size  = build_afdx_trame(buffer, &pl);
    printf(" trame constuit de taille %d \n", size);
    for(int i = 0; i < size ; i++){
        printf("%02x", buffer[i]);

    }
    printf("\n");
    return 0;

}