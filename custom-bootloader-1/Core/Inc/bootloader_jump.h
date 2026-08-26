/*
 * bootloader.h
 *
 *  Created on: Aug 24, 2026
 *      Author: edwin
 */

#ifndef INC_BOOTLOADER_JUMP_H_
#define INC_BOOTLOADER_JUMP_H_

#include "flash_layout.h"

int bootloader_validate_app();
void jump_to_application(void);


#endif /* INC_BOOTLOADER_JUMP_H_ */
