/*	Author: Austin Langrehr
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #2
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
    unsigned char tmpC = 0x00; 
    
    while(1) {
        tmpA = PINA; 
        tmpC = 0;
        
        if ((tmpA == 0x01) || (tmpA == 0x02)) { //light 5, 6 
            tmpC = 0x60; }
        else if ((tmpA == 0x03) || (tmpA == 0x04)) { //light 4, 5, 6 
            tmpC = 0x70; }
        else if ((tmpA == 0x05) || (tmpA == 0x06)) { //light 3, 4, 5
            tmpC = 0x38; }
        else if ((tmpA == 0x07) || (tmpA == 0x08) || (tmpA == 0x09)) { //light 2, 3, 4, 5
            tmpC = 0x3C; }
        else if ((tmpA == 0x0A) || (tmpA == 0x0B) || (tmpA == 0x0C)) { //light 1, 2, 3, 4, 5
            tmpC = 0x3E; }
        else if ((tmpA == 0x0D) || (tmpA == 0x0E) || (tmpA == 0x0F)) { //light 0, 1, 2, 3, 4, 5
            tmpC = 0x3F; }
        else {
            tmpC = 0x40; } //light 6

       
        PORTC = tmpC;

    }

    return 1;
}
