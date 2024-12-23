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

extern WWDG_HandleTypeDef g_wwdg_handle;

void iwdg_init(uint8_t prer, uint16_t rlr);
void iwdg_feed(void);
void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer);

#endif
