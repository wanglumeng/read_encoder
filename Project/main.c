#include "configuration.h"

int main(void)
{
	RCC_Configuration();
	GPIO_Config();
	USART_Configuration();	   //���в��������о���Ƶ��
 	NVIC_Configuration();
	TIM2_Configuration();
	TIME_Configuration();			 //TIM4/5����
	//EXTI_Configuration();
	//myprintf(USART1,"1v1000\r");
	
	while(1)
	{
		//while(g_tim2_flag == 0);
		//g_tim2_flag = 0;
		//myprintf(USART1,"encoder = %d",g_round);
		//myprintf(USART3,"round_x = %d;\r\n ��round_y = %d\r\n", 0,0);
	}
}
