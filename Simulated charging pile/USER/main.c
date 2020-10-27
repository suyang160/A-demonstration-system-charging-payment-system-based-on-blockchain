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
	u8 flag_auth = 0;
	SystemInit();
	delay_init();	    //延时函数初始化	 	 
  uart_init(9600);	 //串口初始化为9600
	LED_Init();		  	//初始化与LED连接的硬件接口 
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
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\n\r\n");//插入换行
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
 