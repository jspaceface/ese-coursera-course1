#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

#define BASE_2 2
#define BASE_3 3
#define BASE_4 4
#define BASE_5 5
#define BASE_6 6
#define BASE_7 7
#define BASE_8 8
#define BASE_9 9
#define BASE_10 10
#define BASE_11 11
#define BASE_12 12
#define BASE_13 13
#define BASE_14 14
#define BASE_15 15
#define BASE_16 16

/**
 * For Course 1 Final
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * For Course 1 Final
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif