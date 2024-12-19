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
#include "./BSP/EXTI/exti.h"

int main()
{
    uint8_t len = 0;
    uint16_t times = 0;
    
    HAL_Init();
    sys_stm32_clock_init(168, 4, 2, 4 );  /* ����ʱ�ӣ�168MKHZ */
    usart_init(115200);
    led_init();
    key_init();
    delay_init(168);
    exti_init();
    
    while(1)
    {
        if (g_usart_rx_sta & 0x8000)
        {
            len = g_usart_rx_sta & 0x3FFF;
            printf("\r\n�����͵���ϢΪ��\r\n");
            
            HAL_UART_Transmit(&g_uart1_handle, (uint8_t*)g_usart_rx_buf, len, 1000);
            while (__HAL_UART_GET_FLAG(&g_uart1_handle, UART_FLAG_TC) != 1);          /* �ȴ����ͽ��� */
            printf("\r\n\r\n");
            g_usart_rx_sta = 0;
        }
        else
        {
            times++;
            if (times % 5000 == 0)
            {
                printf("\r\nSTM32������ ����ʵ��\r\n");
            }
            
            if (times % 200 == 0)
            {
                printf("���������ݣ��Իس�������\r\n");
            }
            
            if (times % 30 == 0)
            {
                HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
            }
            
            delay_ms(10);
        }
    }
}
