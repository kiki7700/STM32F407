/**
 ****************************************************************************************************
 * @file        exti.h
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       �ⲿ�жϴ���
 ****************************************************************************************************
 */
 
#ifndef __EXTI_H
#define __EXTI_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* �жϷ��������� */
#define WKUP_IRQn                  EXTI0_IRQn
#define KEY0_IRQn                  EXTI4_IRQn
#define KEY1_IRQn                  EXTI3_IRQn
#define KEY2_IRQn                  EXTI2_IRQn

#define WKUP_IRQHandler            EXTI0_IRQHandler
#define KEY0_IRQHandler            EXTI4_IRQHandler
#define KEY1_IRQHandler            EXTI3_IRQHandler
#define KEY2_IRQHandler            EXTI2_IRQHandler

/******************************************************************************************/
/* �������� */
void exti_init(void);

#endif
