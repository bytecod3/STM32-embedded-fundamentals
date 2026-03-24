/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define NS_GREEN_PIN 0
#define NS_YELLOW_PIN 1
#define NS_RED_PIN 	2
#define EW_GREEN_PIN	3
#define EW_YELLOW_PIN 4
#define EW_RED_PIN 5

/*
 * state enumeration
 */
typedef enum {
	NS_GREEN, NS_YELLOW, NS_RED,
	EW_GREEN, EW_YELLOW, EW_RED
} TrafficState;

// state durations in seconds
const uint8_t state_durations[] = {30, 5, 35, 30, 5, 35};

// global variables
volatile uint32_t timer_count = 0;
TrafficState current_state = NS_GREEN; /* starting state */

/* allow setting of a GPIO state */
void gpio_set(uint8_t pin, uint8_t value)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

/* timer init 1 second */
void timer_init() {

}

/* set LEDs based on the state */
void set_leds(TrafficState state) {
	/* reset all GPIOs to 0 */
	HAL_GPIO_WritePin(ns_green_GPIO_Port, ns_green_Pin, 0);
	HAL_GPIO_WritePin(ns_yellow_GPIO_Port, ns_green_Pin, 0);
	HAL_GPIO_WritePin(ns_red_GPIO_Port, ns_green_Pin, 0);
	HAL_GPIO_WritePin(ew_green_GPIO_Port, ns_green_Pin, 0);
	HAL_GPIO_WritePin(ew_yellow_GPIO_Port, ns_green_Pin, 0);
	HAL_GPIO_WritePin(ew_red_GPIO_Port, ns_green_Pin, 0);

	/* switch LEDs based on state */
	switch (state) {
		case NS_GREEN:
			HAL_GPIO_WritePin(ns_green_GPIO_Port, ns_green_Pin, 1);
			HAL_GPIO_WritePin(ew_red_GPIO_Port, ew_red_Pin, 1);
			break;

		case NS_YELLOW:
			HAL_GPIO_WritePin(ns_yellow_GPIO_Port, ns_yellow_Pin, 1);
			HAL_GPIO_WritePin(ew_red_GPIO_Port, ew_red_Pin, 1);
			break;

		case NS_RED:
			HAL_GPIO_WritePin(ns_red_GPIO_Port, ns_red_Pin, 1);
			HAL_GPIO_WritePin(ew_green_GPIO_Port, es_green_Pin, 1);
			break;

		case EW_RED:
			HAL_GPIO_WritePin(ew_red_GPIO_Port, es_red_Pin, 1);
			HAL_GPIO_WritePin(ns_green_GPIO_Port, ns_green_Pin, 1);
			break;

		case EW_YELLOW:
			HAL_GPIO_WritePin(ew_yellow_GPIO_Port, es_yellow_Pin, 1);
			HAL_GPIO_WritePin(ns_red_GPIO_Port, ns_red_Pin, 1);
			break;

		case EW_GREEN:
			HAL_GPIO_WritePin(ew_green_GPIO_Port, es_green_Pin, 1);
			HAL_GPIO_WritePin(ns_red_GPIO_Port, ns_red_Pin, 1);
			break;
	}

}

/* get next state */
TrafficState get_next_state(TrafficState state) {
	switch (state) {
		case NS_GREEN: return NS_YELLOW;
		case NS_YELLOW: return NS_RED;
		case EW_GREEN: return EW_YELLOW;
		case EW_YELLOW: return EW_RED;
	}

	/* fallback */
	return NS_GREEN;
}

/* timer interrupt handler */
void timer_isr(void) {
	timer_count++;
}

/* finite starte machine logic */
void traffic_light_fsm(void) {
	if (timer_count >= state_durations[current_state]) {
		set_leds(current_state);
		current_state = get_next_state(current_state);
		timer_count = 0;
	}

}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  timer_init();
  set_leds(current_state);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	 traffic_light_fsm();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ew_red_GPIO_Port, ew_red_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, ew_yellow_Pin|ew_green_Pin|ns_red_Pin|ns_yellow_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ns_green_GPIO_Port, ns_green_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : ew_red_Pin */
  GPIO_InitStruct.Pin = ew_red_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ew_red_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ew_yellow_Pin ew_green_Pin ns_red_Pin ns_yellow_Pin */
  GPIO_InitStruct.Pin = ew_yellow_Pin|ew_green_Pin|ns_red_Pin|ns_yellow_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : ns_green_Pin */
  GPIO_InitStruct.Pin = ns_green_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ns_green_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
