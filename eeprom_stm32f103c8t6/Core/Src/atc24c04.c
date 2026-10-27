/*
 * eeprom.c
 *
 *  Created on: Oct 27, 2026
 *      Author: edwin.mwiti
 */


#include "atc24c04.h"
#include "math.h"

void EEPROM_write(
	uint8_t page,
	uint16_t offset,
	uint8_t* data,
	uint16_t size
) {
	// find out the number of bit where page addressing starts
	int paddr_position = log(PAGE_SIZE) / log(2);

	// calculate the start and end page
	uint16_t start_page = page;
	uint16_t end_page = page + ((size + offset) / PAGE_SIZE);

	// number of pages to be written
	uint16_t num_of_page = (end_page - start_page) + 1;
	uint16_t pos = 0;

	// write the data
	for (int i = 0; i < num_of_page; i++) {
		uint16_t mem_address = start_page << paddr_position | offset;		// calculate the address of the memory location
		uint16_t bytes_remaining = bytestowrite(size, offset);

		HAL_I2C_MEM_Write(
				EEPROM_I2C,
				EEPROM_ADDRESS,
				mem_address,
				2,
				&data[pos],
				bytes_remaining,
				1000
				);		// write data

		start_page = start_page + 1;
		offset = 0;
		size = size - bytes_remaining;
		pos = pos + bytes_remaining;

		HAL_Delay(5);
	}



}
