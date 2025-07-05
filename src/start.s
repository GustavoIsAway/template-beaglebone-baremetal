.equ INTC_BASE, 0x48200000

/* CPSR */
.equ CPSR_I,   0x80
.equ CPSR_F,   0x40
.equ CPSR_IRQ, 0x12
.equ CPSR_USR, 0x10
.equ CPSR_FIQ, 0x11
.equ CPSR_SVC, 0x13
.equ CPSR_ABT, 0x17
.equ CPSR_UND, 0x1B
.equ CPSR_SYS, 0x1F

/* Vector table */
.section .vectors, "ax"
_vector_table:
    ldr   pc, _reset     /* reset - _start           */
    ldr   pc, _undf      /* undefined - _undf        */
    ldr   pc, _swi       /* SWI - _swi               */
    ldr   pc, _pabt      /* program abort - _pabt    */
    ldr   pc, _dabt      /* data abort - _dabt       */
    nop                  /* reserved                 */
    ldr   pc, _irq       /* IRQ - read the VIC       */
    ldr   pc, _fiq       /* FIQ - _fiq               */

_reset: .word _start
_undf:  .word undef_handler
_swi:   .word swi_handler
_pabt:  .word pabt_handler
_dabt:  .word dabt_handler
_irq:   .word irq_handler
_fiq:   .word fiq_handler

.section .text
_start:
    /* Set V=0 in CP15 SCTRL register */
    mrc    p15, 0, r0, c1, c0, 0
    bic    r0, #(1 << 13)
    mcr    p15, 0, r0, c1, c0, 0

    /* Habilita IRQ/FIQ no CPSR */
    mrs r0, cpsr
    bic r0, r0, #0xC0  /* Limpa bits I e F */
    msr cpsr_c, r0

    /* Set VBAR */
    ldr    r0, =_vector_table
    mcr    p15, 0, r0, c12, c0, 0

    /* Initialize stack pointers for all modes */
    /* SVC stack */
    msr    cpsr_c, #(CPSR_SVC | CPSR_F | CPSR_I)
    ldr    sp, =_svc_stack_end

    /* IRQ stack */
    msr    cpsr_c, #(CPSR_IRQ | CPSR_F | CPSR_I)
    ldr    sp, =_irq_stack_end

    /* Back to SVC mode */
    msr    cpsr_c, #(CPSR_SVC | CPSR_F)
    
    /* Clear BSS */
    ldr    r0, =__bss_start
    ldr    r1, =__bss_end
    mov    r2, #0
bss_loop:
    cmp    r0, r1
    strlt  r2, [r0], #4
    blt    bss_loop

    bl     main

loop:
    b      loop

/* Default exception handlers */
undef_handler:
    b undef_handler

swi_handler:
    b swi_handler

pabt_handler:
    b pabt_handler

dabt_handler:
    b dabt_handler

fiq_handler:
    b fiq_handler

/* IRQ handler */
irq_handler:
    sub    lr, lr, #4            /* Ajusta LR */
    srsdb  sp!, #0x12            /* Salva LR_irq e SPSR_irq no stack SVC */
    cps    #0x13                 /* Muda para modo SVC */
    push   {r0-r12, lr}          /* Salva registradores */
    
    and    r1, sp, #4            /* Alinha a pilha se necessário */
    sub    sp, sp, r1
    push   {r1}
    
    bl     ISR_Handler           /* Chama handler em C */
    
    pop    {r1}
    add    sp, sp, r1
    
    pop    {r0-r12, lr}          /* Restaura registradores */
    rfeia  sp!                   /* Retorna da interrupção */

.section .bss
.align 8
_svc_stack:
    .space 1024
_svc_stack_end:

_irq_stack:
    .space 1024
_irq_stack_end:
