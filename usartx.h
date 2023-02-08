#ifndef __USART_H
#define __USART_H
#include <stm32f1xx.h>
#include <stdio.h>

static UART_HandleTypeDef* used_huart;

void usart_init(UART_HandleTypeDef* huart){
	used_huart=huart;
}

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
int _write(int file, char *ptr, int len) {
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++) {
    __io_putchar(*ptr++);
  }

  return len;
}
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE {
  HAL_UART_Transmit(used_huart, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

#endif
