#include "afdx.h"
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int build_afdx_trame(uint8_t * buffer, afdx_payload_t* payload );

int main(){

    uint8_t buffer[2048];
    afdx_payload_t pl;
    strcpy((char*)pl.payload, "Hi afdx from Zak");
    pl.payload_size = strlen((char*) pl.payload);
    pl.vl_id = 1;

    int frame_size  = build_afdx_trame(buffer, &pl);
    printf(" trame constuit de taille %d \n", frame_size);

    //*******socket udp**//
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(20000 + pl.vl_id);
    sendto(sock, buffer, frame_size, 0,
           (struct sockaddr*)&addr, sizeof(addr));

    printf("Frame sent !\n");

    close(sock);
    return 0;
}