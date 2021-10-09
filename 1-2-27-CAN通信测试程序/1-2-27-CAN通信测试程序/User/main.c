/*********************************************************************************************
ģ��������  ��������/���ҵ���
��������	CANͨ�Ų��Գ���
��д�ˣ�	����	
��дʱ�䣺	2018��3��20��
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
#include "oled0561.h"

#include "can.h"

int main (void){//������
	u8 buff[8];
	u8 x;
	delay_ms(100); //�ϵ�ʱ�ȴ�������������
	RCC_Configuration(); //ϵͳʱ�ӳ�ʼ�� 
	TOUCH_KEY_Init();//����������ʼ��
	RELAY_Init();//�̵�����ʼ��

	CAN1_Configuration(); //CAN���߳�ʼ�� ����0��ʾ�ɹ�

	I2C_Configuration();//I2C��ʼ��
	OLED0561_Init(); //OLED��ʼ��
	OLED_DISPLAY_8x16_BUFFER(0,"   YoungTalk "); //��ʾ�ַ���
	OLED_DISPLAY_8x16_BUFFER(2,"   CAN TEST  "); //��ʾ�ַ���
	OLED_DISPLAY_8x16_BUFFER(6,"TX:    RX:   "); //��ʾ�ַ���


	while(1){
		if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_A)){buff[0]='A';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'A');} //��RS232���ڷ����ַ�����OLED����ʾ		
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_B)){buff[0]='B';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'B');} //��RS232���ڷ����ַ�����OLED����ʾ		
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_C)){buff[0]='C';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'C');} //��RS232���ڷ����ַ�����OLED����ʾ
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_D)){buff[0]='D';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'D');} //��RS232���ڷ����ַ�����OLED����ʾ

		//CAN��Ѱ��ʽ�Ľ��մ���
		x = CAN_Receive_Msg(buff); //����Ƿ��յ�����
		if(x){ //�жϽ������ݵ���������Ϊ0��ʾ���յ�����
			OLED_DISPLAY_8x16(6,11*8,buff[0]);//��OLED����ʾ
		}
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



