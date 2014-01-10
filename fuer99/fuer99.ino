#include <Adafruit_NeoPixel.h>
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008

//byte mac[] = { 0xDE, 0xAD, byte(random(0,249)), byte(random(0,249)), byte(random(0,249)), byte(random(0,249)) };
IPAddress ip(192, 168, 0, 55);
EthernetUDP Udp;
byte packetBuffer[216]; //buffer to hold incoming packet,
Adafruit_NeoPixel strip = Adafruit_NeoPixel(432, 7, NEO_GRB + NEO_KHZ800);

void setup() {
    Ethernet.begin(0,ip);
  Udp.begin(8888);
  strip.begin();
  strip.show();

}

void loop() {
  if(Udp.parsePacket())
  {
  int count = 0;
  for (int i = 0; i <= 6; i++) {
   Udp.read(packetBuffer,216);
   for (int w = 0; w <= 72; w++) {
     strip.setPixelColor(w+(i*72),strip.Color(packetBuffer[w*3],packetBuffer[1+(w*3)],packetBuffer[2+(w*3)]));
   }
  }
  }
  strip.show();
  
  
}




