
#ifndef __UART_FORMAT_H__
#define __UART_FORMAT_H__


#include <stdio.h>

#define 	LOG_ADVANCED(status ,format, ...) 	do { printf("[   %s   ]" \
											"\t\t" \
											format,status,  ##__VA_ARGS__); \
											printf("\r\n"); \
											} while(0)

#define 	LOG_NORMAL(format,...)		do { printf("\t\t\t" \
											format,##__VA_ARGS__); \
											printf("\r\n"); \
											} while(0)

											
#define 	LOG_LINE_LIGHT				do { printf("[   ****   ]\t\t---------------------------------------------------------\r\n"); } while(0);
#define 	LOG_LINE_HEAVY				do { printf("[   ****   ]\t\t=========================================================\r\n"); } while(0);
#define 	LOG_LINE_HEAVIEST			do { printf("[   ****   ]\t\t#########################################################\r\n"); } while(0);


#endif /* __UART_FORMAT_H__ */

