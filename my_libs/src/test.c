#include "test.h"

void	blink_init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	GPIO_InitTypeDef	pins;
	pins.GPIO_Pin	=	GPIO_Pin_6;
	pins.GPIO_Mode	=	GPIO_Mode_OUT;
	GPIO_Init(GPIOF, &pins);
}

void	blink(void)
{
	GPIO_ToggleBits(GPIOF, GPIO_Pin_6);
//	GPIOF->BSRR	=	GPIO_BSRR_BS6;
//	GPIO_SetBits(GPIOF, GPIO_Pin_6);
	Delay(1000);
//	GPIOF->BSRR	=	GPIO_BSRR_BR6;
//	GPIO_ResetBits(GPIOF, GPIO_Pin_6);
//	Delay(1000);
}
