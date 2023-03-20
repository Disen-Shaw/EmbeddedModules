
#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#include <stdio.h>

// [] format:  [___0000___]
// log

#define LOG_PRINTF_ENABLE (1u)

#if (LOG_PRINTF_ENABLE)

#define LOG_ADVANCED(status, format, ...)                                      \
  do {                                                                         \
    printf("[   %s   ]"                                                        \
           "\t\t" format,                                                      \
           status, ##__va_args__);                                             \
    printf("\r\n");                                                            \
  } while (0)

#define LOG_NORMAL(format, ...)                                                \
  do {                                                                         \
    printf("\t\t\t" format, ##__va_args__);                                    \
    printf("\r\n");                                                            \
  } while (0)

#define LOG_LINE_LIGHT                                                         \
  do {                                                                         \
    printf(                                                                    \
        "[   ****   "                                                          \
        "]\t\t---------------------------------------------------------\r\n"); \
  } while (0);
#define LOG_LINE_HEAVY                                                         \
  do {                                                                         \
    printf(                                                                    \
        "[   ****   "                                                          \
        "]\t\t=========================================================\r\n"); \
  } while (0);
#define LOG_LINE_HEAVIEST                                                      \
  do {                                                                         \
    printf(                                                                    \
        "[   ****   "                                                          \
        "]\t\t#########################################################\r\n"); \
  } while (0);

#else

#define LOG_ADVANCED(status, format, ...)

#define LOG_NORMAL(format, ...)

#define LOG_LINE_LIGHT
#define LOG_LINE_HEAVY
#define LOG_LINE_HEAVIEST

#endif /* log_printf_enable */

#endif /* __bsp_usart_h__ */
