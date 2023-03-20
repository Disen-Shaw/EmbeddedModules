
#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#include <stdio.h>

// [] format:  [___0000___]
// LOG

#define LOG_PRINTF_ENABLE (1U)

#if (LOG_PRINTF_ENABLE)

#define LOG_ADVANCED(status, format, ...) \
    do {                                  \
        printf("[   %s   ]"               \
               "\t\t" format,             \
            status, ##__VA_ARGS__);       \
        printf("\r\n");                   \
    } while (0)

#define LOG_NORMAL(format, ...)                 \
    do {                                        \
        printf("\t\t\t" format, ##__VA_ARGS__); \
        printf("\r\n");                         \
    } while (0)

#define LOG_LINE_LIGHT                                                                           \
    do {                                                                                         \
        printf("[   ****   ]\t\t---------------------------------------------------------\r\n"); \
    } while (0);
#define LOG_LINE_HEAVY                                                                           \
    do {                                                                                         \
        printf("[   ****   ]\t\t=========================================================\r\n"); \
    } while (0);
#define LOG_LINE_HEAVIEST                                                                        \
    do {                                                                                         \
        printf("[   ****   ]\t\t#########################################################\r\n"); \
    } while (0);

#else

#define LOG_ADVANCED(status, format, ...)

#define LOG_NORMAL(format, ...)

#define LOG_LINE_LIGHT
#define LOG_LINE_HEAVY
#define LOG_LINE_HEAVIEST

#endif /* LOG_PRINTF_ENABLE */


#endif /* __BSP_USART_H__ */
