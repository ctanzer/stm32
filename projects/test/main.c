// #include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

#define TOGGLE_GPIOD(x) GPIOD->ODR ^= x
#define GREEN_LED GPIO_Pin_12
#define ORANGE_LED GPIO_Pin_13
#define RED_LED GPIO_Pin_14
#define BLUE_LED GPIO_Pin_15

int main(int argc, char const *argv[]) {
  SystemInit();

  {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef GPIO_initStruct;

	GPIO_initStruct.GPIO_Pin = GREEN_LED | ORANGE_LED | RED_LED | BLUE_LED;
	GPIO_initStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_initStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_initStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_initStruct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOD, &GPIO_initStruct);
	}

  while (1) {
    int i = 0;
    while(5000000 > i++);
    TOGGLE_GPIOD(GREEN_LED | ORANGE_LED | RED_LED | BLUE_LED);
  }

  return 0;
}
