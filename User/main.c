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

int main()
{
    HAL_Init();
    sys_stm32_clock_init(168, 4, 2, 4 );  /* 设置时钟，168MKHZ */
    usart_init(84, 115200);
    led_init();
    delay_init(168);
    
    while(1)
    {
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET);
        delay_ms(200);
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_RESET);
        delay_ms(200);
    }

}
