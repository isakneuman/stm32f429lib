#include "usart_periph.h"

void	init_usart(USART_TypeDef	*USARTx)
{
	USART_InitTypeDef	USART_current;
	USART_StructInit(&USART_current);
//	USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);

	USART_Init(USARTx, &USART_current);
	USART_Cmd(USARTx, ENABLE);
}
