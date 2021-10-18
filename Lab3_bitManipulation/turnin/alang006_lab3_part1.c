/*	Author: Austin Langrehr
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #1
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
    DDRB = 0x00; PORTB = 0xFF; 
    DDRC = 0xFF; PORTC = 0x00; 
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char cntavail = 0x00;
    unsigned char i = 0x00;
    
    while(1) {
        tmpA = PINA; 
        tmpB = PINB;
        cntavail = 0x00;

        for (i = 0; i < 8; ++i) {
            cntavail = cntavail + ((tmpA >> i) & 0x01) + ((tmpB >> i) & 0x01); 
        }

        PORTC = cntavail;

    }

    return 1;
}
