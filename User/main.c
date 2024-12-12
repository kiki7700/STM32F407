/**
 ****************************************************************************************************
 * @file        main.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       STM32F407����ʵ��
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
    sys_stm32_clock_init(168, 4, 2, 4 );  /* ����ʱ�ӣ�168MKHZ */
    usart_init(84, 115200);
    led_init();
    key_init();
    delay_init(168);
    
    while(1)
    {
        key = key_scan(0);                /* �õ���ֵ */
        
        if (key)
        {
            switch (key)
            {
                case KEY0_PRES:           /* ����LED0��ת */
                    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
                    break;
                case KEY1_PRES:           /* ����LED1��ת */
                    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED1_GPIO_PIN);
                    break;
                case KEY2_PRES:           /* ����LED0��LED1��ת */
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
