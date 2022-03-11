#include "terminal.h"

static	uint8_t			amount_of_buffers;
RING_BUFF_InitTypeDef*	buffers;

int __io_putchar(uint8_t ch)
{
	send_byte(USART1,ch);
	return ch;
}

void	init_terminal(USART_TypeDef	*USARTx)
{
	init_usart_gpio(USARTx);
	init_usart(USARTx);
}

void	create_ring_buff(uint8_t	buff_size)
{
	RING_BUFF_InitTypeDef	temp_Buff[++amount_of_buffers];
}

void	send_byte(USART_TypeDef	*USARTx, uint8_t data)
{
	while(!USART_GetFlagStatus(USARTx, USART_FLAG_TXE));
	USART_SendData(USARTx, data);
}

void	read_byte(USART_TypeDef	*USARTx, uint8_t* data)
{
	while(!USART_GetFlagStatus(USARTx, USART_FLAG_RXNE));
	*data = USART_ReceiveData(USARTx);
}

void	USART1_IRQHandler(void)
{
}
