#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main() {

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(20001);  // VL_ID = 1
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *)&addr, sizeof(addr));// lier le prog à un port

    printf("Receiver waiting on UDP port 20001...\n");

    uint8_t buffer[2048];

    while (1) {
        int len = recv(sock, buffer, sizeof(buffer), 0);
        printf("Received %d bytes\n", len);
    }

    return 0;
}