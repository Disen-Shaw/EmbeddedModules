
#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */

uint16_t bsp_crc_calculate(uint8_t *data, uint32_t length);


#ifdef __cplusplus
}
#endif /* cplusplus */

#endif /* __CRC_H__ */

