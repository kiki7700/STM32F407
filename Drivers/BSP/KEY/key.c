/**
 ****************************************************************************************************
 * @file        key.c
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       KEY��������
 ****************************************************************************************************
 */
 
#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

/**
 * @brief       ��ʼ��KEY���IO�ڣ���ʹ��ʱ��
 * @param       ��
 * @retval      ��
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
 * @brief       ����ɨ�躯��
 * @param       mode:0 / 1, ���庬������:
 *   @arg       0,  ��֧��������(���������²���ʱ, ֻ�е�һ�ε��û᷵�ؼ�ֵ,
 *                  �����ɿ��Ժ�, �ٴΰ��²Ż᷵��������ֵ)
 *   @arg       1,  ֧��������(���������²���ʱ, ÿ�ε��øú������᷵�ؼ�ֵ)
 * @retval      ��ֵ, ��������:
 *              KEY0_PRES, 1, KEY0����
 *              KEY1_PRES, 2, KEY1����
 *              KEY2_PRES, 3, KEY2����
 *              WKUP_PRES, 4, WKUP����
 */
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;            /* �����ɿ���־ */
    uint8_t keyval = 0;                   /* �������� */
    
    if (mode)
    {
        key_up = 1;                       /* ֧�������� */
    }
    
    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 1))
    {
        delay_ms(10);                     /* ����ȥ�� */
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
