/*
 * max31865.c
 *
 *  Created on: Aug 23, 2026
 *      Author: edwin
 */
#include "max31865.h"

/**
 * @brief initialize the IC
 */
HAL_StatusTypeDef max31865_init(uint8_t mode) {
	uint8_t config_val = 0x00;

	/**
	 *  by default, set as follows
	 *  vbias on
	 *  conversion mode auto
	 *  3-wire if mode == 1, 2/4 wire if mode == 0
	 *	50 hertz conversion
	 *
	 *  */

	config_val = config_val | (1 << CONVERSION_MODE_BIT) | (1 << FILTER_SELECT_BIT);


}


