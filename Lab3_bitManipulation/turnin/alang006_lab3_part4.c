/*	Author: Austin Langrehr
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; 
    DDRC = 0xFF; PORTC = 0x00; 
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00; 
    
    while(1) {
        tmpA = PINA; 
        tmpB = 0;
        tmpC = 0;
  
        tmpB = tmpB | (tmpA >> 4);
        tmpC = tmpC | (tmpA << 4);
        
        PORTB = tmpB;
        PORTC = tmpC;

    }

    return 1;
}
