#ifndef DELAY_H_
#define DELAY_H_

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "tim_periph.h"

void 	Delay (uint32_t nCount);
void	init_delay(void);

#endif /* DELAY_H_ */
