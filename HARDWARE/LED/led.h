#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"
#include <stdint.h>

/* LED引脚定义 (PA4-PA7) */
#define LED1_PIN    GPIO_Pin_4
#define LED2_PIN    GPIO_Pin_5
#define LED3_PIN    GPIO_Pin_6
#define LED4_PIN    GPIO_Pin_7
#define ALL_LED_PINS (LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN)

/* 初始化函数 */
void LED_Init(void);

/* 单灯控制函数 */
void LED1_ON(void);
void LED1_OFF(void);
void LED1_Toggle(void);

void LED2_ON(void);
void LED2_OFF(void);
void LED2_Toggle(void);

void LED3_ON(void);
void LED3_OFF(void);
void LED3_Toggle(void);

void LED4_ON(void);
void LED4_OFF(void);
void LED4_Toggle(void);

/* 批量控制函数 */
void LED_All_ON(void);
void LED_All_OFF(void);
void LED_All_Toggle(void);

/* 特效函数 */
void LED_Blink(uint16_t LED_PIN, uint32_t delay_ms);
void LED_RunningLight(uint32_t delay_ms);

#endif /* __LED_H */
