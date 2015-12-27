#include "global.h"
//#include "LCD_STD.h"



void myitoa(int i, char *string)  
{  
    int power=0,j=0;  
			j=i;  
    for( power=1;j>10;j/=10)  
      power*=10;  
    for(;power>0;power/=10)  
    {  
			*string++='0'+i/power;  
      i%=power;  
    }  
    *string='\0'; 
}  

int myatoi(char *str)  
{  
	  int bMinus=0;  
    int result=0;  
    if(!str)  
      return -1;  
    if(('0'>*str || *str>'9')&&(*str=='+'||*str=='-'))  
        {  
               if(*str=='-')  
                bMinus=1;  
               *str++;  
        }  
        while( *str != '\0')  
        {  
                if('0'> *str || *str>'9')  
                        break;  
                else  
                        result = result*10+(*str++ - '0');  
        }  
  
        if (*str != '\0')//no-normal end  
                return -2;  
  
        return bMinus?-result:result;  
}  

int fputc(int ch, FILE *f)
{
    /* Place your implementation of fputc here */
    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)
    {}

    /* e.g. write a character to the USART */
    USART_SendData(USART3, (uint8_t) ch);

    return ch;
}

int fgetc(FILE *fp)
{
	int ch = 0;
    while(USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET)
    {
    }

    ch = (int)USART3->DR & 0xFF;
	
    //putchar(ch); //回显
	
	return ch;
}

void myprintf(USART_TypeDef* USARTx, char *fmt, ...)
{

	char buffer[CMD_BUFFER_LEN+1];  // CMD_BUFFER_LEN长度自己定义吧
	u8 i = 0;
	
	va_list arg_ptr;
	va_start(arg_ptr, fmt);  
	vsnprintf(buffer, CMD_BUFFER_LEN+1, fmt, arg_ptr);
	USART_ClearFlag(USARTx,USART_FLAG_TXE);
	while ((i < CMD_BUFFER_LEN) && buffer[i])
	{
	    USART_SendData(USARTx, (u8) buffer[i++]);
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); 
	}
	va_end(arg_ptr);
} 

void Delay_us(uint32_t us)	   //1us的延迟，可能偏小
{
	char i = 0;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	if (us > 1)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); 
	
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		  	 
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseStructure.TIM_Period = us-1;
		
		TIM_TimeBaseStructure.TIM_Prescaler = 71;
		
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
		TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);				
		TIM_ClearFlag(TIM7, TIM_FLAG_Update);  		

		while(i<1)
		{
			TIM_Cmd(TIM7, ENABLE);			  //当内层嵌套的Delay结束时，会使得外层Delay卡死，故将开关写在循环里面。

			if (TIM_GetFlagStatus(TIM7, TIM_FLAG_Update) == SET)
			{
				i++;
				TIM_ClearFlag(TIM7, TIM_FLAG_Update);
			}
		}

		TIM_ClearFlag(TIM7, TIM_FLAG_Update);
		TIM_Cmd(TIM7,DISABLE);
	}
}

void Delay_ms(uint16_t ms)	   //0.1ms的延迟，可能偏小
{
	char i = 0;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	if (ms > 1)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); 
	
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		  	 
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseStructure.TIM_Period = ms-1;
		
		TIM_TimeBaseStructure.TIM_Prescaler = 7199;
		
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
		TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);				
		TIM_ClearFlag(TIM7, TIM_FLAG_Update);  		

		while(i<1)
		{
			TIM_Cmd(TIM7, ENABLE);			  //当内层嵌套的Delay结束时，会使得外层Delay卡死，故将开关写在循环里面。

			if (TIM_GetFlagStatus(TIM7, TIM_FLAG_Update) == SET)
			{
				i++;
				TIM_ClearFlag(TIM7, TIM_FLAG_Update);
			}
				
		}

		TIM_ClearFlag(TIM7, TIM_FLAG_Update);
		TIM_Cmd(TIM7,DISABLE);
	}
}

#if 0
void LCDMainPrintf (char *fmt, ...)
{
	char LED_buffer[CMD_BUFFER_LEN+1];  // CMD_BUFFER_LEN长度自己定义吧
	
	va_list arg_ptr;
	va_start(arg_ptr, fmt);  
	vsnprintf(LED_buffer, CMD_BUFFER_LEN+1, fmt, arg_ptr);
//	while ((i < CMD_BUFFER_LEN) && LED_buffer[i])
	//{
	LCD_Clear();
	OLED_Clear_From_Row2();
	LCD_Write(1, 1,LED_buffer);

	va_end(arg_ptr);
}

void LCDPrintf (char *fmt, ...)
{
	char LED_buffer[CMD_BUFFER_LEN+1];  // CMD_BUFFER_LEN长度自己定义吧
	
	va_list arg_ptr;
	va_start(arg_ptr, fmt);  
	vsnprintf(LED_buffer, CMD_BUFFER_LEN+1, fmt, arg_ptr);
//	while ((i < CMD_BUFFER_LEN) && LED_buffer[i])
	//{
	//OLED_Clear_From_Row2();
	LCD_Write(1, 2,LED_buffer);

	va_end(arg_ptr);
}
#endif
