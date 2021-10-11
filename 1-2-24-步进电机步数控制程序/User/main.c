/*********************************************************************************************
ģ��������  ��������/���ҵ���
��������	��������������Ƴ���
��д�ˣ�	����	
��дʱ�䣺	2018��3��10��
Ӳ��֧�֣�	STM32F103C8   �ⲿ����8MHz RCC����������Ƶ72MHz��  

�޸���־������
1-	
	
							
˵����
 # ��ģ�������STM32F103�ڲ���RCCʱ�����ã������������õδ�ʱ������ʱ������
 # �ɸ����Լ�����Ҫ���ӻ�ɾ����

*********************************************************************************************/
#include "stm32f10x.h" //STM32ͷ�ļ�
#include "sys.h"
#include "delay.h"
#include "touch_key.h"
#include "relay.h"

#include "step_motor.h"

int main (void){//������
	RCC_Configuration(); //ϵͳʱ�ӳ�ʼ�� 
	TOUCH_KEY_Init();//����������ʼ��
	RELAY_Init();//�̵�����ʼ��

	STEP_MOTOR_Init();//���������ʼ��

	while(1){
		if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_A))STEP_MOTOR_LOOP(0,1,3); // ��Ȧ����ת		
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_B))STEP_MOTOR_LOOP(1,1,3); //��Ȧ����ת		
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_C))STEP_MOTOR_NUM(0,100,3); //��������ת
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_D))STEP_MOTOR_NUM(1,100,3); //��������ת
		else STEP_MOTOR_OFF();//��û�а���ʱ��������ϵ�
	}
}

/*********************************************************************************************
 * �������� www.DoYoung.net
 * ���ҵ��� www.DoYoung.net/YT 
*********************************************************************************************/
/*

���������塿
u32     a; //����32λ�޷��ű���a
u16     a; //����16λ�޷��ű���a
u8     a; //����8λ�޷��ű���a
vu32     a; //�����ױ��32λ�޷��ű���a
vu16     a; //�����ױ�� 16λ�޷��ű���a
vu8     a; //�����ױ�� 8λ�޷��ű���a
uc32     a; //����ֻ����32λ�޷��ű���a
uc16     a; //����ֻ�� ��16λ�޷��ű���a
uc8     a; //����ֻ�� ��8λ�޷��ű���a

#define ONE  1   //�궨��

delay_us(1); //��ʱ1΢��
delay_ms(1); //��ʱ1����
delay_s(1); //��ʱ1��

GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED����

*/



