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
    DDRB = 0x00; PORTB = 0xFF; 
    DDRC = 0xFF; PORTC = 0x00; 
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpC = 0x00; 
    
    while(1) {
        tmpA = PINA; 
        tmpC = 0;
        
        if (((0x0F & tmpA) == 0x01) || ((0x0F & tmpA) == 0x02)) { 
            tmpC = 0x60; } //light 5, 6 
        else if (((0x0F & tmpA) == 0x03) || ((0x0F & tmpA) == 0x04)) {  
            tmpC = 0x70; } //light 4, 5, 6
        else if (((0x0F & tmpA) == 0x05) || ((0x0F & tmpA) == 0x06)) { 
            tmpC = 0x38; } //light 3, 4, 5
        else if (((0x0F & tmpA) == 0x07) || ((0x0F & tmpA) == 0x08) || ((0x0F & tmpA) == 0x09)) { 
            tmpC = 0x3C; } //light 2, 3, 4, 5
        else if (((0x0F & tmpA) == 0x0A) || ((0x0F & tmpA) == 0x0B) || ((0x0F & tmpA) == 0x0C)) { 
            tmpC = 0x3E; } //light 1, 2, 3, 4, 5
        else if (((0x0F & tmpA) == 0x0D) || ((0x0F & tmpA) == 0x0E) || ((0x0F & tmpA) == 0x0F)) { 
            tmpC = 0x3F; } //light 0, 1, 2, 3, 4, 5
        else {
            tmpC = 0x40; } //light 6
        
        if ((0x70 & tmpA) == 0x30) {
            tmpC = tmpC | 0x80; }
       
        PORTC = tmpC;

    }

    return 1;
}
