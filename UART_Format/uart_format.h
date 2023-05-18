
#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#include <stdio.h>

// [] format:  [___0000___]
// log

#define LOG_DEBUG_ENABLE (1U)

#if (LOG_DEBUG_ENABLE)

#define LOG_DEBUG_INFO(status, format, ...)                                    \
  do {                                                                         \
    printf("[   %s   ]"                                                        \
           "\t\t" format,                                                      \
           status, ##__VA_ARGS__);                                             \
    printf("\r\n");                                                            \
  } while (0)

#define LOG_DEBUG_NORMAL(format, ...)                                          \
  do {                                                                         \
    printf("\t\t\t" format, ##__VA_ARGS__);                                    \
    printf("\r\n");                                                            \
  } while (0)

#define LOG_DEBUG_LINE_LIGHT                                                   \
  do {                                                                         \
    printf(                                                                    \
        "[   ****   "                                                          \
        "]\t\t---------------------------------------------------------\r\n"); \
  } while (0);

#define LOG_DEBUG_LINE_HEAVY                                                   \
  do {                                                                         \
    printf(                                                                    \
        "[   ****   "                                                          \
        "]\t\t=========================================================\r\n"); \
  } while (0);

#define LOG_DEBUG_LINE_HEAVIEST                                                \
  do {                                                                         \
    printf(                                                                    \
        "[   ****   "                                                          \
        "]\t\t#########################################################\r\n"); \
  } while (0);

#else

#define LOG_DEBUG_INFO(status, format, ...)
#define LOG_DEBUG_NORMAL(format, ...)

#define LOG_DEBULOG_DEBUG_LINE_LIGHT
#define LOG_DEBUG_LINE_HEAVY
#define LOG_DEBUG_LINE_HEAVIEST

#endif /* LOG_DEBUG_ENABLE */

#define LOG_INFO(status, format, ...)                                          \
  do {                                                                         \
    printf("[   %s   ]"                                                        \
           "\t\t" format,                                                      \
           status, ##__VA_ARGS__);                                             \
    printf("\r\n");                                                            \
  } while (0)

#define LOG_NORMAL(format, ...)                                                \
  do {                                                                         \
    printf("\t\t\t" format, ##__VA_ARGS__);                                    \
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

#endif /* __bsp_usart_h__ */
