.syntax unified                                                 @ Specify unified assembly syntax
.cpu    cortex-m0plus                                           @ Specify CPU type is Cortex M0+
.thumb                                                          @ Specify thumb assembly for RP2040
.global main_asm    
.global checkInterrupt                                          @ Provide program starting address to the linker
.align 4             

.equ    GPIO_LED_PIN,       25          @ Specify pin for the built-in LED
.equ    GPIO_DIR_IN,        0           @ Specify input direction for a GPIO pin
.equ    GPIO_DIR_OUT,       1           @ Specify output direction for a GPIO pin                                           @ Specify code alignment

checkInterrupt:
    wfi
    bx lr

@ Entry point to the ASM portion of the program
main_asm:
    b       main_asm                                           @ Infinite loop


@ Set data alignment
.data
    .align 4

