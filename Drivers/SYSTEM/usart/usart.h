/**
 ****************************************************************************************************
 * @file        usart.h
 * @author      Reenrr
 * @version     V1.1
 * @date        2024-12-19
 * @brief       串口初始化代码(一般是串口1)，支持printf
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 */

#ifndef _USART_H
#define _USART_H

#include "stdio.h"
#include "./SYSTEM/sys/sys.h"


/*******************************************************************************************************/
/* 引脚 和 串口 定义 
 * 默认是针对USART1的.
 * 注意: 通过修改这12个宏定义,可以支持USART1~UART7任意一个串口.
 */
#define USART1_TXRX_GPIO_CLK_ENABLE()          do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

#define USART1_TXRX_GPIO_PORT                  GPIOA
#define USART1_TX_GPIO_PIN                     GPIO_PIN_9
#define USART1_RX_GPIO_PIN                     GPIO_PIN_10
#define USART1_TXRX_GPIO_AF                    GPIO_AF7_USART1
 
/*******************************************************************************************************/

#define USART_REC_LEN   200                     /* 定义最大接收字节数 200 */
#define USART_EN_RX     1                       /* 使能（1）/禁止（0）串口1接收 */
#define RXBUFFERSIZE    1                       /* 缓存大小 */

extern UART_HandleTypeDef g_uart1_handle;       /* UART句柄 */

extern uint8_t  g_usart_rx_buf[USART_REC_LEN];  /* 接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 */
extern uint16_t g_usart_rx_sta;                 /* 接收状态标记 */
extern uint8_t g_rx_buffer[RXBUFFERSIZE];       /* HAL库USART接收Buffer */


void usart_init(uint32_t baudrate);             /* 串口初始化函数 */

#endif







