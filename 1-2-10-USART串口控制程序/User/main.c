/*********************************************************************************************
模板制作：  杜洋工作室/洋桃电子
程序名：	USART串口控制程序
编写人：	杜洋	
编写时间：	2018年1月12日
硬件支持：	STM32F103C8   外部晶振8MHz RCC函数设置主频72MHz　  

修改日志：　　
1-	
	
							
说明：
 # 本模板加载了STM32F103内部的RCC时钟设置，并加入了利用滴答定时器的延时函数。
 # 可根据自己的需要增加或删减。

*********************************************************************************************/
#include "stm32f10x.h" //STM32头文件
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "buzzer.h"
#include "usart.h"


int main (void){//主程序
	u8 a;
	//初始化程序
	RCC_Configuration(); //时钟设置
	LED_Init();//LED初始化
	KEY_Init();//按键初始化
	BUZZER_Init();//蜂鸣器初始化
	USART1_Init(115200); //串口初始化（参数是波特率）

	//主循环
	while(1){

		//查询方式接收
		if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) != RESET){  //查询串口待处理标志位
			a =USART_ReceiveData(USART1);//读取接收到的数据
			switch (a){
				case '0':
					GPIO_WriteBit(LEDPORT,LED1,(BitAction)(0)); //LED控制
					printf("%c:LED1 OFF ",a); //
					break;
				case '1':
					GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED控制
					printf("%c:LED1 ON ",a); //
					break;
				case '2':
					BUZZER_BEEP1(); //蜂鸣一声
					printf("%c:BUZZER ",a); //把收到的数据发送回电脑
					break;
				default:
					break;
			}		  
		}

		//按键控制
		if(!GPIO_ReadInputDataBit(KEYPORT,KEY1)){ //读按键接口的电平
			delay_ms(20); //延时20ms去抖动
			if(!GPIO_ReadInputDataBit(KEYPORT,KEY1)){ //读按键接口的电平
				while(!GPIO_ReadInputDataBit(KEYPORT,KEY1)); //等待按键松开 
				printf("KEY1 "); //
			}
		}		 
		if(!GPIO_ReadInputDataBit(KEYPORT,KEY2)){ //读按键接口的电平
			delay_ms(20); //延时20ms去抖动
			if(!GPIO_ReadInputDataBit(KEYPORT,KEY2)){ //读按键接口的电平
				while(!GPIO_ReadInputDataBit(KEYPORT,KEY2)); //等待按键松开 
				printf("KEY2 "); //
			}
		}		 

//      delay_ms(1000); //延时
	}
}


/*********************************************************************************************
 * 杜洋工作室 www.DoYoung.net
 * 洋桃电子 www.DoYoung.net/YT 
*********************************************************************************************/
/*

【变量定义】
u32     a; //定义32位无符号变量a
u16     a; //定义16位无符号变量a
u8     a; //定义8位无符号变量a
vu32     a; //定义易变的32位无符号变量a
vu16     a; //定义易变的 16位无符号变量a
vu8     a; //定义易变的 8位无符号变量a
uc32     a; //定义只读的32位无符号变量a
uc16     a; //定义只读 的16位无符号变量a
uc8     a; //定义只读 的8位无符号变量a

#define ONE  1   //宏定义

delay_us(1); //延时1微秒
delay_ms(1); //延时1毫秒
delay_s(1); //延时1秒

*/



