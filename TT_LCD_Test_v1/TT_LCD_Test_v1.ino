#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup() {

  // Setup the LCD display
  lcd.begin(16, 2);
  // Set cursor to top line first position
  lcd.setCursor(0, 0);
  // Print message on first line
  lcd.print("Push a button");

}



void loop() {
  delay(500);

  // Move cursor to second line, 9 spaces over
  lcd.setCursor(9, 1);
  // Display seconds elapsed since reset
  lcd.print(millis() / 1000);

  // Move to the begining of the second line
  lcd.setCursor(0, 1);
  
  for (int x =1 ; x < 100; x = x + 1) {
     lcd.setCursor(0, 1);
    lcd.print(x);
    delay(500);
  }






}
