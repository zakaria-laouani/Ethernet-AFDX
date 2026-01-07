#ifndef ETHERNET_H_
#define ETHERNET_H_

#include <stdint.h>

#define ethernet_tp_ip 0x0800
typedef struct {
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint16_t ethe_tp_ip;
}__attribute__((packed)) ethernet_head ; // pour éviter que le compilateur ajoute de pading
//
#endif 