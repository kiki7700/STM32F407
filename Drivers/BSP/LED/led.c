/**
 ****************************************************************************************************
 * @file        led.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       LED驱动代码
 ****************************************************************************************************
 */
 
#include "./BSP/LED/led.h"

/**
 * @brief       初始化LED相关IO口，并使能时钟
 * @param       无
 * @retval      无
 */
void led_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    
    LED_GPIO_CLK_ENABLE();
    
    gpio_init_struct.Pin = LED0_GPIO_PIN | LED1_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(LED_GPIO_PORT, &gpio_init_struct);
    
    HAL_GPIO_WritePin(LED_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET);

}
