#ifndef UDP_H_
#define UDP_H_
#include <stdint.h>


typedef struct{
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t length;
    uint16_t checksum;
}__attribute__((packed)) udp_header_t;
#endif