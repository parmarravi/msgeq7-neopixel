
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#define PIN  3
#define NUMPIXELS  16
int STROBE_PIN = 4;
int RESET_PIN = 2;
int ANALOG_PIN = A0;
int filter=80;
int bandValues[7];
int bandNo;
char buf[4];
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pinMode(RESET_PIN, OUTPUT);
  pinMode(STROBE_PIN, OUTPUT);
 
  // RESET
  digitalWrite(RESET_PIN, LOW);
  digitalWrite(STROBE_PIN, HIGH);
  
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop() 
{
readMSGEQ7();  
 for (bandNo = 0; bandNo < 7; bandNo++)
  {
   if(bandValues[0] >bandValues[2])
   {
   violet(bandValues[bandNo]);
   violet(bandValues[bandNo +1]);
   }
   else if(bandValues[2] >bandValues[3])
   {
    //This band contains random noise thus left empty  
   }
    else if(bandValues[3] >bandValues[4])
   {
    yellow(bandValues[bandNo]);
   }
    else if(bandValues[4] >bandValues[5])
   {
    orange(bandValues[bandNo]);
   }
   else if(bandValues[5] >bandValues[6])
   {
   red(bandValues[bandNo]);
   }
   else
   {
    White(bandValues[bandNo]);
   }
}
}
void readMSGEQ7()
{
  digitalWrite(RESET_PIN, HIGH);
  digitalWrite(RESET_PIN, LOW);
 
  for (bandNo = 0; bandNo < 7; bandNo++)
  {
    digitalWrite(STROBE_PIN, LOW);
    delayMicroseconds(30);
    bandValues[bandNo]=analogRead(ANALOG_PIN);
    bandValues[bandNo]=constrain(bandValues[bandNo], filter, 1023);
    bandValues[bandNo]=map(bandValues[bandNo], filter,1023,0,255);
    digitalWrite(STROBE_PIN, HIGH);
  }
}
void violet(uint32_t i){

  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(148,0,211)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
    delay(10);
  }
  void indigo(uint32_t i){

  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(75,0,130)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
    delay(10);
  }
void blue(uint32_t i){

  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(0,0,255)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
    delay(10);
  }
  void green(uint32_t i){

  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(0,255,0)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
    delay(10);
  }
  void yellow(uint32_t i){

  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(255,255,0)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
    delay(10);
  }
  void orange(uint32_t i){

  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(255,127,0)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
    delay(10);
  }
  void red(uint32_t i){
  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(255,0,0)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  delay(10);
  }
  void White(uint32_t i){
  for(int j=0;j<NUMPIXELS;j++)
  {
    pixels.setBrightness(i);
    pixels.setPixelColor(j, pixels.Color(255,255,255)); //.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  delay(10);
  }

