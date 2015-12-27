#include "stm32f10x.h"
#include "string.h"
#include "stm32f10x_conf.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>


//#define CMD_BUFFER_LEN 100
//#define ATT GPIO_Pin_12	       //ATT  PB12
#define CMD_BUFFER_LEN 100
//#define PI 3.14159265
//#define l 19.052               //码盘到中心点的距离
//#define dseterror 0.1 
//#define MAXv 5000              //达到的最大速度
//#define MAXw 3000              //达到的最大转向速度
//#define SLOWv 600
//#define shouDongMaxv 100
//#define shouDongError 20
//#define La 8.2
//#define Lb 19.5
//#define RelayBit GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_11)  //读限位继电器状态
//#define Relay_OFF GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_RESET);   //限位关
//#define Relay_ON GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_SET);   //限位开

extern uint8_t data[10];
//extern uint8_t PSX_CONN[5];               //进入设置模式
//extern uint8_t PSX_MODE[9];   //设置为Analog Mode
//extern uint8_t PSX_POLL[9];   //轮询
//extern uint8_t PSX_EXIT[9];  //退出，这个在Motor版本里被删掉了
extern int	g_rotary[3];
extern float Round[3];
extern int g_x;
extern int g_y;
//extern u8 g_dma_buffer[19];
//extern const uint8_t FRAMEHEAD[5];
//extern float roll, pitch, yaw;
//extern float preyaw;       //每次开机后陀螺仪的YAW数据
//extern float delta;        //delta = yaw - preyaw 代表当前陀螺仪数据与开机数据的差
//extern u16 g_abs_encoder_data_old; //绝对值码盘
//extern u16 g_abs_encoder_data_new; //绝对值码盘
//extern s32 g_abs_encoder_data;
//extern u8 g_abs_encoder_flag;
//extern int HitFlag;                    //击球标志
//extern int g_tim2_flag;
//extern float g_round;
//extern int g_rotary;


int fgetc(FILE *fp);
int fputc(int ch,FILE *f);
void myprintf (USART_TypeDef* USARTx, char *fmt, ...);
void Delay_us(uint32_t us);
void Delay_ms(uint16_t ms);
int byte2long(u8 buffer[]);
void xsen_dec(void);
void LCDPrintf (char *fmt, ...);
void LCDMainPrintf (char *fmt, ...);
void myitoa(int i, char *string);
int myatoi(char *str);
float GetRound(TIM_TypeDef* TIMx, int n);        //转盘处增量码盘
void readEncoder(int *x,int *y);
//void press();
//void lunxun();
//oid wushua_move(int duty);               //转盘无刷
//void wushua_setball(int duty);						//发球无刷
//void HitBall(int speed);        //击球函数，参数为博创电机速度
