#ifndef __SYS_H
#define __SYS_H
#include <stdint.h>

#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND((uintptr_t)(addr), bitnum)) 

#define Pout(port,bitnum)	BIT_ADDR(&port->ODR,bitnum)
#define Pin(port,bitnum)	BIT_ADDR(&port->IDR,bitnum)

#endif
