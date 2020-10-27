#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
 
 
/************************************************
 ALIENTEK战舰STM32开发板实验1
 跑马灯实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
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
	delay_init();	    //延时函数初始化	  
  uart_init(9600);	 //串口初始化为9600
	uart2_init(9600);	 //串口初始化为4800
	LED_Init();		  	//初始化与LED连接的硬件接口
	red_led = 0;
	 
	while(1)
	{
//first,we need receive the BT signal to active the anothor BT
		if(USART2_RX_STA&0x8000)
		 {					   
				len=USART2_RX_STA&0x3fff;//得到此次接收到的数据长度
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
					 printf("i\r\n");//插枪充电
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
					 printf("j\r\n");//拔枪走人
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