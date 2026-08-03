/*
 * uart-driver.h
 *
 *  Created on: Aug 3, 2026
 *      Author: edwin
 */

#ifndef INC_UART_DRIVER_H_
#define INC_UART_DRIVER_H_

#include "stm32f1xx_hal.h"

/// initialize UART calls
void uart_init();

/// blocking UART send
HAL_StatusTypeDef uart_send();

/// blocking UART receive
void uart_receive();

/// get rid of stale UART data
void uart_flush();
void uart_receive_dma();
void uart_send_dma();
void uart_receive_intr();
void uart_receive_dma();
void uart_send_dma();


#endif /* INC_UART_DRIVER_H_ */
