/*
A simple Processing script for displaying the current number of dota 2 players 
*/

import processing.serial.*;

Serial port;
int refreshTime = 1000;

void setup() {
  port = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  String inBuffer;
 
  // see if request is there
  if (port.available() > 0) {
    delay(100);
    inBuffer = port.readString();
    println(inBuffer);
    
    if (inBuffer.equals("Arduino requesting players!")) {
      loadStrings("http://www.welikelazorguns.us/steamfun/players/currentplayers.php");
      String players[] = loadStrings("http://www.welikelazorguns.us/steamfun/players/players.txt");
      println(players[0]);
      port.write(players[0]);
    }
  }
  
}
