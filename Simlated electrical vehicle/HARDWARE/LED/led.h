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
#define yellow_led PBout(9)
#define green_led  PBout(5)
#define red_led    PBout(12)
#define BT_EN PBout(8)
#define BT_State  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)//��ȡ����0
#define plug  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)//��ȡ����0

void LED_Init(void);//��ʼ��

		 				    
#endif
