/*	Author: Austin Langrehr
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum States {Start, Locked, Press1, Release, Press2, Unlock} state;

void Tick() {
    switch (state) { //Transitions
        case Start:
            state = Locked;
            break;
        case Locked:
            if ((PINA & 0x07) == 0x04) { 
                state = Press1; }
            else 
                state = Locked;
            break;
        case Press1:
            if ((PINA & 0x07) == 0x00) { 
                state = Release; }
            else
                state = Press1;
            break;
        case Release:
             if ((PINA & 0x07) == 0x02) { 
                state = Press2; }
            else if (PINA & 0x05) {
                state = Locked; }
            else
                state = Release;
            break;
        case Press2:
            if ((PINA & 0x07) == 0x00) { 
                state = Unlock; }
            else
                state = Press2;
            break;
        case Unlock:
            if (PORTA & 0x80) 
                state = Locked;
            else
                state = Unlock;
            break;
        default:
            break;
     }
      switch (state) { //Transitions
        case Start:
            break;
        case Locked:
            PORTB = 0x00;
            break;
        case Press1:
            break;
        case Release:
            break;
        case Press2:
            break;
        case Unlock:
            PORTB = 0x01;
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
