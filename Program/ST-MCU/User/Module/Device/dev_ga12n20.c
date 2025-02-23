/*
 * @Author: Hatrix 3113624526@qq.com
 * @LastEditTime: 2025-01-17 16:06:00
 * @Description: GA12N20带编码器减速电机TB6612FNG驱动
 */

#include "dev_ga12n20.h"
#include "stdlib.h"

void MotorGA12_Init(Dev_MotorGA12_Typedef *pmotor, TIM_HandleTypeDef *pwm_htim, uint32_t pwm_ch,
                    GPIO_TypeDef *in1_port, uint16_t in1_pin, GPIO_TypeDef *in2_port, uint16_t in2_pin)
{
    pmotor->pwm_htim = pwm_htim;
    pmotor->pwm_ch = pwm_ch;
    pmotor->in1_port = in1_port;
    pmotor->in1_pin = in1_pin;
    pmotor->in2_port = in2_port;
    pmotor->in2_pin = in2_pin;
    HAL_TIM_PWM_Start(pmotor->pwm_htim, pmotor->pwm_ch);
}

float MotorGA12_GetRotateSpeed(Dev_EncoderN20_Typedef *pencoder)
{
	float rotate_speed = 0.0f;
    if (pencoder->decode_flag)
    {
        pencoder->cnt = __HAL_TIM_GET_COUNTER(pencoder->enc_htim);
        pencoder->tick = HAL_GetTick();
        pencoder->delta_cnt = pencoder->cnt - pencoder->last_cnt;
        if (pencoder->delta_cnt > 32768)
        {
            pencoder->delta_cnt -= 65535;
        }
        else if (pencoder->delta_cnt < -32768)
        {
            pencoder->delta_cnt += 65535;
        }
        rotate_speed = (float)pencoder->delta_cnt * 1000 / 4 / pencoder->enc_lines / (pencoder->tick - pencoder->last_tick);
        pencoder->last_cnt = pencoder->cnt;
        pencoder->last_tick = pencoder->tick;
        pencoder->decode_flag = 0;
    }
	return rotate_speed;
}

void MotorGA12_SetPwmPulse(Dev_MotorGA12_Typedef *pmotor, int16_t pulse)
{
    HAL_GPIO_WritePin(pmotor->in1_port, pmotor->in1_pin, (pulse > 0) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pmotor->in2_port, pmotor->in2_pin, (pulse < 0) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    __HAL_TIM_SET_COMPARE(pmotor->pwm_htim, pmotor->pwm_ch, (pulse == 0) ? 0 : abs(pulse));
}
