/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1
volatile int state = 1;

//TODO: Define states of the state machine
//typedef enum stateTypeEnum{
//} stateType;

//TODO: Use volatile variables that change within interrupts

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts(); 
    //int i = 0;

    //TODO: Write each initialization function
    initLEDs();
    initTimer1();
   // initTimer2();
    
    while(1){
        
        turnOnLED(state);
        
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Inpterupt(){
    IFS0bits.T1IF = 0;
    if(state == 1) state = 2;
    else if(state == 2) state = 3;
    else if(state == 3) state = 1;
    
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed
