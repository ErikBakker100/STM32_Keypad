#ifndef	_KEYPAD_H
#define	_KEYPAD_H

#include <main.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
  Author:     Nima Askari
  WebSite:    http://www.github.com/NimaLTD
  Instagram:  http://instagram.com/github.NimaLTD
  Youtube:    https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw
  
  Version:    1.0.0
  
  
  Reversion History:
  
  (1.0.0)
  First Release.
*/

/**
 * Select Column Pins as output SET and Row Pins as pullup interrupt with rising edge trigger.
 * Config your KeyPadConfig.h.
 * Call KeyPad_Init() function after startup.
 * You can use read keyPad with KeyPad_Key() function.
 * Returned value : 0x0101,0x0201,0x0401,0x0102 and ... .High Byte is Row value,Low Byte is Column Value.
 **/

typedef struct
{
	uint8_t   ColumnSize;
	uint8_t   RowSize;
	uint16_t  LastKey;	
	
}KeyPad_t;

void      	KeyPad_Init(void);
uint16_t	KeyPad_Key(void);
void 		KeyPad_Get(char*);

#endif


