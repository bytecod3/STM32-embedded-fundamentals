## Introduction
This project builds a production-ready UART driver for STM32 with the following features:
- UART
- Interrupt driven RX/TX
- Circular Buffer
- printf support
- non-blocking API

### Requirements 
- The driver shall abstract UART using custom API calls
- The driver shall provide API for calling interrupt driven UART TX
- The driver shall provide API for calling interrupts driven UART RX
- The driver shall provide API for calling printf with custom message 
- The driver shall provide API for flushing the UART buffer
- The driver shall be implemented using a ring buffer 
- The driver shall be STM32-board-agnostic for portability 

