/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2024-12-12 13:31:30
 * @Description: PWM舵机驱动
 */

#include "dev_servo.h"

void Servo_Init(Dev_Servo_TypeDef *servo, TIM_HandleTypeDef *htim, uint32_t ch)
{
    servo->htim = htim;
    servo->ch = ch;
    HAL_TIM_PWM_Start(servo->htim, servo->ch);
    Servo_SetAngle(servo, 0.0f);
}

float Servo_GetAngle(Dev_Servo_TypeDef *servo)
{
    return servo->angle;
}

void Servo_SetAngle(Dev_Servo_TypeDef *servo, float angle)
{
    servo->angle = angle;
    int16_t pulse = (int16_t)((angle + 90) / 180 * 100 + 25);
    __HAL_TIM_SET_COMPARE(servo->htim, servo->ch, pulse);
}
