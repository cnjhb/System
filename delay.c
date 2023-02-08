#include "stm32f1xx.h"
#include <delay.h>
#include <stdint.h>

static int fac_us;

void delay_init() {
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
  fac_us = SystemCoreClock / 1000000;
}
void delay_us(int num) {
  uint32_t ticks = fac_us * num;
  uint32_t told, tnow, tcnt = 0;
  uint32_t reload = SysTick->LOAD;
  told = SysTick->VAL;
  while (1) {
    tnow = SysTick->VAL;
    if (tnow != told) {
      tcnt += tnow <= told ? told - tnow : reload - tnow + told;
      told = tnow;
      if (tcnt >= ticks)
        break;
    }
  }
}
void delay_ms(int num) {
  for (int i = 0; i < num; i++) {
    delay_us(1000);
  }
}
