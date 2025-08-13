#include "stm32f10x.h"
#include "Delay.h"
#include "PWM.h"
#include "usart.h"



 // ������Ŷ���
#define MOTOR1_IN1  GPIO_Pin_5  // PB5 (���1�������1)
#define MOTOR1_IN2  GPIO_Pin_6  // PB6 (���1�������2)
#define MOTOR2_IN3  GPIO_Pin_7  // PB7 (���2�������1)
#define MOTOR2_IN4  GPIO_Pin_8  // PB8 (���2�������2)
 
 
void MOTOR_GPIO_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;  //���ν�L298N  IN1,IN2,IN3,IN4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// ��ʼ�����ֹͣ״̬
  //Car_Stop();
	
}	
 
/*
	�������ܣ���������������ٶȺ�����ת
	����˵����
		PWM1��PWM2
		��Χ��-7200��7200
		����������ͬ��ʾ�����ͬ��ת��
*/
// ǰ�����������ת��
void Car_Forward(void) {
	  printf ( "\r\n  Car_Forward() ......\r\n" );
    GPIO_SetBits(GPIOB, MOTOR1_IN1);    // ���1��ת
    GPIO_ResetBits(GPIOB, MOTOR1_IN2);
    GPIO_SetBits(GPIOB, MOTOR2_IN3);    // ���2��ת
    GPIO_ResetBits(GPIOB, MOTOR2_IN4);
}

// ���ˣ��������ת��
void Car_Backward(void) {
	printf ( "\r\n  Car_Backward() ......\r\n" );
    GPIO_ResetBits(GPIOB, MOTOR1_IN1);  // ���1��ת
    GPIO_SetBits(GPIOB, MOTOR1_IN2);
    GPIO_ResetBits(GPIOB, MOTOR2_IN3);  // ���2��ת
    GPIO_SetBits(GPIOB, MOTOR2_IN4);
}

// ��ת�����1ͣ/��ת�����2��ת��
void Car_TurnLeft(void) {
	printf ( "\r\n  Car_TurnLeft() ......\r\n" );
    GPIO_ResetBits(GPIOB, MOTOR1_IN1);  // ���1ͣ��ת���������������
    GPIO_ResetBits(GPIOB, MOTOR1_IN2);
    GPIO_SetBits(GPIOB, MOTOR2_IN3);    // ���2��ת
    GPIO_ResetBits(GPIOB, MOTOR2_IN4);
}

// ��ת�����1��ת�����2ͣ/��ת��
void Car_TurnRight(void) {
	printf ( "\r\n  Car_TurnRight() ......\r\n" );
    GPIO_SetBits(GPIOB, MOTOR1_IN1);     // ���1��ת
    GPIO_ResetBits(GPIOB, MOTOR1_IN2);
    GPIO_ResetBits(GPIOB, MOTOR2_IN3);  // ���2ͣ��ת���������������
    GPIO_ResetBits(GPIOB, MOTOR2_IN4);
}

// ֹͣ�������ɲ����
void Car_Stop(void) {
	printf ( "\r\n  Car_Stop() ......\r\n" );
    GPIO_SetBits(GPIOB, MOTOR1_IN1 | MOTOR1_IN2);  // ���1ɲ��
    GPIO_SetBits(GPIOB, MOTOR2_IN3 | MOTOR2_IN4);  // ���2ɲ��
}
