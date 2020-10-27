#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
 
 
/************************************************
 ALIENTEKս��STM32������ʵ��1
 �����ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
void Usart2_SendString(char *str);

 int main(void)
 {
	u16 t;  
	u16 len;	
	u8 flag = 0;
	u8 flag_auth = 0;
	SystemInit();
	delay_init();	    //��ʱ������ʼ��	 	 
  uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ� 
	yellow_led=1;
	red_led = 0;
	delay_ms(1000);
	AT = 1;
	printf("AT+LINK=2018,12,172843\r\n");
	while(STATE==0);
	AT = 0;
	while(1)
	{
		 if(USART_RX_STA&0x8000)
		{			
			len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			printf("\r\n\r\n");//���뻻��
			if(USART_RX_BUF[0]=='i')
			{
				green_led=0;
			}
			else if(USART_RX_BUF[0]=='j')
			{
				green_led=1;
			}
			else if(USART_RX_BUF[0]=='h')
			{
				yellow_led=0;
			}
			else if(USART_RX_BUF[0]=='k')
			{
				yellow_led=1;
			}
			USART_RX_STA=0;
		}
		
	}
 }
 