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
#include "./BSP/WDG/wdg.h"
#include "./BSP/TIMER/btim.h"

int main()
{
    HAL_Init();
    sys_stm32_clock_init(168, 4, 2, 4 );         /* 设置时钟，168MKHZ */
    usart_init(115200);
    led_init();
    key_init();
    delay_init(168);
    exti_init();
    btim_timx_init(5000 - 1, 8400 - 1);          /* 定时500ms */
    
    while(1)
    {
    }
}
