/**
 ****************************************************************************************************
 * @file        exti.h
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-11
 * @brief       外部中断代码
 ****************************************************************************************************
 */
 
#ifndef __EXTI_H
#define __EXTI_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* 中断服务函数定义 */
#define WKUP_IRQn                  EXTI0_IRQn
#define KEY0_IRQn                  EXTI4_IRQn
#define KEY1_IRQn                  EXTI3_IRQn
#define KEY2_IRQn                  EXTI2_IRQn

#define WKUP_IRQHandler            EXTI0_IRQHandler
#define KEY0_IRQHandler            EXTI4_IRQHandler
#define KEY1_IRQHandler            EXTI3_IRQHandler
#define KEY2_IRQHandler            EXTI2_IRQHandler

/******************************************************************************************/
/* 函数声明 */
void exti_init(void);

#endif
