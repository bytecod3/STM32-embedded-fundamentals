/*
 * flash_layout.h
 *
 *  Created on: Aug 24, 2026
 *      Author: edwin
 */

#ifndef INC_FLASH_LAYOUT_H_
#define INC_FLASH_LAYOUT_H_



#include "stm32f1xx.h"

// define the start of a flash region
#define BOOTLDR_START_ADDR		(0x08000000)
#define APP_HEADER_ADDR 			(0x08004000)
#define APP_START_ADDR			(0x08004400)

#endif /* INC_FLASH_LAYOUT_H_ */
