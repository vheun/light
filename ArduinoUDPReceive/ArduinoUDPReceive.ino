#include <Adafruit_NeoPixel.h>
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008

// Neopixel Config
#define PIXEL_PIN (7)
#define PIXEL_COUNT (54 * 4)
#define COLOR_DEPTH (3)
#define PIXEL_BRIGHTNESS (128)
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


// Ethernet Config
EthernetUDP Udp;
// Buffers for receiving and sending data
//char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
const int BUFFER_SIZE = PIXEL_COUNT * COLOR_DEPTH;
char packetBuffer[BUFFER_SIZE]; //buffer to hold incoming packet,

void setup() {
  initEthernet();
  // Initialize the neo pixel strip.
  strip.begin();
  strip.show();
  strip.setBrightness(PIXEL_BRIGHTNESS);

  Serial.begin(115200);
}

void initEthernet() {

  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  IPAddress ip(192, 168, 1, 54);
  unsigned int localPort = 8888;      // local port to listen on
  // Start the Ethernet and UDP:
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);
}

void loop() {
  // If there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if(packetSize) {
    // read the packet into packetBufffer
    Udp.read(packetBuffer,BUFFER_SIZE);
    
    // Print Packet Info
    Serial.print("Received size ");
    Serial.println(packetSize);
    /*
    Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i =0; i < 4; i++)
    {
      Serial.print(remote[i], DEC);
      if (i < 3)
      {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());
    */
    
  
    Serial.println("Contents:");
    for (int i = 0; i < packetSize; ++i) {
      Serial.write(packetBuffer[i]);
    }
    Serial.write(10);
    
    
    // Set Strip Colors
    int loc;
    for(int i = 0; i < PIXEL_COUNT; ++i) {
      loc = i * COLOR_DEPTH;
      strip.setPixelColor(i, packetBuffer[loc + 0], packetBuffer[loc + 1], packetBuffer[loc + 2]);
    }
    // Show the output
    strip.show();
    
    //Serial.println(packetBuffer);
  }
  //delay(10);
}




