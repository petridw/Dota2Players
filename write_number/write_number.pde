/*
A simple Processing script for displaying the current number of dota 2 players 
*/

import processing.serial.*;

Serial port;
int refreshTime = 1000;

void setup() {
  port = new Serial(this, Serial.list()[1]);
}

void draw() {
  String onoroff[] = loadStrings("http://www.welikelazorguns.us/steamfun/players/players.txt");
  print(onoroff[0]);
  port.write(onoroff[0]);
  delay(refreshTime);
}
