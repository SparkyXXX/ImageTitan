/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2025-01-19 16:45:45
 * @Description: 上层应用程序和中断处理函数
 */

#ifndef __APP_H__
#define __APP_H__

#include "dev_ga12n20.h"
#include "dev_servo.h"

#define RX_BUFFER_LEN 11

typedef struct
{
    uint8_t header; // 包头 0xA5
    float vel;    // 速度
    float ang;      // 角度
    uint8_t flags;  // 标志字节 (pc_flag, img_flag, control_mode)
    uint8_t footer; // 包尾 0x5A
    uint8_t pc_flag;
    uint8_t img_flag;
    uint8_t control_mode;
} App_DataPacket_TypeDef;

extern App_DataPacket_TypeDef DataPacket;
extern uint8_t RxBuffer[RX_BUFFER_LEN];
extern Dev_MotorGA12_Typedef Motor;
extern Dev_Servo_TypeDef Servo_Front;
extern Dev_Servo_TypeDef Servo_Back;

/**
 * @description: 外设初始化
 * @return {*}
 */
void Init_All(void);

/**
 * @description: 主程序逻辑
 * @return {*}
 */
void Run_All(void);

/**
 * @description: 单元测试
 * @return {*}
 */
void Test_All(void);

void RX_Decode(void);

#endif /* __APP_H__ */
