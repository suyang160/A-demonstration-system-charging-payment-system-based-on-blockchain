#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define start PBout(0)// PB5
#define go_ahead PBout(1)
#define go_back  PBout(10)
#define switch_led PAout(5)// PE5	
#define KEY0  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//��ȡ����0

void LED_Init(void);//��ʼ��

		 				    
#endif
