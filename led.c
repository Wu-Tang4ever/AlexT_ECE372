/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

#define OUTPUT 0
#define INPUT 1

void initLEDs(){
    
    TRISDbits.TRISD0 = OUTPUT;
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
}

void turnOnLED(int passin){
    int currState = 0;
    currState = passin;
    
    switch (passin) {
        case 1:
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;

            break;
            
        case 2:
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 0;

            break;
            
        case 3:
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;            
            break;
    }    
    
}