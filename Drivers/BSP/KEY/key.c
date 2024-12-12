/**
 ****************************************************************************************************
 * @file        key.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       KEY驱动代码
 ****************************************************************************************************
 */
 
#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

/**
 * @brief       初始化KEY相关IO口，并使能时钟
 * @param       无
 * @retval      无
 */
void key_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    
    WKUP_GPIO_CLK_ENABLE();
    KEY_GPIO_CLK_ENABLE();
    
    gpio_init_struct.Pin = WKUP_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_PULLUP;
    
    gpio_init_struct.Pin = KEY0_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_PULLUP;    
    
    gpio_init_struct.Pin = KEY1_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_PULLUP;    
    
    gpio_init_struct.Pin = KEY2_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_PULLUP;
    
    HAL_GPIO_Init(WKUP_GPIO_PORT, &gpio_init_struct);
    HAL_GPIO_Init(KEY_GPIO_PORT, &gpio_init_struct);

}

/**
 * @brief       按键扫描函数
 * @param       mode:0 / 1, 具体含义如下:
 *   @arg       0,  不支持连续按(当按键按下不放时, 只有第一次调用会返回键值,
 *                  必须松开以后, 再次按下才会返回其他键值)
 *   @arg       1,  支持连续按(当按键按下不放时, 每次调用该函数都会返回键值)
 * @retval      键值, 定义如下:
 *              KEY0_PRES, 1, KEY0按下
 *              KEY1_PRES, 2, KEY1按下
 *              KEY2_PRES, 3, KEY2按下
 *              WKUP_PRES, 4, WKUP按下
 */
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;            /* 按键松开标志 */
    uint8_t keyval = 0;                   /* 按键类型 */
    
    if (mode)
    {
        key_up = 1;                       /* 支持连续按 */
    }
    
    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 1))
    {
        delay_ms(10);                     /* 按键去抖 */
        key_up = 0;
        
        if (KEY0 == 0)
        {
            keyval = KEY0_PRES;
        }
        if (KEY1 == 0)
        {
            keyval = KEY1_PRES;
        } 
        if (KEY2 == 0)
        {
            keyval = KEY2_PRES;
        }
        if (WK_UP == 1)
        {
            keyval = WKUP_PRES;
        }
    }
    else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0)
    {
        key_up = 1;
    }
    
    return keyval;
}
