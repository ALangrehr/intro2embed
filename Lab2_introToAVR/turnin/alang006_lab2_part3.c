/*	Author: Austin Langrehr
 *      Email: alang006@ucr.edu
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #2
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
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char cntavail = 0x00;
    
    while(1) {
        tmpA = PINA & 0x0F;
        cntavail = 0x00;

        if (tmpA == 0x0F) { 
            cntavail = (cntavail & 0x70) | 0x84; }
        else if ((tmpA == 0x07) || (tmpA == 0x0B) || (tmpA == 0x0D) || (tmpA == 0x0E)){
            cntavail = (cntavail & 0x70) | 0x03;  }
        else if ((tmpA == 0x03) || (tmpA == 0x06) || (tmpA == 0x09) || (tmpA == 0x0C)){
            cntavail = (cntavail & 0x70) | 0x02;  }
        else if ((tmpA == 0x01) || (tmpA == 0x02) || (tmpA == 4) || (tmpA == 0x08)){
            cntavail = (cntavail & 0x70) | 0x01;  }
        else {
            cntavail = (cntavail & 0xF8) | 0x00;  }
        // 3) Write output
        PORTC = cntavail;    
    }
    return 0;

}
