/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2024-12-12 13:45:49
 * @Description: 外设配置和初始化
 */

#include "Init.h"

App_ChassisControl_TypeDef Akaman_Chassis;
Dev_MotorGA12_Typedef Motor_Left;
Dev_MotorGA12_Typedef Motor_Right;
Dev_EncoderN20_Typedef Encoder_Left;
Dev_EncoderN20_Typedef Encoder_Right;
Dev_Servo_TypeDef Servo_Front;
uint8_t RxBuffer[RX_BUFFER_LEN];

void Init_All(void)
{
    HAL_TIM_Base_Start_IT(&htim1);
    HAL_TIM_Base_Start_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim3);
    MotorGA12_Init(&Motor_Right, &Encoder_Right, &htim3, &htim1, TIM_CHANNEL_1, 7, 50, BIN1_GPIO_Port, BIN1_Pin, BIN2_GPIO_Port, BIN2_Pin);
    MotorGA12_Init(&Motor_Left, &Encoder_Left, &htim2, &htim1, TIM_CHANNEL_4, 7, 50, AIN1_GPIO_Port, AIN1_Pin, AIN2_GPIO_Port, AIN2_Pin);
    Servo_Init(&Servo_Front, &htim4, TIM_CHANNEL_4);
    HAL_UART_Receive_IT(&huart1, RxBuffer, RX_BUFFER_LEN);
    Chassis_Init(&Akaman_Chassis, 20.0f);
}
