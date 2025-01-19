/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2024-12-12 01:38:47
 * @Description: 数据格式转化
 */

#ifndef __UTIL_BUFFER_H__
#define __UTIL_BUFFER_H__

#include "main.h"
#include "string.h"

float buff2float(uint8_t *buff);
void float2buff(float f, uint8_t *buff);
int16_t buff2i16(uint8_t *buff);
void i162buff(int16_t u, uint8_t *buff);
uint16_t buff2ui16(uint8_t *buff);
void ui162buff(uint16_t u, uint8_t *buff);
uint32_t buff2ui32(uint8_t *buff);
void ui322buff(uint32_t u, uint8_t *buff);
int32_t buff2i32(uint8_t *buff);
void i322buff(int32_t u, uint8_t *buff);

#endif /* __UTIL_BUFFER_H__ */
