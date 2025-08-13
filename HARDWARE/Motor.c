#include "stm32f10x.h"
#include "Delay.h"
#include "PWM.h"
#include "usart.h"



 // 电机引脚定义
#define MOTOR1_IN1  GPIO_Pin_5  // PB5 (电机1方向控制1)
#define MOTOR1_IN2  GPIO_Pin_6  // PB6 (电机1方向控制2)
#define MOTOR2_IN3  GPIO_Pin_7  // PB7 (电机2方向控制1)
#define MOTOR2_IN4  GPIO_Pin_8  // PB8 (电机2方向控制2)
 
 
void MOTOR_GPIO_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;  //依次接L298N  IN1,IN2,IN3,IN4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// 初始化电机停止状态
  //Car_Stop();
	
}	
 
/*
	函数功能：控制两个电机的速度和正反转
	参数说明：
		PWM1、PWM2
		范围：-7200到7200
		参数正负不同表示电机不同的转向
*/
// 前进（两电机正转）
void Car_Forward(void) {
	  printf ( "\r\n  Car_Forward() ......\r\n" );
    GPIO_SetBits(GPIOB, MOTOR1_IN1);    // 电机1正转
    GPIO_ResetBits(GPIOB, MOTOR1_IN2);
    GPIO_SetBits(GPIOB, MOTOR2_IN3);    // 电机2正转
    GPIO_ResetBits(GPIOB, MOTOR2_IN4);
}

// 后退（两电机反转）
void Car_Backward(void) {
	printf ( "\r\n  Car_Backward() ......\r\n" );
    GPIO_ResetBits(GPIOB, MOTOR1_IN1);  // 电机1反转
    GPIO_SetBits(GPIOB, MOTOR1_IN2);
    GPIO_ResetBits(GPIOB, MOTOR2_IN3);  // 电机2反转
    GPIO_SetBits(GPIOB, MOTOR2_IN4);
}

// 左转（电机1停/反转，电机2正转）
void Car_TurnLeft(void) {
	printf ( "\r\n  Car_TurnLeft() ......\r\n" );
    GPIO_ResetBits(GPIOB, MOTOR1_IN1);  // 电机1停或反转（根据需求调整）
    GPIO_ResetBits(GPIOB, MOTOR1_IN2);
    GPIO_SetBits(GPIOB, MOTOR2_IN3);    // 电机2正转
    GPIO_ResetBits(GPIOB, MOTOR2_IN4);
}

// 右转（电机1正转，电机2停/反转）
void Car_TurnRight(void) {
	printf ( "\r\n  Car_TurnRight() ......\r\n" );
    GPIO_SetBits(GPIOB, MOTOR1_IN1);     // 电机1正转
    GPIO_ResetBits(GPIOB, MOTOR1_IN2);
    GPIO_ResetBits(GPIOB, MOTOR2_IN3);  // 电机2停或反转（根据需求调整）
    GPIO_ResetBits(GPIOB, MOTOR2_IN4);
}

// 停止（两电机刹车）
void Car_Stop(void) {
	printf ( "\r\n  Car_Stop() ......\r\n" );
    GPIO_SetBits(GPIOB, MOTOR1_IN1 | MOTOR1_IN2);  // 电机1刹车
    GPIO_SetBits(GPIOB, MOTOR2_IN3 | MOTOR2_IN4);  // 电机2刹车
}
