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
 * 5 窗口看门狗
 * 6 定时器6,配置为500ms中断一次,在中断里面进行LED0翻转。

 ***************************************************************************************************
 * 实验现象
 * 1 LED0用于定时器中断取反,指示定时器中断状态,500ms变更一次状态。

 ***************************************************************************************************
 * 注意事项
 * 1 电脑端串口调试助手波特率调节到与本程序相同的115200bps
 * 2 请使用XCOM/SSCOM串口调试助手,其他串口助手可能控制DTR/RTS导致MCU复位/程序不运行
 * 3 串口输入字符串以回车换行结束
 * 4 请用USB线连接在USB_UART,找到USB转串口后测试本例程
 * 5 排针P10的PA9/PA10必须通过跳线帽连接在RXD/TXD上
 
 ***********************************************************************************************************
 */