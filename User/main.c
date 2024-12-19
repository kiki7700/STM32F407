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

int main()
{
    HAL_Init();
    sys_stm32_clock_init(168, 4, 2, 4 );         /* 设置时钟，168MKHZ */
    usart_init(115200);
    led_init();
    key_init();
    delay_init(168);
    exti_init();
    delay_ms(100);
    printf("您还没喂狗，请及时喂狗！！\r\n");
    iwdg_init(IWDG_PRESCALER_16, 2000);          /* 重装载值为2000，溢出时间为1s，溢出即重启 */
    HAL_GPIO_WritePin(LED_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET);
    
    while(1)
    {
        if (key_scan(0) == WKUP_PRES)
        {
            iwdg_feed();
            printf("已经喂狗\r\n");
        }
    }
}
