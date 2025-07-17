#include "../inc/headers.h"
#include "../inc/timer.h"
#include "../inc/uart.h"


void disable_watchdog(void) {                                                       // função permite execução 
  WDT_WSPR = 0xAAAA;                                                                // infinita do programa
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
  uint32_t irq = INTC_SIR_IRQ & 0x7F;

  if (irq == 95) {
    if (DM_TIMER7_IRQSTATUS & (1 << 1)){
      overflowCounter++;
      DM_TIMER7_IRQSTATUS = (1 << 1);
    }
  }
}

int main(void) {
  disable_watchdog();
  begin_WMTIMER7();

  CONF_GPMC_CSN1 |= 0x7;
  GPIO1_OE &= ~(1 << 21);

    
  while (1) {
    char buffer[100];
    uart0_write("Introduza aqui um texto: ");
    uart0_getln(buffer);
    uart0_writeln(buffer);
    uart0_writeln("");
  }

  return 0;
}
