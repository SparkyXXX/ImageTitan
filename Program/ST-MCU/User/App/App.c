/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2025-01-19 17:44:30
 * @Description: 上层应用程序和中断处理函数
 */

#include "App.h"
#include "usart.h"
#include "util_buffer.h"

App_DataPacket_TypeDef DataPacket;
uint8_t RxBuffer[RX_BUFFER_LEN];
Dev_MotorGA12_Typedef Motor;
Dev_Servo_TypeDef Servo_Front;
Dev_Servo_TypeDef Servo_Back;

void Init_All(void)
{
    MotorGA12_Init(&Motor, &htim1, TIM_CHANNEL_4, AIN1_GPIO_Port, AIN1_Pin, AIN2_GPIO_Port, AIN2_Pin);
    Servo_Init(&Servo_Front, &htim3, TIM_CHANNEL_1);
    Servo_Init(&Servo_Back, &htim3, TIM_CHANNEL_2);
    HAL_UART_Receive_IT(&huart1, RxBuffer, RX_BUFFER_LEN);
	MotorGA12_SetPwmPulse(&Motor, 0);
    Servo_SetAngle(&Servo_Front, 50.0f);
    Servo_SetAngle(&Servo_Back, 50.0f);
}

float turn_ang = 0.0f;
int16_t go_vel = 0;
void Run_All(void)
{
//    RX_Decode();
//    DataPacket.pc_flag == 1 ? HAL_GPIO_WritePin(PC_GPIO_Port, PC_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(PC_GPIO_Port, PC_Pin, GPIO_PIN_RESET);
//    DataPacket.img_flag == 1 ? HAL_GPIO_WritePin(IMG_GPIO_Port, IMG_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(IMG_GPIO_Port, IMG_Pin, GPIO_PIN_RESET);
//	go_vel = DataPacket.vel * 1000;
//	turn_ang = DataPacket.ang * 50 + 50;
//	MotorGA12_SetPwmPulse(&Motor, go_vel);
//    Servo_SetAngle(&Servo_Front, turn_ang);
//    Servo_SetAngle(&Servo_Back, 100 - turn_ang);
	Test_All();
}

float test_ang_front = 50.0f;
float test_ang_back = 50.0f;
int16_t test_pulse = 0;
void Test_All(void)
{
    MotorGA12_SetPwmPulse(&Motor, 1200);
	HAL_Delay(1000);
	MotorGA12_SetPwmPulse(&Motor, -1200);
	HAL_Delay(1000);
//    Servo_SetAngle(&Servo_Front, test_ang_front);
//    Servo_SetAngle(&Servo_Back, test_ang_back);
}

void RX_Decode()
{
    DataPacket.header = RxBuffer[0];
    DataPacket.footer = RxBuffer[10];
    if ((DataPacket.header == 0xA5) && (DataPacket.footer == 0x5A))
    {
        DataPacket.vel = buff2float(RxBuffer + 1);
        DataPacket.ang = buff2float(RxBuffer + 5);
        DataPacket.flags = RxBuffer[9];
        DataPacket.pc_flag = (DataPacket.flags >> 7) & 0x01;
        DataPacket.img_flag = (DataPacket.flags >> 6) & 0x01;
        DataPacket.control_mode = (DataPacket.flags >> 5) & 0x01;
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart1)
    {
        HAL_UART_Receive_IT(&huart1, RxBuffer, RX_BUFFER_LEN);
    }
}
