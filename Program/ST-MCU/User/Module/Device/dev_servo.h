/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2024-12-12 11:05:52
 * @Description: PWM舵机驱动
 */

#ifndef __DEV_SERVO_H__
#define __DEV_SERVO_H__

#include "tim.h"

typedef struct
{
    TIM_HandleTypeDef *htim;
    uint32_t ch;
    float angle;
} Dev_Servo_TypeDef;

/**
 * @description: 根据CubeMX配置进行初始化
 * @param {Dev_Servo_TypeDef} *servo
 * @param {TIM_HandleTypeDef} *htim
 * @param {uint32_t} ch
 * @param {uint32_t} clk
 * @param {float} angle
 * @return {*}
 */
void Servo_Init(Dev_Servo_TypeDef *servo, TIM_HandleTypeDef *htim, uint32_t ch);

/**
 * @description: 获取舵机角度
 * @param {Dev_Servo_TypeDef} *servo
 * @return {*}
 */
float Servo_GetAngle(Dev_Servo_TypeDef *servo);

/**
 * @description: 设定舵机角度（默认定时器的ARR为1000，将2.5%~12.5%的占空比映射到-90°~90°的角度）；注意在调用逻辑中对角度进行限幅
 * @param {Dev_Servo_TypeDef} *servo
 * @param {float} angle
 * @return {*}
 */
void Servo_SetAngle(Dev_Servo_TypeDef *servo, float angle);

#endif /* __DEV_SERVO_H__ */