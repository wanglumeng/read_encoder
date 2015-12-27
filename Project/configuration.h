#include "global.h"

extern TIM_TimeBaseInitTypeDef TIM1_TimeBaseStructure;
extern TIM_OCInitTypeDef  TIM1_OCInitStructure;//通道输出初始化结构
extern TIM_ICInitTypeDef   TIM1_ICInitStructure;

extern TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
extern TIM_OCInitTypeDef  TIM_OCInitStructure;//通道输出初始化结构
extern TIM_ICInitTypeDef   TIM_ICInitStructure;


void RCC_Configuration(void);//时钟
void GPIO_Config(void);
void USART_Configuration(void);//串口
//void SPI_Configuration(void);//通用串行总线
//void PSX_Configuration(void);//手柄
//void EXTI_Configuration(void);
void myprintf (USART_TypeDef* USARTx, char *fmt, ...);
void GPIO_Configuration(uint16_t GPIO_Pin,GPIOMode_TypeDef  GPIO_Mode,GPIOSpeed_TypeDef GPIO_Speed,GPIO_TypeDef* GPIOx);
void NVIC_Configuration(void);//中断向量
void DMA_Configuration(void);//高速内存通道
void TIM2_Configuration(void);
void TIM3_Configuration(void);
void TIM4_Configuration(void);
void TIM5_Configuration(void);
void TIME_Configuration(void);
void PWM_Configuration(void);

//中心码盘定时读数
#define tim_config(TIMx) do\
{\
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_##TIMx, ENABLE);\
  TIM_DeInit(TIMx);\
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);\
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0;\
  TIM_TimeBaseStructure.TIM_Period = 29999;\
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;\
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;\
  TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure);\
  TIM_EncoderInterfaceConfig(TIMx,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);\
  TIM_ICStructInit(&TIM_ICInitStructure);\
  TIM_ICInitStructure.TIM_ICFilter = 6;\
  TIM_ICInit(TIMx, &TIM_ICInitStructure);\
  TIMx->CNT=4000;\
  TIM_ClearFlag(TIMx, TIM_FLAG_Update);\
  TIM_ITConfig(TIMx, TIM_IT_Update, ENABLE);\
  TIM_Cmd(TIMx, ENABLE);\
}while(0);
