#ifndef DEFINES_H
#define DEFINES_H

#define WDT1_BASE   0x44E35000
#define WDT_WSPR    (*(volatile unsigned int *)(WDT1_BASE + 0x48))
#define WDT_WWPS    (*(volatile unsigned int *)(WDT1_BASE + 0x34))

#define CM_WKUP_BASE            0x44E00400 //Clock Module Wakeup Registers
#define CM_WKUP_ADC_TSC_CLKCTRL (*(volatile unsigned int *)(CM_WKUP_BASE + 0xBC))

//========================================== ATIVAÇÃO DO CLOCK DO GPIO1 ==================================
#define CM_PER_BASE             0x44E00000
#define CM_PER_GPIO1_CLKCTRL      (*(volatile unsigned int*)(CM_PER_BASE + 0xAC))
#define CM_PER_TIMER7_CLKCTRL     (*(volatile unsigned int *)(CM_PER_BASE + 0x7C))

//======================================== CONFIG RESISTRADORES DO GPIO1 ===============================
#define GPIO1_BASE              0x4804C000
#define GPIO1_EOI               (*(volatile unsigned int*)(GPIO1_BASE + 0x20))
#define GPIO1_OE                (*(volatile unsigned int*)(GPIO1_BASE + 0x134))
#define GPIO1_CLEARDATAOUT      (*(volatile unsigned int*)(GPIO1_BASE + 0x190))
#define GPIO1_SETDATAOUT        (*(volatile unsigned int*)(GPIO1_BASE + 0x194))
#define GPIO1_DATAIN            (*(volatile unsigned int*)(GPIO1_BASE + 0x138))
#define GPIO1_IRQSTATUS_SET_0   (*(volatile unsigned int*)(GPIO1_BASE + 0x34))
#define GPIO1_IRQSTATUS_0       (*(volatile unsigned int*)(GPIO1_BASE + 0x2C))
#define GPIO1_RISINGDETECT      (*(volatile unsigned int*)(GPIO1_BASE + 0x148))

//=========================================== MUX DECLARATION ============================================
#define CONTROL_MODULE_BASE     0x44E10000
#define CONF_GPMC_AD1       (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x804))
#define CONF_GPMC_AD3       (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x80C))
#define CONF_GPMC_AD4       (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x810))
#define CONF_GPMC_AD5       (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x814))
#define CONF_GPMC_AD6       (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x818))
#define CONF_GPMC_AD7       (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x81C))
#define CONF_GPMC_AD12      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x830))
#define CONF_GPMC_AD13      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x834))
#define CONF_GPMC_AD14      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x838))
#define CONF_GPMC_AD15      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x83C))
#define CONF_GPMC_CSN1      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x880))
#define CONF_GPMC_CSN2      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x884))
#define CONF_GPMC_CSN3      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x884))
#define CONF_GPMC_CSN4      (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x884))
#define CONF_AIN0           (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x984))
#define CONF_AIN1           (*(volatile unsigned int*)(CONTROL_MODULE_BASE + 0x988)) 

//=========================================== INTERRUPÇÃO =================================================
#define INTC_BASE       0x48200000

//OLHAR SE O VETOR 3 TEM INTERRUPÇÃO POR VALOR LOGICO 
#define INTC_MIR_CLEAR3 (*(volatile unsigned int*)(INTC_BASE + 0xE8))  // VERIFICAR SE A INTERRUPÇÃO DO ADC ESTÁ NO 3º VETOR
#define INTC_MIR_CLEAR2 (*(volatile unsigned int*)(INTC_BASE + 0xC8))
#define INTC_SIR_IRQ    (*(volatile unsigned int*)(INTC_BASE + 0x40))
#define INTC_CONTROL    (*(volatile unsigned int*)(INTC_BASE + 0x48))

//========================================== CONFIG UART ==================================================
#define UART0_BASE      0x44E09000
#define UART0_THR       (*(volatile unsigned int *)(UART0_BASE + 0x00))  // Registrador de Transmissão (que é o mesmo que o de Recepção)
#define UART0_LSR       (*(volatile unsigned int *)(UART0_BASE + 0x14))  // Base do LSR
#define UART0_LSR_THRE  (1 << 5)                                         // Avisa que registrador THR transmite dados
#define UART0_LSR_RHRE  (1 << 0)                                         // Avisa que registrador RHR recebe dados


#define DM_TIMER7_BASE            0x4804A000
#define DM_TIMER7_COUNTER         (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x3C))
#define DM_TIMER7_TCLR            (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x38)) 
#define DM_TIMER7_IRQENABLE_SET   (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x2C))
#define DM_TIMER7_IRQENABLE_CLEAR (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x30))
#define DM_TIMER7_IRQSTATUS       (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x28))
#define DM_TIMER7_IRQ_EOI         (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x20))
#define DM_TIMER7_TSICR           (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x54))
#define DM_TIMER7_TCRR            (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x3C))
#define DM_TIMER7_TLDR            (*(volatile unsigned int*)(DM_TIMER7_BASE + 0x4C))
#define DM_TIMER7_START_STOP_TIMER      (1 << 0)
#define DM_TIMER7_AUTORELOAD            (1 << 1)
#define DM_TIMER7_PRESCALER_ENABLE      (1 << 5)

//============================================== DEF PIN ==================================================
#define LED_INT1 (1 << 21)
#define LED_INT2 (1 << 22)
#define LED_INT3 (1 << 23)
#define LED_INT4 (1 << 24)


#define pulsosPorSegundo                24000000
#endif















