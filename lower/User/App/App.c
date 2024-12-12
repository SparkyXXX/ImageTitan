/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2024-12-12 13:53:52
 * @Description: 上层应用程序和中断处理函数
 */

#include "App.h"
#include "Init.h"
#include "tim.h"
#include "usart.h"
#include "util_buffer.h"

#define ONE_BUTTON 1
#define TWO_BUTTONS 2
#define CONTROL_MODE ONE_BUTTON

void Run_All(void)
{
    Remote_Control();
}

void Remote_Control(void)
{
    MotorGA12_GetRotateSpeed(&Motor_Left);
    MotorGA12_GetRotateSpeed(&Motor_Right);
    MotorGA12_SetPwmPulse(&Motor_Left, -(&Akaman_Chassis)->vel_pulse);
    MotorGA12_SetPwmPulse(&Motor_Right, -(&Akaman_Chassis)->vel_pulse);
    Servo_SetAngle(&Servo_Front, (&Akaman_Chassis)->servo_angle);
}

void Chassis_Init(App_ChassisControl_TypeDef *chassis, float servo_angle_limit)
{
    chassis->vel_pulse = 0;
    chassis->servo_angle = 0.0f;
    chassis->servo_angle_limit = servo_angle_limit;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim1)
    {
        if (Motor_Left.pencoder == NULL || Motor_Right.pencoder == NULL)
        {
            return;
        }
        (&Motor_Left)->pencoder->decode_flag = 1;
        (&Motor_Right)->pencoder->decode_flag = 1;
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart1)
    {
        uint8_t checksum = 0;
        for (int i = 1; i < RX_BUFFER_LEN - 2; i++)
        {
            checksum += RxBuffer[i];
        }
        checksum = checksum & 0xFF;

        if (RxBuffer[0] == 0xA5 && RxBuffer[RX_BUFFER_LEN - 1] == 0x5A && checksum == RxBuffer[RX_BUFFER_LEN - 2])
        {
            (&Akaman_Chassis)->vel_pulse = buff2i16(RxBuffer + 1);
			#if CONTROL_MODE == ONE_BUTTON
            (&Akaman_Chassis)->servo_angle = buff2float(RxBuffer + 5) / 900 * (&Akaman_Chassis)->servo_angle_limit; // 90为蓝牙调试助手中设置的值
			#endif
			#if CONTROL_MODE == TWO_BUTTONS
            (&Akaman_Chassis)->servo_angle = buff2float(RxBuffer + 5) / 90 * (&Akaman_Chassis)->servo_angle_limit; // 90为蓝牙调试助手中设置的值
			#endif
		}

        HAL_UART_Receive_IT(&huart1, RxBuffer, RX_BUFFER_LEN);
    }
}
