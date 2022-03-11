#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "stm32f4xx_usart.h"
#include "usart_periph.h"
#include "gpio_periph.h"
#include "stdio.h"

#define		MAX_BUFF_SIZE	0x08

typedef struct
{
	uint8_t				states;
	uint8_t 			buff_size;
	uint8_t*			buffer;
	uint8_t				tail_b;
	uint8_t				head_b;
}RING_BUFF_InitTypeDef;

void	init_terminal(USART_TypeDef	*USARTx);
void	printf_new(uint8_t* data);
void	send_byte(USART_TypeDef	*USARTx, uint8_t data);
void	read_byte(USART_TypeDef	*USARTx, uint8_t* data);

#endif /* TERMINAL_H_ */
