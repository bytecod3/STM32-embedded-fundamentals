/*
 * bootloader.c
 *
 *  Created on: Aug 24, 2026
 *      Author: edwin
 */
#include "bootloader_jump.h"
#include "app_header.h"

#define APP_MAGIC_NUMBER 	(0xDEADBEEF)

typedef void(*p_function)(void);

/**
 * validate the application metadata
 */
int bootloader_validate_app() {
	uint32_t HEADER_ADDR = APP_HEADER_ADDR;
	const app_header_t* app_hdr = (const app_header*) HEADER_ADDR;

	// 1. check magic number
	if(app_hdr->magic != APP_MAGIC_NUMBER) {
		return 1;
	}

	// 2. check reset handler validity
	uint32_t  rst_handler = *(volatile uint32_t*)(APP_START_ADDR + 4);
	if(( rst_handler & 0xFF000000) != 0x08000000) {
		return 2;
	}

	// app is valid, return 0
	return 0;
}

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
	// allows the application to run from its own stack
	__set_MSP(app_stack);

	// jump to application
	app_entry();
}
