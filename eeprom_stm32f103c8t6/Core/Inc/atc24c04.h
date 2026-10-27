/*
 * atc24c04.h
 *
 *  Created on: Oct 27, 2026
 *      Author: edwin.mwiti
 */

#ifndef ATC24C04_H_
#define ATC24C04_H_

#include "main.h"

extern I2C_HandleTypeDef hi2c1;
#define EEPROM_I2C &hi2c1

#define EEPROM_ADDRESS 0xA0

#define PAGE_SIZE 16	// page size
#define PAGE_NUM 32 // num of pages

void EEPROM_write(
	uint8_t page,
	uint16_t offset,
	uint8_t* data,
	uint16_t size
);

#endif /* ATC24C04_H_ */
