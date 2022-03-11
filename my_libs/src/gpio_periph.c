#include "gpio_periph.h"

void	init_usart_gpio(USART_TypeDef	*USARTx)
{
	GPIO_InitTypeDef	USART1_pins;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_PinAFConfig(GPIOA, 9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, 10, GPIO_AF_USART1);

	USART1_pins.GPIO_Mode	=	GPIO_Mode_AF;
	USART1_pins.GPIO_Pin	=	USART1_RX_PIN|USART1_TX_PIN;

	GPIO_Init(GPIOA,&USART1_pins);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
}

void	init_tim2_gpio(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef	pins;
	pins.GPIO_Pin	=	(1<<TIM2_CH2_PIN);
	pins.GPIO_Mode	=	GPIO_Mode_OUT;
	GPIO_PinAFConfig(TIM2_CH2_PORT, TIM2_CH2_PIN, GPIO_AF_TIM2);
	GPIO_Init(TIM2_CH2_PORT, &pins);
}

void	init_i2c1_gpio(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef pins;
	pins.GPIO_Pin	=	(1<<I2C1_SDA)|(1<<I2C1_SCL);
	pins.GPIO_Mode	=	GPIO_Mode_AF;
	pins.GPIO_PuPd	=	GPIO_PuPd_NOPULL;
	pins.GPIO_Speed	=	GPIO_Speed_50MHz;
	pins.GPIO_OType	=	GPIO_OType_OD;
	GPIO_Init(I2C1_Port, &pins);

	GPIO_PinAFConfig(I2C1_Port, I2C1_SDA, GPIO_AF_I2C1);
	GPIO_PinAFConfig(I2C1_Port, I2C1_SCL, GPIO_AF_I2C1);
}

void	init_hc_sr04_gpio(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef pins;
	pins.GPIO_Pin	=	(1<<TRIGG_PIN)|(1<<ECHO_PIN);
	pins.GPIO_Mode	=	GPIO_Mode_AF;
	GPIO_Init(ULTRA_SOUND_Port, &pins);

	GPIO_PinAFConfig(ULTRA_SOUND_Port, TRIGG_PIN, GPIO_AF_TIM1);
	GPIO_PinAFConfig(ULTRA_SOUND_Port, ECHO_PIN, GPIO_AF_TIM3);
}
