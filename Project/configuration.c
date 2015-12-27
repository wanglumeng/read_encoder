#include "configuration.h"
#include <stdio.h>

GPIO_InitTypeDef GPIO_InitStructure;
RCC_ClocksTypeDef RCC_ClockFreq;
USART_InitTypeDef USART_InitStructure; 
NVIC_InitTypeDef NVIC_InitStructure;
//DMA_InitTypeDef DMA_Structure; 
//EXTI_InitTypeDef EXTI_InitStructure;

TIM_TimeBaseInitTypeDef TIM1_TimeBaseStructure;
TIM_OCInitTypeDef  TIM1_OCInitStructure;//ͨ�������ʼ���ṹ
TIM_ICInitTypeDef   TIM1_ICInitStructure;

TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;//ͨ�������ʼ���ṹ
TIM_ICInitTypeDef   TIM_ICInitStructure;



void RCC_Configuration()
{
	RCC_DeInit();			//��ʼ��Ϊȱʡֵ
	SystemInit();//Դ��system_stm32f10x.c�ļ�,ֻ��Ҫ���ô˺���,������RCC������.
	RCC_GetClocksFreq(&RCC_ClockFreq);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);
                                                            //�����¼����ƼĴ���/�ⲿ�жϿ��ƼĴ���/��ӳ��ʱ���뿪��AFIOʱ�ӣ������ܽŵ�Ĭ�����蹦�ܲ�����Ҫ��AFIOʱ�ӣ�û����ӳ�䣩
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);	 //ʹ��USART1ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);	//ʹ��USART2ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);	//ʹ��USART3ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE); 		
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);		
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);   

}

void GPIO_Configuration(uint16_t GPIO_Pin,GPIOMode_TypeDef  GPIO_Mode,GPIOSpeed_TypeDef GPIO_Speed,GPIO_TypeDef* GPIOx)
{
 
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;                       //�ܽź� 
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;                     //���ģʽ
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
  	GPIO_Init(GPIOx, &GPIO_InitStructure);                        //�ܽ���� 
}

void GPIO_Config(void)
{
	//δʹ�� ���ô���1  PB6 TX  PB7 RX
	GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE);
	GPIO_Configuration(GPIO_Pin_7,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOB); //USART1 RX
	GPIO_Configuration(GPIO_Pin_6,GPIO_Mode_AF_PP, GPIO_Speed_50MHz,GPIOB);   //USART1 TX
	
	//δʹ�� ���ô���2   PD5 TX PD6 RX
	GPIO_PinRemapConfig(GPIO_Remap_USART2,ENABLE);
	GPIO_Configuration(GPIO_Pin_5,GPIO_Mode_AF_PP, GPIO_Speed_50MHz,GPIOD);   //USART2 TX
	GPIO_Configuration(GPIO_Pin_6,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOD); //USART2 RX
	//����3    �жϽ�����������    PB10 TX  PB11 RX
	GPIO_Configuration(GPIO_Pin_10,GPIO_Mode_AF_PP, GPIO_Speed_50MHz,GPIOB);   //USART3 TX
	GPIO_Configuration(GPIO_Pin_11,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOB); //USART3 RX
	
	//�ֱ�    PB14 PB12 PB13 PB15
//	GPIO_Configuration(GPIO_Pin_14,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOB);
//	GPIO_Configuration(GPIO_Pin_12,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOB);
//	GPIO_Configuration(GPIO_Pin_13|GPIO_Pin_15,GPIO_Mode_AF_PP, GPIO_Speed_50MHz,GPIOB);
		/************************************************************************************
	                 		��ʾ�� 
#define OLED_D0_PORT	GPIOE
#define OLED_D0_Pin		GPIO_Pin_8
#define OLED_D1_PORT	GPIOE
#define OLED_D1_Pin		GPIO_Pin_7

#define OLED_CS_PORT	GPIOG
#define OLED_CS_Pin		GPIO_Pin_0
#define OLED_DC_PORT	GPIOG
#define OLED_DC_Pin		GPIO_Pin_1
	*************************************************************************************/
//	GPIO_Configuration(GPIO_Pin_0,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);
//	GPIO_Configuration(GPIO_Pin_1,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);
//	GPIO_Configuration(GPIO_Pin_8,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOE);
//	GPIO_Configuration(GPIO_Pin_7,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOE);
	
	//����ֵ����  DO:PG5  CLK:PG4 CS:PG3
