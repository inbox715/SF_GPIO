# SF_GPIO
Super Fast GPIO pins on AVR microcontrollers


Example usage:
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

Example usage with long version:
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
