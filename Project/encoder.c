#include "configuration.h"
int	g_rotary[3] = {0};
float Round[3] = {0};


float GetRound(TIM_TypeDef* TIMx, int n)       //转盘处增量码盘
{
	g_rotary[n] +=(TIM_GetCounter(TIMx)-4000);
	TIMx->CNT = 4000;
	Round[n] = ((float)g_rotary[n])/2000;        //此处两个码盘不一样
	return Round[n];
} 

void readEncoder(int *x,int *y)
{
	*x = GetRound(TIM5, 1);
	*y = GetRound(TIM4, 2);
}
