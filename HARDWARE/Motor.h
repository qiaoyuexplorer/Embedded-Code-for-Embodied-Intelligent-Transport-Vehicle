#ifndef __MOTOR_H
#define __MOTOR_H

void MOTOR_GPIO_Init(void);

// 基础运动控制函数
void Car_Forward(void);   // 前进
void Car_Backward(void);  // 后退
void Car_TurnLeft(void);  // 左转
void Car_TurnRight(void); // 右转
void Car_Stop(void);      // 停止


#endif

