/**
 * Usage, according to documentation(http://www.hobbywing.com/uploadfiles/sx/file/manual/HW-01-V4.pdf) : 
 *     1. Plug your Arduino to your computer with USB cable, open terminal, then type 1 to send max throttle to every ESC to enter programming mode
 *     2. Power up your ESCs. You must hear "beep1 beep2 beep3" tones meaning the power supply is OK
 *     3. After 2sec, "beep beep" tone emits, meaning the throttle highest point has been correctly confirmed
 *     4. Type 0 to send 0 throttle
 *     5. Several "beep" tones emits, wich means the quantity of the lithium battery cells (3 beeps for a 3 cells LiPo)
 *     6. A long beep tone emits meaning the throttle lowest point has been correctly confirmed
 *     7. Type 2 to launch test function. This will send 0 to 180 throttle to ESCs to test them
 */



/*
 * 
 *         DRONE
 * 
 *     A         B
 *      \       /
 *        -----
 *       |     |
 *       |     |                  (((((((((((((    Controller
 *        -----
 *     /        \
 *   C            D
 * 
 * 
 * 
 * 
 *  Controller:
 *      Links onder: 1003.00 - 1011.00 (channel 2)  //dalen
 *      Links bover: 1978.00 - 1961.00 (channel 2)  //stijgen
 * 
 *      Rechts onder: 996.00 - 988.00 (channel 1) //achteruit
 *      Rechts centraal: 1489.00 - 1473.00 (channel 1)
 *      Rechts boven: 1987.00 - 1972.00 (channel 1) //voorruit
 *      
 *      Rechts links: 1490.00 - 1473.00 (channel 0) //links
 *      rechts centraal: 1495.00 - 1473.00 (channel 0)
 *      Rechts rechts: 1539.00 - 1515.00 (channel 0) //rechts
 *            
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <Servo.h>

Servo motA, motB, motC, motD;
int channel0, channel1, channel2, channel3;
char data;

/**
 * Initialisation routine
 */
void setup() {
    Serial.begin(9600);

    //radio freq
    pinMode(2, INPUT);
    
    //servo's
    motA.attach(4, 1000, 2000); // 1000 and 2000 are very important ! Values can be different with other ESCs.
    motB.attach(5, 1000, 2000);
    motC.attach(6, 1000, 2000);
    motD.attach(7, 1000, 2000);
    
    displayInstructions();
}

/**
 * Main function
 */
void loop() {
   

channel0 =  pulseIn(8, HIGH);
channel1 =  pulseIn(9, HIGH);
channel2 =  pulseIn(10, HIGH);
channel3 =  pulseIn(11, HIGH);

channel1 = map(channel0, 988, 1986, -180, 180); // full throttle = 179, low thorttle = -180, neutrol = 0 tot +2
channel2 = map(channel2, 1011, 1940, 0, 180);

channel2 = normalizethrottle(channel2);



 Serial.println(channel2);
writeToFourESC(channel2);
}

/**
 * Test function sending angle to the ESCs from 0 to 180 degrees
 */


/**
 * Displays instructions to user
 */
void displayInstructions()
{  
    Serial.println("READY - PLEASE SEND INSTRUCTIONS AS FOLLOWING :");
    Serial.println("\t0 : Sends 0 throttle");
    Serial.println("\t1 : Sends 180 throttle");
    Serial.println("\t2 : Runs test function\n");
}

void writeToFourESC(int throttle){
     motA.write(throttle);
    motB.write(throttle);
    motC.write(throttle);
    motD.write(throttle);
}

void writeToESC(int throttleEscA, int throttleEscB, int throttleEscC, int throttleEscD){
    motA.write(throttleEscA);
    motB.write(throttleEscB);
    motC.write(throttleEscC);
    motD.write(throttleEscD);
}

int calculatTotalSpeed(int channel2, int channel1, int channel0)
{
  int totalSpeed = channel2 + (1/18 * channel1) + channel0;
  return normalizethrottle(totalSpeed);
   
}
int normalizethrottle(int throttle){
  if(throttle < 0){
    Serial.println("normalize throttle to 0");
    return 0;
    
  }
  if(throttle > 180){
    Serial.println("normalize throttle to 180");
    return 180;
    
  }
  Serial.print("throttle not normalized");
  return throttle;
}

