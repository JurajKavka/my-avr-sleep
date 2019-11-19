#include "avr/sleep.h"
#include "myavrsleep.h"

/**
 * Disables ADC, enables deep sleep and disables BOD.
 */
void avrDeepSleep() {

    // DISABLE ADC
    ADCSRA &= ~(1 << 7);

    //ENABLE SLEEP
    SMCR |= (1 << 2);  // power down mode
    SMCR |= 1;         // enable sleep

    // BOD disable
    MCUCR |= (3 << 5);  // set both BODS and BODSE at the same time
    MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6);  // then set the BODS bit and clear 
                                             // the BODSE bit at the same time

    __asm__ __volatile__("sleep");
}


/**
 * Enable ADC after wake up.
 */
void avrEnableAdc(){
    ADCSRA |= (1 << 7);
}
