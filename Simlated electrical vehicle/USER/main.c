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
	u8 flag1 = 0;
	u8 flag2 = 0;
	u8 plug_flag = 0;
	SystemInit();
	delay_init();	    //��ʱ������ʼ��	  
  uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	uart2_init(9600);	 //���ڳ�ʼ��Ϊ4800
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	red_led = 0;
	 
	while(1)
	{
//first,we need receive the BT signal to active the anothor BT
		if(USART2_RX_STA&0x8000)
		 {					   
				len=USART2_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			  if(USART2_RX_BUF[0]=='a')
				{
					//the open command
//					BT_EN = 1;
					flag=1;
				}
				else if(USART2_RX_BUF[0]=='b')
				{
	       flag1=1;			
				}
				else if(USART2_RX_BUF[0]=='c')
				{
					flag2=1;
				}
				USART2_RX_STA=0;
		 }
		 if(flag==1)
		 { 
			 //send message to computer
//			 printf("h\r\n");
//			 Usart2_SendString("h\r\n");
//			 yellow_led = 0;
			 flag=0;
		 }
		 if(flag1==1)
		 {
			  printf("k\r\n");
				yellow_led = 1;	
				flag1=0;
		 }
		 if(flag2==1)
		 {
			 printf("h\r\n");
			 yellow_led = 0;
			 flag2 = 0;
		 }
		 if(plug_flag==0)
		 {
			 if(plug==1)
			 {
				 delay_ms(300);
				 if(plug == 1)
				 {
					 Usart2_SendString("i\r\n");
					 green_led = 0;
					 printf("i\r\n");//��ǹ���
			     plug_flag=1;
				 }
			 }
		 }
		 else 
		 {
			 if(plug==0)
			 {
				 delay_ms(300);
				 if(plug == 0)
				 {
					 Usart2_SendString("j\r\n");
					 green_led = 1;
					 printf("j\r\n");//��ǹ����
			     plug_flag=0;
				 }
			 }
		 }
		 		 
	}
 }
 
 void Usart2_SendString(char *str)
{
		 while(*str)
		{
			USART_SendData(USART2,*str);
			while(USART_GetFlagStatus(USART2, USART_FLAG_TC)!=SET); 
			str++;
    }
}