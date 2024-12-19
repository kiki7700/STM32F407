/**
 ****************************************************************************************************
 * @file        wdg.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-19
 * @brief       看门狗代码
 ****************************************************************************************************
 */
 
#include "./BSP/WDG/wdg.h"

IWDG_HandleTypeDef g_iwdg_handle;

/**
 * @brief       初始化IWDG
 * @param       prer:分频系数
                rlr：重装载值
 * @retval      无
 */
void iwdg_init(uint8_t prer, uint16_t rlr)
{
    g_iwdg_handle.Instance = IWDG;
    g_iwdg_handle.Init.Prescaler = prer;
    g_iwdg_handle.Init.Reload = rlr;
    
    HAL_IWDG_Init(&g_iwdg_handle);
}

/**
 * @brief       IWDG喂狗函数
 * @param       无
 * @retval      无
 */
void iwdg_feed(void)
{
    HAL_IWDG_Refresh(&g_iwdg_handle);
}
