#include <avr/io.h>

/**
 * @file SF_GPIO.h
 * @brief Header file for Super Fast GPIO functions.
 * @details This file contains inline functions for controlling Super Fast GPIO pins on AVR microcontrollers.
 * @anchor inbox715
 * @date 2024-07-31
 * 
 * 
 * 
 * 
 * 
 * This file contains inline functions for controlling Super Fast GPIO pins on AVR microcontrollers.
 * It provides functions to set pins high, low, as output, as input, enable pull-up resistors,
 * toggle pins, and read pin values.
 * 
 * only using inline functions, the compiler will replace the function call with the actual code of the function.
 * no loss of performance.
 * 
 * The pin definitions are specific to certain AVR microcontrollers, such as ATmega48, ATmega88, ATmega168, and ATmega328.
 * Additional pins can be added for other microcontrollers by modifying the pin definitions.
 * 
 * The functions are provided in two versions: a short version that uses PORTB, DDRB, and PINB registers directly,
 * and a long version that allows using any PORTx, DDRx, and PINx registers.
 */



// Example usage:
// #include <avr/io.h>
// #include "SF_GPIO.h"
// int main()
// {
//     set_pin_output(pin_14);
//     while (1)
//     {
//         set_pin_toggle(pin_14);
//     }
//     return 0;
// }

// Example usage with long version:
// int main()
// {
//     set_ppin_output(&PORTB, 0);
//     while (1)
//     {
//         set_ppin_toggle(&PORTB, 0);
//     }
//     return 0;
// }




// You can add more pins here if you want to use them
#if defined(__AVR_ATmega48__) || (__AVR_ATmega48P__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) || (__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)

	#define pin_0 PORTC6
	#define pin_2 PORTD0
	#define pin_3 PORTD1
	#define pin_4 PORTD2
	#define pin_5 PORTD3
	#define pin_6 PORTD4
	#define pin_11 PORTD5
	#define pin_12 PORTD6
	#define pin_13 PORTD7
	#define pin_14 PORTB0
	#define pin_15 PORTB1
	#define pin_16 PORTB2
	#define pin_17 PORTB3
	#define pin_18 PORTB4
	#define pin_19 PORTB5
	#define pin_9 PORTB6
	#define pin_10 PORTB7
	#define pin_23 PORTC0
	#define pin_24 PORTC1
	#define pin_25 PORTC2
	#define pin_26 PORTC3
	#define pin_27 PORTC4
	#define pin_28 PORTC5

#endif



// Inline function to set a pin low


static inline void set_pin_high(uint8_t pin)
{
    PORTB |= (1 << pin);
}

static inline void set_pin_low(uint8_t pin)
{
    PORTB &= ~(1 << pin);
}

static inline void set_pin_output(uint8_t pin)
{
    DDRB |= (1 << pin);
}

static inline void set_pin_input(uint8_t pin)
{
    DDRB &= ~(1 << pin);
}

static inline void set_pin_pullup(uint8_t pin)
{
    PORTB |= (1 << pin);
}

static inline void set_pin_toggle(uint8_t pin)
{
    PORTB ^= (1 << pin);
}

static inline uint8_t read_pin(uint8_t pin)
{
    return (PINB & (1 << pin));
}



// Long version of the above functions 
// This is for when you want to use the PORTx, DDRx, and PINx registers directly
// pp - > means port pin

static inline void set_ppin_high( volatile uint8_t* port , uint8_t pin)
{
	*port |= (1 << pin);
}

static inline void set_ppin_low( volatile uint8_t* port , uint8_t pin)
{
	*port &= ~(1 << pin);
}

static inline void set_ppin_output ( volatile uint8_t* port , uint8_t pin)
{
	*port |= (1 << pin);
}

static inline void set_ppin_input( volatile uint8_t* port , uint8_t pin)
{
	*port &= ~(1 << pin);
}

static inline void set_ppin_pullup( volatile uint8_t* port , uint8_t pin)
{
	*port |= (1 << pin);
}

static inline void set_ppin_toggle( volatile  uint8_t* port , uint8_t pin)
{
	*port ^= (1 << pin);
}

static inline uint8_t read_ppin( volatile uint8_t* port , uint8_t pin)
{
	return (*port & (1 << pin));
}
