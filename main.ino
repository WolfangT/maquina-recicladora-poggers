/* Main.ino
 * main code for the poggers project
 * intended for proteus 8.10 simulation
 *
 * Created:   Mon Feb 7 2022
 * Processor: Arduino Mega
 * Compiler:  Arduino AVR (Proteus)
 * author:    wolfang.torres@gmail.com
 */

// Peripheral Configuration Code (do not edit)
//---CONFIG_BEGIN---
#pragma GCC push_options
#pragma GCC optimize("Os")

#include <core.h> // Required by cpu
#include <cpu.h>

#pragma GCC pop_options

// Peripheral Constructors
CPU &cpu = Cpu;

void peripheral_setup()
{
}

void peripheral_loop()
{
}
//---CONFIG_END---

const byte stepper_positions[8] = {
    0b00010000,
    0b00110000,
    0b00100000,
    0b01100000,
    0b01000000,
    0b11000000,
    0b10000000,
    0b10010000,
};
byte n = 0;

void setup()
{
    peripheral_setup();
    DDRB |= 0xF0;
}

void loop()
{
    peripheral_loop();
    analogWrite(7, 250);
    n++;
    if (n >= 8)
        n = 0;
    PORTB = stepper_positions[n];
    delay(500);
}
