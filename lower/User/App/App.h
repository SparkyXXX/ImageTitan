/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2024-12-12 13:36:19
 * @Description: 上层应用程序和中断处理函数
 */

#ifndef __APP_H__
#define __APP_H__

#include "main.h"

typedef struct
{
    int16_t vel_pulse;
    float servo_angle;
    float servo_angle_limit;
} App_ChassisControl_TypeDef;

extern App_ChassisControl_TypeDef Akaman_Chassis;

/**
 * @description: 主程序逻辑
 * @return {*}
 */
void Run_All(void);

/**
 * @description: 遥控任务
 * @return {*}
 */
void Remote_Control(void);

/**
 * @description: 底盘初始化，设置舵机角度限位
 * @param {float} servo_angle_limit
 * @return {*}
 */
void Chassis_Init(App_ChassisControl_TypeDef *chassis, float servo_angle_limit);

#endif /* __APP_H__ */
