import java.util.Arrays;
import java.util.Collections;

import hypermedia.net.*;
 
// UDP config
UDP udp;  // define the UDP object
String ip       = "192.168.1.54";  // the remote IP address
int port        = 8888;    // the destination port

// Strip Config
final int STRIP_COUNT = 4;
final int STRIP_LENGTH = 54;
final int PIXEL_COUNT = STRIP_LENGTH * STRIP_COUNT;
final int COLOR_DEPTH = 3;
char pixels[] = new char[PIXEL_COUNT * COLOR_DEPTH];

void setup() {
  udp = new UDP( this, 6000 );  // create a new datagram connection on port 6000
  //udp.log( true );     // <-- printout the connection activity
  
  frameRate(60);
  
  for (int i = 0; i < 2; ++i) {
    int loc0 = (i * STRIP_LENGTH);
    int loc1 = (i * STRIP_LENGTH) + 26;
    initPixelPattern(loc0);
    initPixelPattern(loc1);
  }
}

void initPixelPattern(int locSeed) {
  int loc;
  loc = (locSeed + 0) * COLOR_DEPTH;
  pixels[loc + 0] = 255; // red
  pixels[loc + 1] = 0; // green
  pixels[loc + 2] = 0; // blue
  
  loc = (locSeed + 1) * COLOR_DEPTH;
  pixels[loc + 0] = 255; // red
  pixels[loc + 1] = 255; // green
  pixels[loc + 2] = 0; // blue
  
  loc = (locSeed + 2) * COLOR_DEPTH;
  pixels[loc + 0] = 0; // red
  pixels[loc + 1] = 255; // green
  pixels[loc + 2] = 0; // blue
  
  loc = (locSeed + 3) * COLOR_DEPTH;
  pixels[loc + 0] = 0; // red
  pixels[loc + 1] = 255; // green
  pixels[loc + 2] = 255; // blue
  
  loc = (locSeed + 4) * COLOR_DEPTH;
  pixels[loc + 0] = 0; // red
  pixels[loc + 1] = 0; // green
  pixels[loc + 2] = 255; // blue
  
  loc = (locSeed + 5) * COLOR_DEPTH;
  pixels[loc + 0] = 255; // red
  pixels[loc + 1] = 0; // green
  pixels[loc + 2] = 255; // blue
}
 
void draw() {
  // Update pixel pattern
  rotatePixels();
  
  // Send to strip
  String output = String.valueOf(pixels);
  //println("Sending out: " + output);
  udp.send(output, ip, port );   // the message to send
  //udp.send(pixels, ip, port );   // the message to send
}

void rotatePixels() {
  char first0 = pixels[0];
  char first1 = pixels[1];
  char first2 = pixels[2];
  for (int i = 0; i < PIXEL_COUNT - 1; ++i) {
    int loc0 = i * COLOR_DEPTH + 0;
    int loc1 = i * COLOR_DEPTH + 1;
    int loc2 = i * COLOR_DEPTH + 2;
    pixels[loc0] = pixels[loc0 + COLOR_DEPTH];
    pixels[loc1] = pixels[loc1 + COLOR_DEPTH];
    pixels[loc2] = pixels[loc2 + COLOR_DEPTH];
  }
  pixels[pixels.length - 3 + 0] = first0;
  pixels[pixels.length - 3 + 1] = first1;
  pixels[pixels.length - 3 + 2] = first2;
}

 
void keyPressed() {
  //udp.send("Hello World", ip, port );   // the message to send

  rotatePixels();

  /*
  // Set the pixel colors
  int loc;
  for (int i = 0; i < PIXEL_COUNT; ++i) {
    loc = i * COLOR_DEPTH;
    
    //pixels[loc + 0] = 65; // red
    //pixels[loc + 1] = 66; // green
    //pixels[loc + 2] = 67; // blue
    
    pixels[loc + 0] = char(int(random(0, 50))); // red
    pixels[loc + 1] = char(int(random(0, 50))); // green
    pixels[loc + 2] = char(int(random(0, 50))); // blue
  }
  */
  
  // Send to strip
  //String output = String.valueOf(pixels);
  //println("Sending out: " + output);
  //udp.send(output, ip, port );   // the message to send
  //udp.send(pixels, ip, port );   // the message to send
}
 
/*
void receive( byte[] data ) {       // <-- default handler
  //void receive( byte[] data, String ip, int port ) {  // <-- extended handler
 
  for(int i=0; i < data.length; i++) 
  print(char(data[i]));  
  println();   
}
*/

