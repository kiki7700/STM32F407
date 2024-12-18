/**
 ***************************************************************************************************
 * 实验简介
 * 实验平台：正点原子 探索者F407开发板

 ***************************************************************************************************
 * 硬件资源及引脚分配
 * 1 LED灯
     DS0（RED）     : LED0 - PF9
     DS1（GREEN）   : LED1 - PF10
 * 2 独立按键
     KEY0    - PE4
     KEY1    - PE3
     KEY2    - PE2
     KEY_UP  - PA0  (程序中的宏名:WK_UP)
 * 3 串口1 (PA9/PA10连接在板载USB转串口芯片CH340上面)
 * 4 独立看门狗

 ***************************************************************************************************
 * 实验现象
 * 1 LED0闪烁,提示程序在运行。
 * 2 STM32通过串口1和上位机对话,STM32在收到串口助手发过来的字符串(以回车换行结束)后,会返回给串口助手。
     同时每隔一定时间,通过串口1输出一段信息，可以通过串口助手显示接收。

 ***************************************************************************************************
 * 注意事项
 * 1 电脑端串口调试助手波特率调节到与本程序相同的115200bps
 * 2 请使用XCOM/SSCOM串口调试助手,其他串口助手可能控制DTR/RTS导致MCU复位/程序不运行
 * 3 串口输入字符串以回车换行结束
 * 4 请用USB线连接在USB_UART,找到USB转串口后测试本例程
 * 5 排针P10的PA9/PA10必须通过跳线帽连接在RXD/TXD上
 
 ***********************************************************************************************************
 */