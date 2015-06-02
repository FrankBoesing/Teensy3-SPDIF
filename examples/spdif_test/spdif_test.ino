/*
  Demo of the audio sweep function.
  The user specifies the amplitude,
  start and end frequencies (which can sweep up or down)
  and the length of time of the sweep.
   
*/
 
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
//#include <Bounce.h>
#include "output_spdif.h"

AudioSynthToneSweep myEffect;
//AudioOutputI2S      audioOutput;        // audio shield: headphones & line-out
AudioOutputSPDIF     audioOutput;

// The tone sweep goes to left and right channels
AudioConnection c1(myEffect, 0, audioOutput, 0);
AudioConnection c2(myEffect, 0, audioOutput, 1);



const int ledPin = 13;

float t_ampx = 0.8;
int t_lox = 10;
int t_hix = 5000;
// Length of time for the sweep in seconds
float t_timex = 1;
// <<<<<<<<<<<<<<>>>>>>>>>>>>>>>>
void setup(void)
{

  delay(1000);
  Serial.begin(9600);
   Serial.println("Start");
     AudioMemory(16);
}

void loop(void)
{ 
  
    if(!myEffect.play(t_ampx,t_lox,t_hix,t_timex)) {
    Serial.println("AudioSynthToneSweep - begin failed");
    while(1);
  }
  // wait for the sweep to end
  while(myEffect.isPlaying());

  Serial.println("Done");

}
