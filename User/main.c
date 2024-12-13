/**
 ****************************************************************************************************
 * @file        main.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       STM32F407功能实现
 ****************************************************************************************************
 */

#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/usart/usart.h"
#include "./BSP/LED/led.h"
#include "./BSP/KEY/key.h"
#include "./BSP/EXTI/exti.h"

int main()
{
    HAL_Init();
    sys_stm32_clock_init(168, 4, 2, 4 );  /* 设置时钟，168MKHZ */
    usart_init(84, 115200);
    led_init();
    key_init();
    delay_init(168);
    exti_init();
    
    while(1)
    {
        delay_ms(500);
    }
}
