/**
 ****************************************************************************************************
 * @file        wdg.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-19
 * @brief       ���Ź�����
 ****************************************************************************************************
 */
 
#include "./BSP/WDG/wdg.h"
#include "./BSP/LED/led.h"

IWDG_HandleTypeDef g_iwdg_handle;
WWDG_HandleTypeDef g_wwdg_handle;

/**
 * @brief       ��ʼ��IWDG
 * @param       prer:��Ƶϵ��
                rlr����װ��ֵ
 * @retval      ��
 */
void iwdg_init(uint8_t prer, uint16_t rlr)
{
    g_iwdg_handle.Instance = IWDG;
    g_iwdg_handle.Init.Prescaler = prer;
    g_iwdg_handle.Init.Reload = rlr;
    
    HAL_IWDG_Init(&g_iwdg_handle);
}

/**
 * @brief       IWDGι������
 * @param       ��
 * @retval      ��
 */
void iwdg_feed(void)
{
    HAL_IWDG_Refresh(&g_iwdg_handle);
}

/**
 * @brief       ��ʼ��WWDG
 * @param       tr��������
                wr������ֵ
                fprer����Ƶϵ��
 * @retval      ��
 */
void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
    g_wwdg_handle.Instance = WWDG;
    g_wwdg_handle.Init.Counter = tr;
    g_wwdg_handle.Init.Window = wr;
    g_wwdg_handle.Init.Prescaler = fprer;
    g_wwdg_handle.Init.EWIMode = WWDG_EWI_ENABLE;
    
    HAL_WWDG_Init(&g_wwdg_handle);
}

/**
 * @brief       WWDG�ײ��ʼ������
 * @param       hwwdg ��WWDG�������ָ��
 * @note        �˺����ᱻHAL_UART_Init()����
 * @retval      ��
 */
void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
    __HAL_RCC_WWDG_CLK_ENABLE();
    
    HAL_NVIC_SetPriority(WWDG_IRQn, 2, 1);
    HAL_NVIC_EnableIRQ(WWDG_IRQn);
}

/**
 * @brief       WWDG�жϷ�����
 * @param       hwwdg ��WWDG�������ָ��
 * @retval      ��
 */
void WWDG_IRQHandler(WWDG_HandleTypeDef *hwwdg)
{
    HAL_WWDG_IRQHandler(&g_wwdg_handle);
}

/**
 * @brief       WWDG��ǰ�����жϻص�����
 * @param       hwwdg ��WWDG�������ָ��
 * @retval      ��
 */
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
    HAL_WWDG_Refresh(&g_wwdg_handle);
    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
}
