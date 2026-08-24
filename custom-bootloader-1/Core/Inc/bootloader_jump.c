/*
 * bootloader.c
 *
 *  Created on: Aug 24, 2026
 *      Author: edwin
 */
#include "bootloader_jump.h"

typedef void(*p_function)(void);

void jump_to_application(void) {
	uint32_t app_stack;
	uint32_t app_reset_handler;
	p_function app_entry;

	// read application stack pointer
	app_stack = *(volatile uint32_t*)APP_START_ADDR;

	// read reset handler address
	app_reset_handler = *(volatile uint32_t*)(APP_START_ADDR + 4);
	app_entry = (p_function)app_reset_handler;

	// disable interrupts
	__disable_irq();

	// stop systick
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	// set main stack pointer
	__set_MSP(app_stack);

	// jump to application
	app_entry();


}
