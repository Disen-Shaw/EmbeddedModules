#include <stdio.h>

// For printf
int fputc(int ch, FILE* f)
{
    HAL_UART_Transmit(&huart_n, (uint8_t*)&ch, 1, 0xFF);
    return (ch);
}

// for scanf
int fgetc(FILE* f)
{
    int ch;
    HAL_UART_Receive(&huart_n, (uint8_t*)&ch, 1, 1000);
    return (ch);
}
