#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

extern volatile uint64_t overflowCounter;

void setup_WMTIMER7(void);
void unsetOverflow(void);
void setOverflow(void);
void _delay_sec(unsigned int time);
void _delay_ms(unsigned int time);

#endif