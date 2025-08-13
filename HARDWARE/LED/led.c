#include "stm32f10x.h"  // STM32标准库
#include "delay.h"      // 延时函数（需自行实现或使用HAL库）

// 定义LED引脚（PA4~PA7）
#define LED1_PIN    GPIO_Pin_4
#define LED2_PIN    GPIO_Pin_5
#define LED3_PIN    GPIO_Pin_6
#define LED4_PIN    GPIO_Pin_7
#define ALL_LED_PINS (LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN)

// 初始化LED（PA4~PA7）
void LED_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = ALL_LED_PINS;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    GPIO_SetBits(GPIOA, ALL_LED_PINS); // 默认关闭所有LED
}

// 单个LED控制
void LED1_ON(void)  { GPIO_ResetBits(GPIOA, LED1_PIN); }
void LED1_OFF(void) { GPIO_SetBits(GPIOA, LED1_PIN); }
void LED1_Toggle(void) { GPIOA->ODR ^= LED1_PIN; }

void LED2_ON(void)  { GPIO_ResetBits(GPIOA, LED2_PIN); }
void LED2_OFF(void) { GPIO_SetBits(GPIOA, LED2_PIN); }
void LED2_Toggle(void) { GPIOA->ODR ^= LED2_PIN; }

void LED3_ON(void)  { GPIO_ResetBits(GPIOA, LED3_PIN); }
void LED3_OFF(void) { GPIO_SetBits(GPIOA, LED3_PIN); }
void LED3_Toggle(void) { GPIOA->ODR ^= LED3_PIN; }

void LED4_ON(void)  { GPIO_ResetBits(GPIOA, LED4_PIN); }
void LED4_OFF(void) { GPIO_SetBits(GPIOA, LED4_PIN); }
void LED4_Toggle(void) { GPIOA->ODR ^= LED4_PIN; }

// 批量控制
void LED_All_ON(void)  { GPIO_ResetBits(GPIOA, ALL_LED_PINS); }
void LED_All_OFF(void) { GPIO_SetBits(GPIOA, ALL_LED_PINS); }
void LED_All_Toggle(void) { GPIOA->ODR ^= ALL_LED_PINS; }



