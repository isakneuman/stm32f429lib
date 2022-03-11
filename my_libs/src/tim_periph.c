#include "tim_periph.h"

void	init_timer(void)
{
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseInitTypeDef;

	TIM_TimeBaseInitTypeDef.TIM_Period			=	999;
	TIM_TimeBaseInitTypeDef.TIM_Prescaler		=	320;
	TIM_TimeBaseInitTypeDef.TIM_ClockDivision	=	TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeDef.TIM_CounterMode		=	TIM_CounterMode_CenterAligned2;

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitTypeDef);

	TIM_OCInitTypeDef		TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);

	TIM_OCInitStruct.TIM_OCMode			=	TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState	=	TIM_OutputState_Enable;

	TIM_OC2Init(TIM2, &TIM_OCInitStruct);

	TIM_Cmd(TIM2, ENABLE);
	TIM_CCxCmd(TIM2, TIM_Channel_2, TIM_CCx_Enable);
}
