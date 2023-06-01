#include <stdint.h>

#include "alg.h"

/**
 * @brief 均值滤波算法
 *
 * @param data 数据 buffer 首地址
 * @param from_index 起始索引
 * @param to_index 结束索引
 *
 * @return 计算得出的均值
 */
float app_alg_average(uint16_t* data, uint32_t from_index, uint32_t to_index)
{
    uint64_t sum = 0;
    uint32_t i;
    if (from_index <= to_index) {
        for (i = from_index; i <= to_index; i++) {
            sum += data[i];
        }
        return sum / (float)(to_index - from_index + 1);
    } else {
        return -1.0F;
    }
}

/**
 * @brief 冒泡排序算法
 *
 * @param buffer 数据 buffer 首地址
 * @param len 排序数据长度
 * @param data_type 排序数据类型
 *   @case 0: uint8_t   8   位无符号
 *   @case 1: int8_t    8   位有符号
 *   @case 2: uint16_t  16  位无符号
 *   @case 3: int16_t   16  位有符号
 *   @case 4: uint32_t  32  位无符号
 *   @case 5: int32_t   32  位有无符号
 *   @case 6: float
 *   @case 7: double
 */
void app_alg_sort(void* buffer, uint32_t len, uint8_t data_type)
{
}
