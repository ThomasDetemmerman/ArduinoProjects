//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// The Unnamed Circuit
// 
// Made by detemmerman thomas
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/5255240-the-unnamed-circuit

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 7;
int number0[] = {1,2,3,5,0,6,7};
int number1[] = {3,7,0,0,0,0,0};
int number2[] = {2,3,4,5,6,0};
int number3[] = {2,3,4,7,6,0,0};
int number4[] = {1,0,3,4,7,0,0};
int number5[] = {2,1,4,6,7,0,0};
int number6[] = {1,2,0,4,5,6,7};
int number7[] = {3,7,2,0,0,0,0};
int number8[] = {1,2,3,4,5,6,7};
int number9[] = {2,3,4,7,6,0,1};
int maxArrayLengt = 7;
int delaytime = 600;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
  pinMode(led6, OUTPUT);
   pinMode(led5, OUTPUT);
   pinMode(led7, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  printnumber(number0);
  delay(delaytime);
printnumber(number1);
  delay(delaytime);
 printnumber(number2);
  delay(delaytime);
  printnumber(number3);
  delay(delaytime);
  printnumber(number4);
  delay(delaytime);
  printnumber(number5);
  delay(delaytime);
   printnumber(number6);
  delay(delaytime);
   printnumber(number7);
delay(delaytime);
printnumber(number8);
 delay(delaytime);
  printnumber(number9);
 delay(delaytime);
}

void printnumber(int arr[])
{  
  dissableAllLights();
  for(int i=0; i<maxArrayLengt ; i++)  
  {
    digitalWrite(arr[i], HIGH); 
   

  }
 

}

void dissableAllLights(){
	for(int i=1; i<=maxArrayLengt ; i++)
    
  {
    digitalWrite(i, LOW); 
    

  }
 
}
