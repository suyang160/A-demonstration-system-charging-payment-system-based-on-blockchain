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
#define start PAout(1)// PB5
#define yellow_led PBout(6)
#define green_led PBout(5)
#define red_led PBout(12)
#define AT PBout(7)
#define STATE GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)

void LED_Init(void);//��ʼ��

		 				    
#endif
