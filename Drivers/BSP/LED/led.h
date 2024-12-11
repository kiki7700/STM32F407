/**
 ****************************************************************************************************
 * @file        led.h
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       LED驱动代码
 ****************************************************************************************************
 */

#ifndef __LED_H
#define __LED_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* 引脚定义 */
#define LED_GPIO_PORT              GPIOF
#define LED0_GPIO_PIN              GPIO_PIN_9
#define LED1_GPIO_PIN              GPIO_PIN_10
#define LED_GPIO_CLK_ENABLE()      do{ __HAL_RCC_GPIOF_CLK_ENABLE(); }while(0)

void led_init(void);

#endif
