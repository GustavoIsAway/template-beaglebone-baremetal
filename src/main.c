#include "../inc/defines.h"


void disable_watchdog(void) {                                                       // função permite execução 
  WDT_WSPR = 0xAAAA;                                                              // infinita do programa
  while (WDT_WWPS & (1 << 4));
  WDT_WSPR = 0x5555;
  while (WDT_WWPS & (1 << 4));
}
  
void delayBurro(unsigned int delay){
  for (int i = 0; i < delay; i++){
    __asm__ __volatile__ ("nop");
  }
}

void ISR_Handler(){
  __asm__ __volatile__("nop");
}

int main(void) {
  disable_watchdog();

  CONF_GPMC_CSN1 |= 0x7;
  GPIO1_OE &= ~(1 << 21);

    
  while (1) {
    GPIO1_SETDATAOUT = (1 << 21);
    delayBurro(200000000);
    GPIO1_CLEARDATAOUT = (1 << 21);
    delayBurro(200000000);  
  }

  return 0;
}
