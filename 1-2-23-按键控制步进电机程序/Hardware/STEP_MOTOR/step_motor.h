#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H	 
#include "sys.h"
#include "delay.h"


#define STEP_MOTOR_PORT	GPIOB	//����IO�ӿ�������
#define STEP_MOTOR_A	GPIO_Pin_3	//����IO�ӿ�
#define STEP_MOTOR_B	GPIO_Pin_4	//����IO�ӿ�
#define STEP_MOTOR_C	GPIO_Pin_8	//����IO�ӿ�
#define STEP_MOTOR_D	GPIO_Pin_9	//����IO�ӿ�



void STEP_MOTOR_Init(void);//��ʼ��
void STEP_MOTOR_OFF (void);//�ϵ�״̬
void STEP_MOTOR_4S (u8 speed);//�̶�λ�ã��ƶ���
void STEP_MOTOR_4R (u8 speed);//
void STEP_MOTOR_4L (u8 speed);
void STEP_MOTOR_8R (u8 speed);
void STEP_MOTOR_8L (u8 speed);


		 				    
#endif
