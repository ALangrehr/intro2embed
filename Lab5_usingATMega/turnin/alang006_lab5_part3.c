/*	Author: Austin Langrehr
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *      Demo Link: https://www.youtube.com/watch?v=ijCxVrOShc4
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char out = 0x00;

enum States {Start, NoLights, Lights2, Lights4, Lights6, Press1, Press2, Press3, Press4, Press5, Press6, Lights42, Lights22} state;

void Tick() {
    switch (state) { //Transitions
        case Start:
            out = 0x00;
            state = NoLights;
            break;
        case NoLights:
            if(0x01 & ~PINA)
                state = Press1;
            else
                state = NoLights;
            break;
        case Press1:
            if(0x01 & ~PINA)
                state = Press1;
            else
                state = Lights2;
            break;
        case Lights2:
            if(0x01 & ~PINA)
                state = Press2;
            else
                state = Lights2;
            break;
        case Press2:
            if(0x01 & ~PINA)
                state = Press2;
            else
                state = Lights4;
            break;
        case Lights4:
            if(0x01 & ~PINA)
                state = Press3;
            else
                state = Lights4;
            break;
        case Press3:
            if(0x01 & ~PINA)
                state = Press3;
            else
                state = Lights6;
            break;
        case Lights6:
            if(0x01 & ~PINA)
                state = Press4;
            else
                state = Lights6;
            break;
        case Press4:
            if(0x01 & ~PINA)
                state = Press4;
            else
                state = Lights42;
            break;
        case Lights42:
            if(0x01 & ~PINA)
                state = Press5;
            else
                state = Lights42;
            break;
        case Press5:
            if(0x01 & ~PINA)
                state = Press5;
            else
                state = Lights22;
            break;
        case Lights22:
            if(0x01 & ~PINA)
                state = Press6;
            else
                state = Lights22;
            break;
        case Press6:
            if(0x01 & ~PINA)
                state = Press6;
            else
                state = NoLights;
            break;
        default:
            break;
     }
    switch (state) { //State Actions
        case NoLights:
            out = 0x00;
            break;
        case Lights2:
            out = 0x0C;
            break;
        case Lights4:
            out = 0x12;
            break;
        case Lights6:
            out = 0x21;
            break;
        case Lights42:
            out = 0x12;
            break;
        case Lights22:
            out = 0x0C;
            break;
        default:
            break;
     }
}




int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */

    state = Start;
    while (1) {
        Tick();
        PORTB = out;
    }
    return 1;
}

