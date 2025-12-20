//
// Created by r1skerss on 12/20/2025.
//

#ifndef UART_FRAME_PROTOCOL_H
#define UART_FRAME_PROTOCOL_H

#include "stdint.h"

#define PACKET_HEADER        0xAAAA
#define PACKET_TAIL          0x55

typedef struct __attribute__((packed)) {
    uint16_t header;      // Packet header
    uint32_t seq;     // Command identifier
    int16_t val1;
    int16_t val2;
    uint8_t checksum;    // Checksum for error detection
} Frame_t;

#endif //UART_PACKET_PROTOCOL_H