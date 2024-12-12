/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2024-12-12 13:44:49
 * @Description: 外设配置和初始化
 */

#ifndef __INIT_H__
#define __INIT_H__

#include "App.h"
#include "dev_ga12n20.h"
#include "dev_servo.h"
#include "tim.h"
#include "usart.h"

#define RX_BUFFER_LEN 11

extern App_ChassisControl_TypeDef Akaman_Chassis;
extern Dev_MotorGA12_Typedef Motor_Left;
extern Dev_MotorGA12_Typedef Motor_Right;
extern Dev_EncoderN20_Typedef Encoder_Left;
extern Dev_EncoderN20_Typedef Encoder_Right;
extern Dev_Servo_TypeDef Servo_Front;
extern uint8_t RxBuffer[RX_BUFFER_LEN];

/**
 * @description: 初始化所有外设
 * @return {*}
 */
void Init_All(void);

#endif /* __INIT_H__ */
