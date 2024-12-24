/**
 ****************************************************************************************************
 * @file        btim.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-19
 * @brief       ������ʱ������
 ****************************************************************************************************
 */
 
#include "./BSP/TIMER/btim.h"
#include "./BSP/LED/led.h"
#include "./SYSTEM/usart/usart.h"

TIM_HandleTypeDef g_timx_handle;

/**
 * @brief       ��ʼ��������ʱ��
 * @param       arr���Զ���װ��ֵ
                psc����Ƶϵ��
 * @retval      ��
 */
void btim_timx_init(uint16_t arr, uint16_t psc)
{
    g_timx_handle.Instance = TIM6;
    g_timx_handle.Init.Period = arr;
    g_timx_handle.Init.Prescaler = psc;
    
    HAL_TIM_Base_Init(&g_timx_handle);
    
    HAL_TIM_Base_Start_IT(&g_timx_handle);
}

/**
 * @brief       ������ʱ���ײ��ʼ������
 * @param       htim��������ʱ���������ָ��
 * @retval      ��
 */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM6)
    {
        __HAL_RCC_TIM6_CLK_ENABLE();
        HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 1, 3);
        HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
    }
}

/**
 * @brief       ������ʱ��6�жϷ�����
 * @param       ��
 * @retval      ��
 */
void TIM6_DAC_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&g_timx_handle);
}

/**
 * @brief       ������ʱ��6����ж��жϻص�����
 * @param       ��
 * @retval      ��
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM6)
    {
        static uint8_t time = 0;
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
        time++;
        if(time == 10)
        {
            printf("���������Ϣ\r\n");
            time = 0;
        }
    }
}
