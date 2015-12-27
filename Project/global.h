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
//#define l 19.052               //���̵����ĵ�ľ���
//#define dseterror 0.1 
//#define MAXv 5000              //�ﵽ������ٶ�
//#define MAXw 3000              //�ﵽ�����ת���ٶ�
//#define SLOWv 600
//#define shouDongMaxv 100
//#define shouDongError 20
//#define La 8.2
//#define Lb 19.5
//#define RelayBit GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_11)  //����λ�̵���״̬
//#define Relay_OFF GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_RESET);   //��λ��
//#define Relay_ON GPIO_WriteBit(GPIOG, GPIO_Pin_11, Bit_SET);   //��λ��

extern uint8_t data[10];
//extern uint8_t PSX_CONN[5];               //��������ģʽ
//extern uint8_t PSX_MODE[9];   //����ΪAnalog Mode
//extern uint8_t PSX_POLL[9];   //��ѯ
//extern uint8_t PSX_EXIT[9];  //�˳��������Motor�汾�ﱻɾ����
extern int	g_rotary[3];
extern float Round[3];
extern int g_x;
extern int g_y;
//extern u8 g_dma_buffer[19];
//extern const uint8_t FRAMEHEAD[5];
//extern float roll, pitch, yaw;
//extern float preyaw;       //ÿ�ο����������ǵ�YAW����
//extern float delta;        //delta = yaw - preyaw ����ǰ�����������뿪�����ݵĲ�
//extern u16 g_abs_encoder_data_old; //����ֵ����
//extern u16 g_abs_encoder_data_new; //����ֵ����
//extern s32 g_abs_encoder_data;
//extern u8 g_abs_encoder_flag;
//extern int HitFlag;                    //�����־
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
float GetRound(TIM_TypeDef* TIMx, int n);        //ת�̴���������
void readEncoder(int *x,int *y);
//void press();
//void lunxun();
//oid wushua_move(int duty);               //ת����ˢ
//void wushua_setball(int duty);						//������ˢ
//void HitBall(int speed);        //������������Ϊ��������ٶ�
