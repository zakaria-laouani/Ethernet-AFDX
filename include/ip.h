#ifndef IP_H_
#define IP_H_
#include <stdint.h>


typedef struct {
    uint8_t type_ver;
    uint8_t service_ip;
    uint16_t totale_lengh;
    uint16_t identification;
    uint16_t flag_position_fragement;
    uint8_t ttl; // la duré de vie maximale du paquet en sec
    uint8_t protocole; // udp, tcp, 
    uint16_t checksum;
    uint32_t src_ip;
    uint32_t dst_ip;
}__attribute__((packed)) ip_header_t;

#endif