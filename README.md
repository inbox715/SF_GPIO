# SF_GPIO
Super Fast GPIO pins on AVR microcontrollers

 This file contains inline functions for controlling Super Fast GPIO pins on AVR microcontrollers.
 It provides functions to set pins high, low, as output, as input, enable pull-up resistors,
 toggle pins, and read pin values.
 
 only using inline functions, the compiler will replace the function call with the actual code of the function.
 no loss of performance.
 
 The pin definitions are specific to certain AVR microcontrollers, such as ATmega48, ATmega88, ATmega168, and ATmega328.
 Additional pins can be added for other microcontrollers by modifying the pin definitions.
 
 The functions are provided in two versions: a short version that uses PORTB, DDRB, and PINB registers directly,
 and a long version that allows using any PORTx, DDRx, and PINx registers.

Example usage 1:
``` C++
#include <avr/io.h>
#include "SF_GPIO.h"

int main()
{
    set_pin_output(pin_14);
    while (1)
    {
        set_pin_toggle(pin_14);
    }
    return 0;
}
```

Example usage 2:
``` C++
#include <avr/io.h>
#include "SF_GPIO.h"

int main()
{
    set_ppin_output(&PORTB, 0);
    while (1)
    {
        set_ppin_toggle(&PORTB, 0);
    }
    return 0;
}
```
