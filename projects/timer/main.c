// #include "stm32f4xx.h"
// #include "stm32f4xx_rcc.h"
// #include "stm32f4xx_gpio.h"
// #include "stm32f4xx_tim.h"
// #include "misc.h"
// #include "stm32f4xx_it.h"

#include "main.h"

#define TOGGLE_GPIOD(x) GPIOD->ODR ^= x

void wait_delay(volatile int);

int main(int argc, char const *argv[]) {
  SystemInit();

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  GPIO_InitTypeDef GPIO_initStruct;
  TIM_TimeBaseInitTypeDef TIM_timebaseStruct;
  NVIC_InitTypeDef NVIC_initStruct;

  GPIO_initStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_initStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_initStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_initStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_initStruct.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOD, &GPIO_initStruct);

  TIM_timebaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_timebaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_timebaseStruct.TIM_Period = 4999;
  TIM_timebaseStruct.TIM_Prescaler = 16799;
  TIM_TimeBaseInit(TIM2, &TIM_timebaseStruct);

  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

  NVIC_initStruct.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_initStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_initStruct.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_initStruct.NVIC_IRQChannelSubPriority = 0x0F;
  NVIC_Init(&NVIC_initStruct);

  TIM_Cmd(TIM2, ENABLE);

  while (1) {
    wait_delay(6000);
    TOGGLE_GPIOD(GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    wait_delay(2500);
    TOGGLE_GPIOD(GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    wait_delay(2500);
    TOGGLE_GPIOD(GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    wait_delay(2500);
    TOGGLE_GPIOD(GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
  }

  return 0;
}

void wait_delay(volatile int count) {
  while (count--) {
    volatile int temp = count;
    while (temp--)
      ;
  }
}
