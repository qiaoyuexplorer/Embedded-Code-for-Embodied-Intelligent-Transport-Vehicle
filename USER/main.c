#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "esp8266.h"
#include "Servo.h"
#include <s2f.h> 
#include "Motor.h"
#include "PWM.h"

uint8_t flag;

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  SystemInit();//??????????72M	
	USART_Config();
	printf ( "\r\n  USART_Config ......\r\n" );
	
	ESP8266_Init ();   //?????WiFi?????õ????????
  ESP8266_StaTcpClient ();//WiFi???????
	printf ( "\r\n  ESP8266_Init ESP8266_StaTcpClient ......\r\n" );
	
	delay_s(3);
	
	bool success = ESP8266_SendString(DISABLE, "ready", 5, 520);
		if (success) {
			printf("\r\n  Initial server request information feedback successful \r\n ");
		}else{
			printf("\r\n  Initial server request information feedback failure \r\n ");
		}
		
	MOTOR_GPIO_Init();
  printf ( "\r\n  MOTOR_GPIO_Init() ......\r\n" );
  while (1)
    {
		printf("????????\n");
		//delay_s(5);
		char *received_data = ESP8266_ReceiveString(DISABLE);
		printf("print received_data ??%s\n", received_data);
			
		if (received_data != NULL)
      {
			Command cmd = extractAndConvertToFloat(received_data);
			delay_s(5);
			
			printf ( "\r\n  cmd.action:---------------------- %d\r\n", cmd.action );
				printf ( "\r\n  cmd.time:-----------------------    %d\r\n", cmd.time );
      switch (cmd.action) {
        case 1:  // ???
            Car_Forward();
            break;
        case 2:  // ????
            Car_Backward();
            break;
        case 3:  // ???
            Car_TurnLeft();
            break;
        case 4:  // ???
            Car_TurnRight();
            break;
        default:  // ?????
            Car_Stop();
       }
    
       delay_s(cmd.time);  // ???????
       Car_Stop();  // ??
			 
	     bool success = ESP8266_SendString(DISABLE, "TCP copy", 5, 520);
			   if (success) {
				   printf("???????\n");
			   }else{
				   printf("???????\n");
			   }
       }
    }
}
