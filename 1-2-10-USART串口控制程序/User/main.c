/*********************************************************************************************
ģ��������  ��������/���ҵ���
��������	USART���ڿ��Ƴ���
��д�ˣ�	����	
��дʱ�䣺	2018��1��12��
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
#include "led.h"
#include "key.h"
#include "buzzer.h"
#include "usart.h"


int main (void){//������
	u8 a;
	//��ʼ������
	RCC_Configuration(); //ʱ������
	LED_Init();//LED��ʼ��
	KEY_Init();//������ʼ��
	BUZZER_Init();//��������ʼ��
	USART1_Init(115200); //���ڳ�ʼ���������ǲ����ʣ�

	//��ѭ��
	while(1){

		//��ѯ��ʽ����
		if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) != RESET){  //��ѯ���ڴ������־λ
			a =USART_ReceiveData(USART1);//��ȡ���յ�������
			switch (a){
				case '0':
					GPIO_WriteBit(LEDPORT,LED1,(BitAction)(0)); //LED����
					printf("%c:LED1 OFF ",a); //
					break;
				case '1':
					GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED����
					printf("%c:LED1 ON ",a); //
					break;
				case '2':
					BUZZER_BEEP1(); //����һ��
					printf("%c:BUZZER ",a); //���յ������ݷ��ͻص���
					break;
				default:
					break;
			}		  
		}

		//��������
		if(!GPIO_ReadInputDataBit(KEYPORT,KEY1)){ //�������ӿڵĵ�ƽ
			delay_ms(20); //��ʱ20msȥ����
			if(!GPIO_ReadInputDataBit(KEYPORT,KEY1)){ //�������ӿڵĵ�ƽ
				while(!GPIO_ReadInputDataBit(KEYPORT,KEY1)); //�ȴ������ɿ� 
				printf("KEY1 "); //
			}
		}		 
		if(!GPIO_ReadInputDataBit(KEYPORT,KEY2)){ //�������ӿڵĵ�ƽ
			delay_ms(20); //��ʱ20msȥ����
			if(!GPIO_ReadInputDataBit(KEYPORT,KEY2)){ //�������ӿڵĵ�ƽ
				while(!GPIO_ReadInputDataBit(KEYPORT,KEY2)); //�ȴ������ɿ� 
				printf("KEY2 "); //
			}
		}		 

//      delay_ms(1000); //��ʱ
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

*/