//	GPIO_Configuration(GPIO_Pin_5,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOG);  //DO����
//	GPIO_Configuration(GPIO_Pin_4,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);
//	GPIO_Configuration(GPIO_Pin_3,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);
	
	//��ʱ�� ��������   ����TIM4 PD12 PD13   TIM5 PA1 PA0
	GPIO_PinRemapConfig(GPIO_Remap_TIM4,ENABLE);
	GPIO_Configuration(GPIO_Pin_12|GPIO_Pin_13,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOD);  //TIM4��remap
	GPIO_Configuration(GPIO_Pin_0|GPIO_Pin_1,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOA); 		
	
	//�����ŷ�  (�̵���)   PG11 PG10
//	GPIO_Configuration(GPIO_Pin_11,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);
//	GPIO_Configuration(GPIO_Pin_10,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);

	//��դ(�������)   PF1
//  GPIO_Configuration(GPIO_Pin_1,GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz,GPIOF);
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOF, GPIO_PinSource1);/*�����ּ����Ӧ�Ĺܽ����ӵ��ڲ��ж��� */ 

	//�̵����ϵ�ϵͳ  PG12
//	GPIO_Configuration(GPIO_Pin_12,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);
//	GPIO_Configuration(GPIO_Pin_13,GPIO_Mode_Out_PP, GPIO_Speed_50MHz,GPIOG);
	
}
#if 0
void EXTI_Configuration(void)   //����������ж�
{
		EXTI_InitStructure.EXTI_Line = EXTI_Line1;			   //�ж���0
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		 //�ж�ģʽ
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  //�����ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
	
}
#endif

void TIM2_Configuration()        //0.005ms ��ʱ 
{
	/*TIM2*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Prescaler = 4999;  
	TIM_TimeBaseStructure.TIM_Period = 7199;  
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;  //������ʱ�ӷָ�
    //��ʱ����ʱ������Ϊ (4+1)*(71+1)/(72*10^6)=0.005ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;// ����  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);	

}


#if 0
void TIM4_Configuration()   //��������
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	TIM_DeInit(TIM4);

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;  // No prescaling 
	TIM_TimeBaseStructure.TIM_Period = 30000 - 1;  
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;  //������ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;// ����  
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
 
	TIM_EncoderInterfaceConfig(TIM4,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 6;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);

	TIM4->CNT=4000;

	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM4, ENABLE);	
}
#endif

void TIME_Configuration(void)
{
	tim_config(TIM4);
	tim_config(TIM5);
}


void USART_Configuration(void)
{
	//����1
	USART_InitTypeDef USART_InitStructure; 
	USART_InitStructure.USART_BaudRate = 115200; 	   //���ò�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;    //һ��֡�д��������λ�����ֳ�Ϊ8λ���ݸ�ʽ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1; 	   //һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No; 	//����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;  //���ͺͽ���ģʽ
	USART_Init(USART1, &USART_InitStructure);	 //��ʼ������	
	USART_Cmd(USART1, ENABLE);	  //ʹ�ܴ���
	
	//����2
	USART_InitStructure.USART_BaudRate = 115200; 	   //���ò�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;    //һ��֡�д��������λ�����ֳ�Ϊ8λ���ݸ�ʽ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1; 	   //һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No; 	//����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;  //���ͺͽ���ģʽ
	USART_Init(USART2, &USART_InitStructure);	 //��ʼ������	
	USART_DMACmd(USART2, USART_DMAReq_Rx, ENABLE);//����DMA
	USART_Cmd(USART2, ENABLE);	  //ʹ�ܴ���
	
	//����3 ����
	USART_InitStructure.USART_BaudRate = 115200; 	   //���ò�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;    //һ��֡�д��������λ�����ֳ�Ϊ8λ���ݸ�ʽ��
	USART_InitStructure.USART_StopBits = USART_StopBits_1; 	   //һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No; 	//����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;  //���ͺͽ���ģʽ
	USART_Init(USART3, &USART_InitStructure);	 //��ʼ������	
	//USART_DMACmd(USART3, USART_DMAReq_Rx, ENABLE);//����DMA
	USART_Cmd(USART3, ENABLE);	  //ʹ�ܴ���
	USART_ITConfig(USART3,USART_IT_RXNE, ENABLE);//���жϣ��ӿ�
}

void NVIC_Configuration()
{
		//USART1 �ж�
//		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//    NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;//0
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;//0
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure); 
		//TIM2 �ж�
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;//0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;//0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure); 
    //TIM4 �ж�
//	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//    NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;//0
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;//0
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure); 
		//TIM5�ж�
//		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//    NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;//0
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;//0
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure); 
    //USART3 �ж�
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    NVIC_InitStructure.NVIC_IRQChannel=USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;//0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;//0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure); 
		
		//�����ⲿ�ж� 
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;	 //ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   //��ռ���ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		  //�����ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			  //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);				 //����NVIC_InitStructure��ָ���Ĳ�����ʼ������NVIC
}
