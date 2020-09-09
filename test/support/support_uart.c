#include <xc.h>
#include <stdbool.h>

#include "support_uart.h"

// disable watchdog
#pragma config WDTE = OFF

#define TRUE 1
#define FALSE 0

void putch(char data)
{
    support_init_uart();
    TX1REG = data;
    PIR1bits.TXIF = 0;
}

void support_init_uart(void)
{
static _Bool uart_was_init = false;
    if( !uart_was_init)
    {
        // disable interrupts before changing states
        PIE1bits.RCIE = 0;
        PIE1bits.TXIE = 0;
        // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
        BAUD1CON = 0x08;
        // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
        RC1STA = 0x90;
        // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
        TX1STA = 0x24;
        // SP1BRGL 138; 
        SP1BRGL = 0x8A;
        // SP1BRGH 0; 
        SP1BRGH = 0x00;

        RXPPS = 0x10;   //RC0->EUSART:RX;    
        RC2PPS = 0x14;   //RC2->EUSART:TX;    
        uart_was_init = true;
    }
}
