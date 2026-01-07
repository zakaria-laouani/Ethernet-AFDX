#ifndef AFDX_H_
#define AFDX_H_
#include <stdint.h>
#define AFDX_PAYLOAD_MAX 256 


typedef struct {
    uint8_t payload[AFDX_PAYLOAD_MAX]; // la charge utile
    uint16_t payload_size;
    uint16_t vl_id;
} afdx_payload_t;
#endif