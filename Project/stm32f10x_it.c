/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
//#include "LCD_STD.h"
#include "Configuration.h"
//#include "absEncoder.h"
//float deltaYaw = 0.0;        //delta = yaw - preyaw 代表当前陀螺仪数据与开机数据的差
//int T = 0;                //进入中断的周期
//int targetPos;						//目标位置
//int curPos;             //当前位置
//int deltaPos;
//int oFlag = 0;
//int aFlag = 0;
//int g_tim2_flag = 0;
//float g_round = 0;
int g_x = 0;
int g_y = 0;
/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

#if 0
void TIM2_IRQHandler(void)//定时器中断函数  
{
  if( TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET ) 
  {
//  myprintf(USART1,"TIM1_OCInitStructure.TIM_Pulse=%d",TIM1_OCInitStructure.TIM_Pulse);

	 TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);//必须清除中断标志位否则一直中断
	 g_rotary +=(TIM_GetCounter(TIM4)-4000);
	//	myprintf(USART1,"g_rotary_one=%d\tg_rotary_two=%d\tg_rotary_three=%d\r\n", g_rotary_one, g_rotary_two,g_rotary_three);
	 TIM4->CNT = 4000;
	// myprintf(USART1,"TIM1_OCInitStructure.TIM_Pulse=%d",TIM1_OCInitStructure.TIM_Pulse);
	 g_round = ((float)g_rotary)/4000;
	 myprintf(USART1, "转的圈数为：%5f\r\n", g_round);
  }
}
#endif

void TIM2_IRQHandler(void)
{
		if( TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET ) 
		{
			//myprintf(USART1,"counter = %d;",TIM_GetCounter(TIM4));
			readEncoder(&g_x , &g_y);
			//myprintf(USART3,"round_x = %d;\r\n 哈round_y = %d\r\n", 0,0);
			myprintf(USART3,"round_x = %d;\r\n\tround_y = %d\r\n", g_x , g_y);
			//myprintf(USART3,"bang");
			//g_tim2_flag = readEncoder();

			TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);//必须清除中断标志位否则一直中断
		}	
}

void TIM4_IRQHandler(void)
{
	if( TIM_GetITStatus(TIM4,TIM_IT_Update) != RESET )
	{
		TIM_ClearITPendingBit(TIM4, TIM_FLAG_Update);
	}
}

void TIM5_IRQHandler(void)
{
	if( TIM_GetITStatus(TIM5,TIM_IT_Update) != RESET )
	{
		TIM_ClearITPendingBit(TIM5, TIM_FLAG_Update);
	}
}

#if 0
void EXTI1_IRQHandler(void)  //光栅
{
	
			//Delay_ms(30);
			GPIO_WriteBit(GPIOG, GPIO_Pin_10, Bit_SET);
	    Delay_ms(10);
			GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_SET);
			//if(aFlag == 0)
			aFlag = 1;
			LCDMainPrintf("EXTI_Line_1");
				//Delay_ms(1000);
			/* 清除中断挂起标志位，否则会被认为中断没有被处理而循环再次进入中断 */
			EXTI_ClearITPendingBit(EXTI_Line1);
}
#endif

#if 1
void USART1_IRQHandler(void)
{ 
	 //myprintf(USART1,"%f",readEncoder());
	 USART_ClearITPendingBit(USART1, USART_IT_RXNE);//清除接收中断标志
	 //USART_ITConfig(USART1,USART_IT_RXNE, ENABLE);
}
#endif

#if 1
void USART3_IRQHandler(void)
{
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}
#endif

#if 0
void USART3_IRQHandler(void)
{ 
	 char buffer[100];
	  //LCDMainPrintf("Enter");
    if(USART_GetITStatus(USART3, USART_IT_RXNE)!= RESET) 
    {
			//USART_ClearITPendingBit(USART3, USART_IT_RXNE);	//清除接收中断标志
			//myprintf(USART3, "\nhi I'm coming\n");
			scanf("%s", buffer);
			LCDMainPrintf("%s", buffer);
			if(buffer[0] == 'o')          //圈圈  强制击球
			{
				GPIO_WriteBit(GPIOG, GPIO_Pin_10, Bit_SET);
				GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_SET);
				aFlag = 1;
			}
			
//			if(buffer[0] == 's')           //L2 落球无刷
//				wushua_setball(79);
//			else
//				wushua_setball(86);
			else if(buffer[0] == 'x')    //断电！
			{
				GPIO_WriteBit(GPIOG, GPIO_Pin_12, Bit_RESET);
				GPIO_WriteBit(GPIOG, GPIO_Pin_10, Bit_RESET);
				GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_RESET);
			}
			else if(buffer[0] == 't')    //不按  继电器断电系统高电平
			{
				GPIO_WriteBit(GPIOG, GPIO_Pin_12, Bit_SET);
				if(aFlag == 1)
				{
					Delay_ms(5000);
					GPIO_WriteBit(GPIOG, GPIO_Pin_10, Bit_RESET);
					GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_RESET);
					aFlag = 0;
				}
				
			}
			USART_ITConfig(USART3,USART_IT_RXNE, ENABLE);
			//LCDMainPrintf("%d", myatoi(buffer));
			//USART_ClearITPendingBit(USART3, USART_IT_RXNE);
			//if(USART_GetITStatus(USART3, USART_IT_RXNE)== SET)
				//USART_ClearITPendingBit(USART3, USART_IT_RXNE);	//清除接收中断标志
		}
		
	//LCDMainPrintf("Exit");
	//if(USART_GetITStatus(USART3, USART_IT_RXNE)== SET)
	//USART_ClearITPendingBit(USART3, USART_IT_RXNE);	//清除接收中断标志
}
#endif

void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */

/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
