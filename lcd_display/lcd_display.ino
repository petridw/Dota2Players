/*
  Reads from serial and writes message it receives on first line of lcd. 
  Counts number of updates and displays it on the 2nd lcd line.
*/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 7;

int updateCount;    //# of times pushbutton pressed

void setup() {
  updateCount = 0;
  
  pinMode(buttonPin, INPUT);
  
  // begin serial connection
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
}

void loop() {
  String message;   //# message that displays the count
  int buttonState;
  int receiveWait;
  boolean messageReceived;
  
  buttonState = digitalRead(buttonPin);
  
  receiveWait = 0;
  messageReceived = false;
  
  // only check for message when button is depressed
  if (buttonState == LOW) {
    
    // request players via serial
    Serial.write("Arduino requesting players!");
    
    message = String("Updating!");
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(message);
    
    // wait for message via serial
    while (!messageReceived) {
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
        
        updateCount ++;            //updateCount goes up after receiving message
        messageReceived = true;  //set receivedMsg to true to exit the loop  
      }
      
    }
    
  }
  lcd.setCursor(0, 1);
  message = String("Updates: ") + updateCount;
  lcd.print(message);
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);
}

