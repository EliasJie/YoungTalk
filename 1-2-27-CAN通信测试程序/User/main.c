/*********************************************************************************************
模板制作：  杜洋工作室/洋桃电子
程序名：	CAN通信测试程序
编写人：	杜洋	
编写时间：	2018年3月20日
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
#include "touch_key.h"
#include "relay.h"
#include "oled0561.h"

#include "can.h"

int main (void){//主程序
	u8 buff[8];
	u8 x;
	delay_ms(100); //上电时等待其他器件就绪
	RCC_Configuration(); //系统时钟初始化 
	TOUCH_KEY_Init();//触摸按键初始化
	RELAY_Init();//继电器初始化

	CAN1_Configuration(); //CAN总线初始化 返回0表示成功

	I2C_Configuration();//I2C初始化
	OLED0561_Init(); //OLED初始化
	OLED_DISPLAY_8x16_BUFFER(0,"   YoungTalk "); //显示字符串
	OLED_DISPLAY_8x16_BUFFER(2,"   CAN TEST  "); //显示字符串
	OLED_DISPLAY_8x16_BUFFER(6,"TX:    RX:   "); //显示字符串


	while(1){
		if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_A)){buff[0]='A';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'A');} //向RS232串口发送字符并在OLED上显示		
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_B)){buff[0]='B';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'B');} //向RS232串口发送字符并在OLED上显示		
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_C)){buff[0]='C';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'C');} //向RS232串口发送字符并在OLED上显示
		else if(!GPIO_ReadInputDataBit(TOUCH_KEYPORT,TOUCH_KEY_D)){buff[0]='D';CAN_Send_Msg(buff,1);OLED_DISPLAY_8x16(6,4*8,'D');} //向RS232串口发送字符并在OLED上显示

		//CAN查寻方式的接收处理
		x = CAN_Receive_Msg(buff); //检查是否收到数据
		if(x){ //判断接收数据的数量，不为0表示有收到数据
			OLED_DISPLAY_8x16(6,11*8,buff[0]);//在OLED上显示
		}
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

GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED控制

*/



