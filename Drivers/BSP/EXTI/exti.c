/**
 ****************************************************************************************************
 * @file        exti.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       外部中断代码
 ****************************************************************************************************
 */
 
 #include "./BSP/EXTI/exti.h"
 #include "./SYSTEM/delay/delay.h"
 #include "./BSP/LED/led.h"
 #include "./BSP/KEY/key.h"

/**
 * @brief       初始化EXTI相关IO口，并使能时钟;设置中断优先级，使能中断
 * @param       无
 * @retval      无
 */
void exti_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    
    WKUP_GPIO_CLK_ENABLE();
    KEY_GPIO_CLK_ENABLE();
    
    gpio_init_struct.Pin = WKUP_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_IT_RISING;
    gpio_init_struct.Pull = GPIO_PULLDOWN;
    
    gpio_init_struct.Pin = KEY0_GPIO_PIN | KEY1_GPIO_PIN | KEY2_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_IT_FALLING;
    gpio_init_struct.Pull = GPIO_PULLUP;
    
    HAL_GPIO_Init(WKUP_GPIO_PORT, &gpio_init_struct);
    HAL_GPIO_Init(KEY_GPIO_PORT, &gpio_init_struct);
    
    HAL_NVIC_SetPriority(KEY0_IRQn, 0, 2);
    HAL_NVIC_EnableIRQ(KEY0_IRQn);
    
    HAL_NVIC_SetPriority(KEY1_IRQn, 1, 2);
    HAL_NVIC_EnableIRQ(KEY1_IRQn);
    
    HAL_NVIC_SetPriority(KEY2_IRQn, 2, 2);
    HAL_NVIC_EnableIRQ(KEY2_IRQn);
    
    HAL_NVIC_SetPriority(WKUP_IRQn, 3, 2);
    HAL_NVIC_EnableIRQ(WKUP_IRQn);
}

/**
 * @brief       KEY0外部中断服务函数
 * @param       无
 * @retval      无
 */
void KEY0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY0_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY0_GPIO_PIN);
}

/**
 * @brief       KEY1外部中断服务函数
 * @param       无
 * @retval      无
 */
void KEY1_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY1_GPIO_PIN);
}

/**
 * @brief       KEY2外部中断服务函数
 * @param       无
 * @retval      无
 */
void KEY2_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY2_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY2_GPIO_PIN);
}

/**
 * @brief       WKUP外部中断服务函数
 * @param       无
 * @retval      无
 */
void WKUP_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(WKUP_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(WKUP_GPIO_PIN);
}

/**
 * @brief       EXTI中断回调函数
 * @param       无
 * @retval      无
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    delay_ms(20);             /* 消抖 */
    
    switch (GPIO_Pin)
    {
        case KEY0_GPIO_PIN:
            if(KEY0 == 0)
            {
                HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
            }
            break;
        case KEY1_GPIO_PIN:
            if(KEY1 == 0)
            {
                HAL_GPIO_TogglePin(LED_GPIO_PORT, LED1_GPIO_PIN);
            }
            break;
        case KEY2_GPIO_PIN:
            if(KEY2 == 0)
            {
                HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
                HAL_GPIO_TogglePin(LED_GPIO_PORT, LED1_GPIO_PIN);
            }
            break;
        default : break;
    }
    
//    if (GPIO_Pin == KEY0_GPIO_PIN)
//    {
//        if(HAL_GPIO_ReadPin(KEY_GPIO_PORT, KEY0_GPIO_PIN) == 0)
//        {
//            HAL_GPIO_TogglePin(LED_GPIO_PORT, LED0_GPIO_PIN);
//        }
//    }
}


