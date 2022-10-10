/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "retarget.h"
#include <KeyPad.h>
#include <string.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI4_15_IRQn
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOF
#define LED_GREEN_Pin GPIO_PIN_5
#define LED_GREEN_GPIO_Port GPIOA
#define COL3_Pin GPIO_PIN_6
#define COL3_GPIO_Port GPIOA
#define COL2_Pin GPIO_PIN_7
#define COL2_GPIO_Port GPIOA
#define COL4_Pin GPIO_PIN_4
#define COL4_GPIO_Port GPIOC
#define ROW5_Pin GPIO_PIN_0
#define ROW5_GPIO_Port GPIOB
#define ROW5_EXTI_IRQn EXTI0_1_IRQn
#define ROW4_Pin GPIO_PIN_14
#define ROW4_GPIO_Port GPIOB
#define ROW4_EXTI_IRQn EXTI4_15_IRQn
#define COL1_Pin GPIO_PIN_8
#define COL1_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define ROW1_Pin GPIO_PIN_3
#define ROW1_GPIO_Port GPIOB
#define ROW1_EXTI_IRQn EXTI2_3_IRQn
#define ROW3_Pin GPIO_PIN_4
#define ROW3_GPIO_Port GPIOB
#define ROW3_EXTI_IRQn EXTI4_15_IRQn
#define ROW2_Pin GPIO_PIN_5
#define ROW2_GPIO_Port GPIOB
#define ROW2_EXTI_IRQn EXTI4_15_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
