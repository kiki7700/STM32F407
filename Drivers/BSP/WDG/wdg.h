/**
 ****************************************************************************************************
 * @file        wdg.h
 * @author      Reenrr
 * @version     V1.0
 * @date        2024-12-19
 * @brief       ¿´ÃÅ¹·´úÂë
 ****************************************************************************************************
 */
 
#ifndef __WDG_H
#define __WDG_H

#include "./SYSTEM/sys/sys.h"

void iwdg_init(uint8_t prer, uint16_t rlr);
void iwdg_feed(void);

#endif
