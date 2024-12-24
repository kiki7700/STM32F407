/**
 ****************************************************************************************************
 * @file        btim.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-19
 * @brief       基本定时器代码
 ****************************************************************************************************
 */
 
#include "./BSP/TIMER/btim.h"
#include "./BSP/LED/led.h"
#include "./SYSTEM/usart/usart.h"

TIM_HandleTypeDef g_timx_handle;

/**
 * @brief       初始化基本定时器
 * @param       arr：自动重装载值
                psc：分频系数
 * @retval      无
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
 * @brief       基本定时器底层初始化函数
 * @param       htim：基础定时器句柄类型指针
 * @retval      无
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
 * @brief       基本定时器6中断服务函数
 * @param       无
 * @retval      无
 */
void TIM6_DAC_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&g_timx_handle);
}

/**
 * @brief       基本定时器6溢出中断中断回调函数
 * @param       无
 * @retval      无
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
            printf("输出串口信息\r\n");
            time = 0;
        }
    }
}
