/*********************************************************************************************
模板制作：  杜洋工作室/洋桃电子
程序名：	OLED屏汉字与图片显示程序
编写人：	杜洋	
编写时间：	2018年3月7日
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
#include "lm75a.h"

#include "oled0561.h"

int main (void){//主程序
	u8 buffer[3];
	delay_ms(100); //上电时等待其他器件就绪
	RCC_Configuration(); //系统时钟初始化 

	I2C_Configuration();//I2C初始化
	LM75A_GetTemp(buffer); //读取LM75A的温度数据

	OLED0561_Init(); //OLED初始化
	OLED_DISPLAY_LIT(100);//亮度设置

	OLED_DISPLAY_PIC1();//显示全屏图片
	delay_ms(1000); //延时
	OLED_DISPLAY_CLEAR();
	OLED_DISPLAY_8x16_BUFFER(0,"   YoungTalk "); //显示字符串
	OLED_DISPLAY_8x16_BUFFER(6,"  Temp:"); //显示字符串

	OLED_DISPLAY_16x16(2,2*16,0);//汉字显示	 洋桃电子
	OLED_DISPLAY_16x16(2,3*16,1);
	OLED_DISPLAY_16x16(2,4*16,2);
	OLED_DISPLAY_16x16(2,5*16,3);

	while(1){
		LM75A_GetTemp(buffer); //读取LM75A的温度数据
			
		if(buffer[0])OLED_DISPLAY_8x16(6,7*8,'-'); //如果第1组为1即是负温度
		OLED_DISPLAY_8x16(6,8*8,buffer[1]/10+0x30);//显示温度值
		OLED_DISPLAY_8x16(6,9*8,buffer[1]%10+0x30);//
		OLED_DISPLAY_8x16(6,10*8,'.');//
		OLED_DISPLAY_8x16(6,11*8,buffer[2]/10+0x30);//
		OLED_DISPLAY_8x16(6,12*8,buffer[2]%10+0x30);//
		OLED_DISPLAY_8x16(6,13*8,'C');//

		delay_ms(200); //延时
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



