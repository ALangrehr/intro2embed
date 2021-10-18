/*	Author: Austin Langrehr
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, On1, Press1, On2, Press2} state;

void Tick() {
    switch (state) { //Transitions
        case Start:
            state = On1;
            break;
        case On1:
             if (PINA & 0x01) { 
                state = Press1; }
            else {
                state = On1; }
            break;
        case Press1:
             if (PINA & 0x01) { 
                state = Press1; }
            else {
                state = On2; }
            break;
        case On2:
             if (PINA & 0x01) { 
                state = Press2; }
            else {
                state = On2; }
            break;
        case Press2:
            if (PINA & 0x01) { 
                state = Press2; }
            else {
                state = On1; }
            break;
        default:
            break;
     }
     switch (state) { //State Actions
        case Start:
            break;
        case On1:
            PORTB = 0x01;
            break;
        case Press1:
            break;
        case On2:
             PORTB = 0x02;
            break;
        case Press2:
            break;
        default:
            break;
     }
}




int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */

    state = Start;
    while (1) {
        Tick();
    }
    return 1;
}
