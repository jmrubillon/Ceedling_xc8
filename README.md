# Ceedling_xc8
Sample project for using ceedling with Microchip's xc8 compiler

This is a simple example ceedling project demonstrating how Microchip's xc8 compiler and simulation tool can be used to test embedded code.

It was inspired by the [PIC32 example](https://github.com/crespum/Ceedling-PIC32) and the [PIC16 example](https://github.com/ThrowTheSwitch/CeedlingExample_Microchip)

This example uses a modified version of CMock (2.5.2) which allows it to be compiled without requiring setjmp.h.

On Windows, to avoid issues with spaces in folder names, it is advised to create folder junctions to MPLABX and XC compiler folders.

 * mklink /j C:\mplabx "C:\Program Files (x86)\Microchip\MPLABX\v5.30"
 * mklink /j C:\xc8 "C:\Program Files (x86)\Microchip\xc8\v2.10"
