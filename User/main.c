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
    wwdg_init(0x7f, 0x5f, WWDG_PRESCALER_8);
    
    if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET)
    {
        printf("窗口看门狗复位\r\n");
        __HAL_RCC_CLEAR_RESET_FLAGS();
    }
    else
    {
        printf("外部复位\r\n");
    }
    
    printf("请在窗口期内喂狗\r\n\r\n");
    
    while(1)
    {
        delay_ms(45);
    }
}
