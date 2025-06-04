#define WDT1_BASE 0x44E35000                                                        // Watchdog
#define WDT_WSPR (*(volatile unsigned int *)(WDT1_BASE + 0x48))
#define WDT_WWPS (*(volatile unsigned int *)(WDT1_BASE + 0x34))


void disable_watchdog(void) {     // função permite execução 
    WDT_WSPR = 0xAAAA;            // infinita do programa
    while (WDT_WWPS & (1 << 4));
    WDT_WSPR = 0x5555;
    while (WDT_WWPS & (1 << 4));
}


int main(void) {
  disable_watchdog();

  //inicialização de dados aqui
    
  while (1) {
      //código do loop aqui
  }

  return 0;
}
