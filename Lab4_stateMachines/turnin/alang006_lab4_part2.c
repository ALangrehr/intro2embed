/*	Author: Austin Langrehr
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char count = 0x00;

enum States {Start, Rest, Press_Up, Press_Down, Reset} state;

void Tick() {
    switch (state) { //Transitions
        case Start:
            count = 0x07;
            state = Rest;
            break;
        case Rest:
            if ((PINA & 0x03) == 0x03) { 
                state = Reset; }
            else if ((PINA & 0x03) == 0x01) {
                state = Press_Up; }
            else if ((PINA & 0x03) == 0x02) {
                state = Press_Down; }
            else 
                state = Rest;
            break;
        case Press_Up:
            if ((PINA & 0x03) == 0x03) { 
                state = Reset; }
            else if ((PINA & 0x01) == 0x00) {
                if (count < 0x09) {
                    count = count + 1; }
                else {
                    count = 0x09; }
                state = Rest; }
            else
                state = Press_Up;
            break;
        case Press_Down:
             if ((PINA & 0x03) == 0x03) { 
                state = Reset; }
            else if ((PINA & 0x02) == 0x00) {
                if (count > 0x00) {
                    count = count - 1; }
                else {
                    count = 0x00; }
                state = Rest; }
            else
                state = Press_Down;
            break;
        case Reset:
            if ((PINA & 0x03) != 0x03) { 
                count = 0x00;
                state = Rest; }
            else {
                state = Reset; }
            break;
        default:
            break;
     }
}




int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */

    state = Start;
    while (1) {
        Tick();
        PORTC = count;
    }
    return 1;
}
