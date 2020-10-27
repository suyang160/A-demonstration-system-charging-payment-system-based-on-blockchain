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
	uart2_init(9600);	 //串口初始化为4800
	LED_Init();		  	//初始化与LED连接的硬件接口
	while(1)
	{
		if(flag == 0)
		{
			if(KEY0==1)
			{
				delay_ms(10);
				if(KEY0==1)
				{
					switch_led = 1;
					//send message to the computer
					printf("b"); //start the demo
					//control the car go ahead
					go_back = 0; //0 go ahead
					delay_ms(1000);
					printf("m"); 
					delay_ms(1000);
					go_back = 1;
					printf("a"); 
					
				  //send message by BT to open the car's BT
					Usart2_SendString("a\r\n");
					delay_ms(1000);
					printf("s");
					Usart2_SendString("c\r\n");
					delay_ms(1000);
					printf("p");
					flag = 1;
				}
			}
		}
		if(flag == 1)
		{
			if(KEY0==0)
			{
				delay_ms(10);
				if(KEY0==0)
				{
					//close the led
					switch_led = 0;
					//send message to computer,finish the process
					printf("r"); //end the demo
					//when the button is triggered agian,go back the car
					go_ahead = 0;
					delay_ms(1000);
					delay_ms(1000);
					go_ahead = 1;
					flag = 0;
					delay_ms(1000);
					Usart2_SendString("b\r\n");
				}
			}
		}
		
		//recive message from car and transmit it to the computer
		if(USART2_RX_STA&0x8000)
		 {					   
				len=USART2_RX_STA&0x3fff;//得到此次接收到的数据长度
					for(t=0;t<len;t++)
				{
					USART_SendData(USART1, USART2_RX_BUF[t]);//向串口1发送数据
					while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
				}
//			 
//			  if(USART2_RX_BUF[0]=='a'&&USART2_RX_BUF[1]=='u'&&USART2_RX_BUF[2]=='t'&&USART2_RX_BUF[3]=='h')
//				{
//					//the open command
//					printf("start the process of authentication\r\n");
////					delay_ms(1000);
////					delay_ms(1000);
////					printf("finish the process and Wait for the charger\r\n\r\n");
////					flag_auth = 1;
//				}
//				if(USART2_RX_BUF[0]=='h')
//				{
//					printf("start the process of authentication\r\n");
//				}
				if(USART2_RX_BUF[0]=='i')//插入plug
				{
					printf("i");
				}
				if(USART2_RX_BUF[0]=='j')//拔出
				{
					printf("o");
				}
				USART2_RX_STA=0;
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