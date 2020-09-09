#include "gpio_access.h"
#include <xc.h>
#include <assert.h>

void GPIO_SetBit(GPIO_PORTS port, PORT_BITS bit)
{
    switch (port)
    {
        case PORT_A:
            if (BIT_0 == bit) LATAbits.LATA0 = 1;
            else if (BIT_1 == bit) LATAbits.LATA1 = 1;
            else if (BIT_2 == bit) LATAbits.LATA2 = 1;
            else if (BIT_4 == bit) LATAbits.LATA4 = 1;
            else 
                assert(1); 
            break;
        default:
        case PORT_B: 
            if (BIT_4 == bit) LATBbits.LATB4 = 1;
            else 
                assert(1); 
            break;
    }
}

void GPIO_ClearBit(GPIO_PORTS port, PORT_BITS bit)
{
    switch (port)
    {
        case PORT_A:
            if (BIT_0 == bit) LATAbits.LATA0 = 0;
            else if (BIT_1 == bit) LATAbits.LATA1 = 0;
            else if (BIT_2 == bit) LATAbits.LATA2 = 0;
            else if (BIT_4 == bit) LATAbits.LATA4 = 0;
            else 
                assert(1); 
            break;
        default:
        case PORT_B: 
            if (BIT_4 == bit) LATBbits.LATB4 = 0;
            else 
                assert(1); 
            break;
    }
}

bool GPIO_IsBitSet(GPIO_PORTS port, PORT_BITS bit)
{
    bool rv = false;
    switch (port)
    {
        case PORT_A:
            if (BIT_0 == bit) rv = (LATAbits.LATA0);
            else if (BIT_1 == bit) rv = (LATAbits.LATA1);
            else if (BIT_2 == bit) rv = (LATAbits.LATA2);
            else if (BIT_4 == bit) rv = (LATAbits.LATA4);
            else 
                assert(1); 
            break;
        default:
        case PORT_B: 
            if (BIT_4 == bit) rv = (LATBbits.LATB4);
            else 
                assert(1); 
            break;
    }
    return rv;
}