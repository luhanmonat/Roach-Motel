/*
 * Electric Roach Motel Vers-1
 * 6/22 Luhan Monat
 * Coded for ATtiny85 w/optiboot 
 * 8 Mhz internal oscillator
 * 
 * Creates 600-900 volt pulses from 9-12 volt source.
 * Uses Sleep mode to save power between pulses.
 * 
 */

#define HVOLT   4       // High voltage drive
#define SENSE   3       // Sense for a/d (optional)
#define LED     2       // On board indicator LED


//  Written using main() function for more efficient coding

int	main() {
int i;

  DDRB  = 0b00110111;       // most bits are output except bit 3
  WDTCR = 0b00101000;       // 4 second wdt 

  bitSet(PORTB,LED);            // indicate start of pulse

//  Generate 500 each 200 microsecond cycles for a total of 100 milliseconds

  for(i=0;i<500;i++) {  
    bitSet(PORTB,HVOLT);        // turn on drive to coil
    delayMicroseconds(100);     //   for 100 microseconds
    bitClear(PORTB,HVOLT);      // turn off for 100 microseconds
    delayMicroseconds(100);
  }
  
  bitClear(PORTB,LED);          // indicate end of pulse

  Sleeper();                    // go to sleep to save power

}

//  Go to sleep for about 4 seconds
//  Wake up using Watch Dog Timer
//  and perform RESET function.

void  Sleeper() {

  WDTCR = 0b00101000;       // setup for 4 second wdt
  bitSet(MCUCR,SE);         // Sleep enable
  bitSet(MCUCR,SM1);        //  bits for
  bitClear(MCUCR,SM0);      //  power down mode
  PRR = 0b00001111;         // turm off periferals
  asm("sleep \n");          // execute assembler sleep instruction

}
