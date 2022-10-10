#include "KeyPad.h"
#include "KeyPadConfig.h"
#define _KEYPAD_DELAY(x)      HAL_Delay(x)

KeyPad_t	KeyPad;

void Keypad_Init_Column(GPIO_PinState);
void Keypad_Init_Row_Input(void);
void Keypad_Init_Row_Interrupt(void);
//#############################################################################################
void	KeyPad_Init(void)
{
  KeyPad.ColumnSize = sizeof(_KEYPAD_COLUMN_GPIO_PIN)/2;
  KeyPad.RowSize = sizeof(_KEYPAD_ROW_GPIO_PIN)/2;
  Keypad_Init_Column(GPIO_PIN_SET);
  Keypad_Init_Row_Interrupt();
}

void Keypad_Init_Column(GPIO_PinState state) {
	GPIO_InitTypeDef	gpio = {0};
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	for(uint8_t	i=0 ; i<KeyPad.ColumnSize ; i++) {
		gpio.Pin = _KEYPAD_COLUMN_GPIO_PIN[i];
		HAL_GPIO_Init((GPIO_TypeDef*)_KEYPAD_COLUMN_GPIO_PORT[i], &gpio);
		HAL_GPIO_WritePin((GPIO_TypeDef*)_KEYPAD_COLUMN_GPIO_PORT[i], _KEYPAD_COLUMN_GPIO_PIN[i], state);
	}
}

void Keypad_Init_Row_Input(void) {
	GPIO_InitTypeDef	gpio = {0};
	gpio.Mode = GPIO_MODE_INPUT;
	gpio.Pull = GPIO_PULLDOWN;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	for(uint8_t	i=0 ; i<KeyPad.RowSize ; i++)
	{
		gpio.Pin = _KEYPAD_ROW_GPIO_PIN[i];
		HAL_GPIO_Init((GPIO_TypeDef*)_KEYPAD_ROW_GPIO_PORT[i], &gpio);
	}
}

void Keypad_Init_Row_Interrupt(void) {
	GPIO_InitTypeDef	gpio = {0};
    gpio.Mode = GPIO_MODE_IT_RISING;
    gpio.Pull = GPIO_PULLDOWN;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    for(uint8_t	i=0 ; i<KeyPad.RowSize ; i++) {
    	gpio.Pin = _KEYPAD_ROW_GPIO_PIN[i];
    	HAL_GPIO_Init((GPIO_TypeDef*)_KEYPAD_ROW_GPIO_PORT[i], &gpio);
    }
    Keypad_Init_Column(GPIO_PIN_SET);
}
//#############################################################################################
uint16_t	KeyPad_Scan(void)
{
  uint16_t  key=0;
  Keypad_Init_Row_Input();
  Keypad_Init_Column(GPIO_PIN_RESET );
  for(uint8_t c=0 ; c<KeyPad.ColumnSize ; c++)
  {
	  HAL_GPIO_WritePin((GPIO_TypeDef*)_KEYPAD_COLUMN_GPIO_PORT[c], _KEYPAD_COLUMN_GPIO_PIN[c], GPIO_PIN_SET);
        _KEYPAD_DELAY(_KEYPAD_DEBOUNCE_TIME_MS);
        for(uint8_t r=0 ; r<KeyPad.RowSize ; r++) {
		  if(HAL_GPIO_ReadPin((GPIO_TypeDef*)_KEYPAD_ROW_GPIO_PORT[r], _KEYPAD_ROW_GPIO_PIN[r]) == GPIO_PIN_SET) {
			  key |= 1<<c;
			  key |= 1<<(r+8);
		  }
        }
  	  HAL_GPIO_WritePin((GPIO_TypeDef*)_KEYPAD_COLUMN_GPIO_PORT[c], _KEYPAD_COLUMN_GPIO_PIN[c], GPIO_PIN_RESET);
  }
  Keypad_Init_Column(GPIO_PIN_SET);
  Keypad_Init_Row_Interrupt();
  return key;
}
//#############################################################################################
uint16_t	KeyPad_Key(void)
{	
  uint16_t  keyRead;
  keyRead = KeyPad_Scan();
  if(keyRead == KeyPad.LastKey) keyRead = 0;
  else KeyPad.LastKey = keyRead;
  return keyRead;
}
//#############################################################################################
void KeyPad_Get(char* button)
{
	uint16_t key = KeyPad_Key();
	switch(key) {
		case 0x0101:
			strcpy(button, "F1");
			break;
		case 0x0102:
			strcpy(button, "F2");
			break;
		case 0x0104:
			strcpy(button, "#");
			break;
		case 0x0108:
			strcpy(button, "*");
			break;
		case 0x0201:
			strcpy(button, "1");
			break;
		case 0x0202:
			strcpy(button, "2");
			break;
		case 0x0204:
			strcpy(button, "3");
			break;
		case 0x0208:
			strcpy(button, "UP");
			break;
		case 0x0401:
			strcpy(button, "4");
			break;
		case 0x0402:
			strcpy(button, "5");
			break;
		case 0x0404:
			strcpy(button, "6");
			break;
		case 0x0408:
			strcpy(button, "DWN");
			break;
		case 0x0801:
			strcpy(button, "7");
			break;
		case 0x0802:
			strcpy(button, "8");
			break;
		case 0x0804:
			strcpy(button, "9");
			break;
		case 0x0808:
			strcpy(button, "ESC");
			break;
		case 0x1001:
			strcpy(button, "LFT");
			break;
		case 0x1002:
			strcpy(button, "0");
			break;
		case 0x1004:
			strcpy(button, "RGT");
			break;
		case 0x1008:
			strcpy(button, "ENT");
			break;
		default:
			strcpy(button, "");
	}
	return;
}
