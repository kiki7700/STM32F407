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

int main()
{
    uint8_t key;
    
    HAL_Init();
    sys_stm32_clock_init(168, 4, 2, 4 );  /* 设置时钟，168MKHZ */
    usart_init(84, 115200);
    led_init();
    key_init();
    delay_init(168);
    
    while(1)
    {
        key = key_scan(0);                /* 得到键值 */
        
        if (key)
        {
            switch (key)
            {
                case KEY0_PRES:           /* 控制LED0翻转 */
                    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
                    break;
                case KEY1_PRES:           /* 控制LED1翻转 */
                    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED1_GPIO_PIN);
                    break;
                case KEY2_PRES:           /* 控制LED0、LED1翻转 */
                    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
                    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED1_GPIO_PIN);
                    break;
                default : break;
            }
        }
        else
        {
            delay_ms(10);
        }
    }
}
