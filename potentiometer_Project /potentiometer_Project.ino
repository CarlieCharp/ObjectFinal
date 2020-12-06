//Potentiometer 
#include <Adafruit_NeoPixel.h>
/* Analog Read to LED
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead(). In the easiest case we connect
 * a potentiometer to analog pin 2.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

#define LED_PIN    9 //Connection to LED PIN on the LilyPad
#define LED_COUNT 3 //number of LEDs
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Part of neoPixel library, Setting up “strip” -->Just the name of LEDs we are using 
//NEO_GRB + NEO_KHZ800 -->pre defined color settings and speed 


int potPin = 4;    // select the input pin for the potentiometer   
int val = 0;       // variable to store the value coming from the sensor



void setup() {
  strip.begin(); //Create a "Strip" of LEDs called strip
  strip.show(); // initialize all strip to "off"
  Serial.begin(9600);
  
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  Serial.println(val);
  delay(1000); //just how long to wait
  //if the user is MAD
  if(val>0 &&val<170){
    //values are slit into 5 section (1/5 for each color)
    //1023/5 for each "mood"
    for(int i=0; i<3; i++){
      //int i= 0 -->  just how to count how many times it does this loop
      //i<3 --> tells to do it 2 time
      //i++ --> incrementor, every loop add 1 to i When it gets to 3 I resets to 1

    strip.setPixelColor(i, strip.Color(255, 10, 71)); //red
    // “ i ” is just saying turn on 0 LED first, show it (turn it on)
    //Then goes through and sets the color of each LED and goes to the next 0-2 are the LED’s in order starting at 0

    delay(250);
    //how long to wait
     strip.show(); 
     // .show lets use info given 
    }
  }
  //if the user is NERVOUS
  if(val>171 && val<340){
    for(int m=0; m<3; m++){
    strip.setPixelColor(m, strip.Color(255, 10, 194)); // find pink
    delay(250);
     strip.show(); 
    }
  }
  //if the user is Happy
  if(val>341 &&  val<550){
    for(int j=0; j<3; j++){
    strip.setPixelColor(j, strip.Color(194, 255, 10)); // find yellow
    delay(250);
     strip.show(); 
    }
  }
  //If the user is sick
  if(val>551 && val<750){
    for(int k=0; k<3; k++){
    strip.setPixelColor(k, strip.Color(71, 255, 10)); // find green
    delay(250);
     strip.show(); 
    }
  } 
  //if the user is Sad
  if(val>751 && val<1023){
    for(int l=0; l<3; l++){
    strip.setPixelColor(l, strip.Color(10, 194, 255)); // find blue
    delay(250);
     strip.show(); 
    }
  }  
}  

//how it works
//user ill be told what the mood options are and what the colors corilate to
//they will then be able to use the potentiometer to turn to the color that represents there mood
//if there mood changes they can move to a different mood at any point
