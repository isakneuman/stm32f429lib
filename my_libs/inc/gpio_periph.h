#ifndef GPIO_PERIPH_H_
#define GPIO_PERIPH_H_

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define		USART1_RX_PIN	(1<<10)
#define		USART1_TX_PIN	(1<<9)

#define TRIGG_PIN	8
#define ECHO_PIN	6
#define ULTRA_SOUND_Port	GPIOA

#define I2C1_Port	GPIOB
#define I2C1_SDA	GPIO_PinSource7
#define I2C1_SCL	GPIO_PinSource6

#define	TIM2_CH2_PORT	GPIOA
#define	TIM2_CH2_PIN	GPIO_PinSource1

void	init_tim2_gpio(void);
void	init_i2c1_gpio(void);
void 	init_hc_sr04_gpio(void);
void	init_usart_gpio(USART_TypeDef	*USARTx);


#endif /* GPIO_PERIPH_H_ */
