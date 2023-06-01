#include "log.h"

void println_binary_bit16(uint16_t value)
{
    int i = 0;
    for (i = 0; i < 16; i++) {

        if (value & (0x01 << (15 - i)))
            printf("1");
        else
            printf("0");

        if ((i + 1) % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}


void println_binary_bit32(uint32_t value)
{
    int i = 0;
    for (i = 0; i < 32; i++) {

        if (value & (0x01 << (31 - i)))
            printf("1");
        else
            printf("0");

        if ((i + 1) % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

