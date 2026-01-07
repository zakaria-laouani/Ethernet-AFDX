#include "afdx.h"
#include "udp.h"
#include "ip.h"
#include "ethernet.h"
#include <string.h>

uint16_t swap16(uint16_t x){
    return (x<<8 | x>>8);
}
uint32_t swap32(uint32_t x){
    return (((x<<24)&0xFF000000)|
            ((x<<8)&0x00FF0000) |
            ((x>>8)&0x0000FF00) |
            ((x>>24)&0x000000FF));
}

int build_afdx_trame(uint8_t * buffer, afdx_payload_t* payload ){
    int index = 0;
    // construction de ethernet 
    ethernet_head eth = {
        .dst_mac = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF},
        .src_mac = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60},
        .ethe_tp_ip = swap16(ethernet_tp_ip)
    };
    // copier le header dans le buffer
    memcpy(buffer + index, &eth, sizeof(ethernet_head));
    index += sizeof(ethernet_head);

    ip_header_t ip ={
        .type_ver = 0x45,
        .service_ip = 0,
        .totale_lengh = swap16(sizeof(ip_header_t) + sizeof(udp_header_t) + payload->payload_size),
        .identification = 0,
        .flag_position_fragement = 0,
        .ttl = 64, 
        .protocole = 0x17,
        .checksum = 0,
        .src_ip = swap32(0x0A000001), //10.0.0.1
        .dst_ip = swap32(0x0A000002)
    };
    //clacul de checksum ;
    
    memcpy(buffer + index, &ip, sizeof(ip));
    index += sizeof(ip);


    udp_header_t udp = {
        .src_port = swap16(10000 + payload->vl_id),
        .dst_port = swap16(20000 + payload->vl_id),
        .length = swap16(sizeof(udp_header_t) + payload->payload_size),
        .checksum = 0
    };

    memcpy(buffer + index, &udp, sizeof(udp));
    index += sizeof(udp);

    memcpy(buffer + index, payload->payload, payload->payload_size);
    index += payload->payload_size;
    return index ;
}