/*
  Reads from serial and writes message it receives on first line of lcd. 
  Counts number of updates and displays it on the 2nd lcd line.
*/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int count = 0;
String message;

void setup() {
  // begin serial connection
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
}

void loop() {
  
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen & set the cursor
    lcd.clear();
    lcd.setCursor(0, 0);
    // read all the available characters
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
    count ++;
    
  }
  lcd.setCursor(0, 1);
  message = String("Updates: ") + count;
  lcd.print(message);
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);
}

