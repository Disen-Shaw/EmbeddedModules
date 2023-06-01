#pragma once
#include <stdint.h>
#include <stdio.h>

void println_binary_bit16(uint16_t value);
void println_binary_bit32(uint32_t value);

#define LOG_DEBUG_USAGE (1)

typedef enum {
    LOG_TYPE_NORMAL = 0,
    LOG_TYPE_WARNING = 1,
    LOG_TYPE_ERROR = 2
} LOG_TYPE;

typedef enum {
    LOG_LINE_TYPE_LIGHT = 0,
    LOG_LINE_TYPE_HEAVY = 1,
    LOG_LINE_TYPE_HEAVIEST = 2,
} LOG_LINE_TYPE;

#if LOG_DEBUG_USAGE
#define LOG_DEBUG(type, format, ...)                         \
    do {                                                     \
        switch (type) {                                      \
        case LOG_TYPE_ERROR:                                 \
            printf("[   ERROR   ]\t" format, ##__VA_ARGS__); \
            printf("\r\n");                                  \
            break;                                           \
        case LOG_TYPE_WARNING:                               \
            printf("[  WARNING  ]\t" format, ##__VA_ARGS__); \
            printf("\r\n");                                  \
            break;                                           \
        case LOG_TYPE_NORMAL:                                \
            printf("\t\t" format, ##__VA_ARGS__);            \
            printf("\r\n");                                  \
            break;                                           \
        default:                                             \
            printf("\t\t" format, ##__VA_ARGS__);            \
            printf("\r\n");                                  \
            break;                                           \
        }                                                    \
    } while (0)

#define LOG_DEBUG_LINE(type)                                                                                 \
    do {                                                                                                     \
        switch (type) {                                                                                      \
        case LOG_LINE_TYPE_LIGHT:                                                                            \
            printf("[   *****   ]\t------------------------------------------------------------------\r\n"); \
            break;                                                                                           \
        case LOG_LINE_TYPE_HEAVY:                                                                            \
            printf("[   *****   ]\t******************************************************************\r\n"); \
            break;                                                                                           \
        case LOG_LINE_TYPE_HEAVIEST:                                                                         \
            printf("[   *****   ]\t##################################################################\r\n"); \
            break;                                                                                           \
        default:                                                                                             \
            printf("[   *****   ]\t------------------------------------------------------------------\r\n"); \
            break;                                                                                           \
        }                                                                                                    \
    } while (0)

#define LOG_DEBUG_BINARY_BIT16(value)      \
    do {                             \
        printf("\t\t");              \
        println_binary_bit16(value); \
    } while (0)

#define LOG_DEBUG_BINARY_BIT32(value)      \
    do {                             \
        printf("\t\t");              \
        println_binary_bit32(value); \
    } while (0)



#else
#define LOG_DEBUG(format, type, ...)
#define LOG_DEBUG_LINE(type)
#define LOG_DEBUG_BINARY_BIT16(value)
#define LOG_DEBUG_BINARY_BIT32(value)
#endif

#define LOG(type, format, ...)                               \
    do {                                                     \
        switch (type) {                                      \
        case LOG_TYPE_ERROR:                                 \
            printf("[   ERROR   ]\t" format, ##__VA_ARGS__); \
            printf("\r\n");                                  \
            break;                                           \
        case LOG_TYPE_WARNING:                               \
            printf("[  WARNING  ]\t" format, ##__VA_ARGS__); \
            printf("\r\n");                                  \
            break;                                           \
        case LOG_TYPE_NORMAL:                                \
            printf("\t\t" format, ##__VA_ARGS__);            \
            printf("\r\n");                                  \
            break;                                           \
        default:                                             \
            printf("\t\t" format, ##__VA_ARGS__);            \
            printf("\r\n");                                  \
            break;                                           \
        }                                                    \
    } while (0)

#define LOG_LINE(type)                                                                                       \
    do {                                                                                                     \
        switch (type) {                                                                                      \
        case LOG_LINE_TYPE_LIGHT:                                                                            \
            printf("[   *****   ]\t------------------------------------------------------------------\r\n"); \
            break;                                                                                           \
        case LOG_LINE_TYPE_HEAVY:                                                                            \
            printf("[   *****   ]\t******************************************************************\r\n"); \
            break;                                                                                           \
        case LOG_LINE_TYPE_HEAVIEST:                                                                         \
            printf("[   *****   ]\t##################################################################\r\n"); \
            break;                                                                                           \
        default:                                                                                             \
            printf("[   *****   ]\t------------------------------------------------------------------\r\n"); \
            break;                                                                                           \
        }                                                                                                    \
    } while (0)

#define LOG_BINARY_BIT16(value)      \
    do {                             \
        printf("\t\t");              \
        println_binary_bit16(value); \
    } while (0)

#define LOG_BINARY_BIT32(value)      \
    do {                             \
        printf("\t\t");              \
        println_binary_bit32(value); \
    } while (0)
