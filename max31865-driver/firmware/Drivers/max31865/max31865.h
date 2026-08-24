/*
 * max31865.h
 *
 *  Created on: Aug 23, 2026
 *      Author: edwin
 */

#ifndef MAX31865_MAX31865_H_
#define MAX31865_MAX31865_H_

#include "stm32f4xx.h"

////////////////// register addresses
#define CONFIG_REG 						(0x00)
#define RTD_MSB_REG						(0x01)
#define RTD_LSB_REG						(0x02)
#define HIGH_FAULT_THRESHOLD_MSB_REG		(0x03)
#define HIGH_FAULD_THRESHOLD_LSB_REG		(0x04)
#define LOW_FAULT_THRESHOLD_MSB_REG		(0x05)
#define LOW_FAULT_THRESHOLD_LSB_REG		(0x06)
#define FAULT_STATUS_REG

////////////////// settings
#define THREE_WIRE_MODE			(1)
#define TWO_WIRE					(0)
#define FOUR_WIRE				(0)
#define PRECISION_MODE			(1)

#define BIAS_BIT					(7)		// 1 enables bias, 0 turn it off
#define CONVERSION_MODE_BIT   	(6)		// 1 sets automatic conversion, 0 sets Normally off
#define ONE_SHOT_BIT				(5)		// if Normally Off, write 1 to start conversion
#define WIRE_COUNT_BIT			(4)		// set 1 for 3-wire, 0 for 2-wire and 4-wire
#define FAULT_DETECT_BIT_1		(3)		//
#define FAULT_DETECT_BIT_0		(2)		//
#define FAULT_STATUS_CLEAR_BIT 	(1)
#define FILTER_SELECT_BIT		(0)		// set 1 for 50Hz, 0 for 60Hz

////////////////// function declarations
HAL_StatusTypeDef max31865_init(uint8_t mode);
float max31865_read_temperature();

////////////////// communication functions
HAL_StatusTypeDef spi_send_byte(uint8_t b);
HAL_StatusTypeDef spi_receive_byte(uint8_t* data);



#endif /* MAX31865_MAX31865_H_ */
