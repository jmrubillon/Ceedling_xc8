#include "unity.h"
#include "gpio_access.h"
#include "support/support_uart.h"
#include <xc.h>
#include <string.h>  // for memset()

//volatile PORTABITS PORTAbits;   // Declare the registers for the GPIO Ports
//volatile PORTBBITS PORTBbits;

void setUp(void)
{
    //Set all ports to zero by default
    memset((void *)&LATAbits, 0x00, sizeof(LATAbits));
    memset((void *)&LATBbits, 0x00, sizeof(LATBbits));
}

void tearDown(void)
{
}

// Test setting port A latches
void test_GPIO_SetBit_should_set_corresponding_SFR_bit_for_A0(void)
{
    GPIO_SetBit(PORT_A, BIT_0);
    TEST_ASSERT_EQUAL(1, LATAbits.LATA0);
}

void test_GPIO_SetBit_should_set_corresponding_SFR_bit_for_A1(void)
{
    GPIO_SetBit(PORT_A, BIT_1);
    TEST_ASSERT_EQUAL(1, LATAbits.LATA1);
}

void test_GPIO_SetBit_should_set_corresponding_SFR_bit_for_A2(void)
{
    GPIO_SetBit(PORT_A, BIT_2);
    TEST_ASSERT_EQUAL(1, LATAbits.LATA2);
}

void test_GPIO_SetBit_should_set_corresponding_SFR_bit_for_A4(void)
{
    GPIO_SetBit(PORT_A, BIT_4);
    TEST_ASSERT_EQUAL(1, LATAbits.LATA4);
}


// Test Clearing Port A Latches
void test_GPIO_ClearBit_should_clear_the_corresponding_SFR_bit_for_A0(void)
{
    // Create initial condition
    LATAbits.LATA0 = 1;
    // Call function under test
    GPIO_ClearBit(PORT_A, BIT_0);
    // Assert results
    TEST_ASSERT_EQUAL(0, LATAbits.LATA0);
}

void test_GPIO_ClearBit_should_clear_the_corresponding_SFR_bit_for_A1(void)
{
    // Create initial condition
    LATAbits.LATA1 = 1;
    // Call function under test
    GPIO_ClearBit(PORT_A, BIT_1);
    // Assert results
    TEST_ASSERT_EQUAL(0, LATAbits.LATA1);
}

void test_GPIO_ClearBit_should_clear_the_corresponding_SFR_bit_for_A2(void)
{
    // Create initial condition
    LATAbits.LATA2 = 1;
    // Call function under test
    GPIO_ClearBit(PORT_A, BIT_2);
    // Assert results
    TEST_ASSERT_EQUAL(0, LATAbits.LATA2);
}


void test_GPIO_ClearBit_should_clear_the_corresponding_SFR_bit_for_A4(void)
{
    // Create initial condition
    LATAbits.LATA4 = 1;
    // Call function under test
    GPIO_ClearBit(PORT_A, BIT_4);
    // Assert results
    TEST_ASSERT_EQUAL(0, LATAbits.LATA4);
}


void test_GPIO_SetBit_should_set_corresponding_SFR_bit_for_B4(void)
{
    GPIO_SetBit(PORT_B, BIT_4);
    TEST_ASSERT_EQUAL(1, LATBbits.LATB4);
}


void test_GPIO_ClearBit_should_clear_the_corresponding_SFR_bit_for_B4(void)
{
    // Create initial condition
    LATBbits.LATB4 = 1;
    // Call function under test
    GPIO_ClearBit(PORT_B, BIT_4);
    // Assert results
    TEST_ASSERT_EQUAL(0, LATBbits.LATB4);
}
