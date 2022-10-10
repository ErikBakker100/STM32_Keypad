#ifndef	_KEYPADCONFIG_H
#define	_KEYPADCONFIG_H
#include <main.h>

#define           _KEYPAD_DEBOUNCE_TIME_MS        20

const GPIO_TypeDef* _KEYPAD_COLUMN_GPIO_PORT[] =
{
	COL1_GPIO_Port,
	COL2_GPIO_Port,
	COL3_GPIO_Port,
	COL4_GPIO_Port
};

const uint16_t _KEYPAD_COLUMN_GPIO_PIN[] =
{
	COL1_Pin,
	COL2_Pin,
	COL3_Pin,
	COL4_Pin
};

const GPIO_TypeDef* _KEYPAD_ROW_GPIO_PORT[] =
{
	ROW1_GPIO_Port,
	ROW2_GPIO_Port,
	ROW3_GPIO_Port,
	ROW4_GPIO_Port,
	ROW5_GPIO_Port
};

const uint16_t _KEYPAD_ROW_GPIO_PIN[] =
{
	ROW1_Pin,
	ROW2_Pin,
	ROW3_Pin,
	ROW4_Pin,
	ROW5_Pin,
};

#endif
