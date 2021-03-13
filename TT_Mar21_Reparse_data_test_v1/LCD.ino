//----------------------------------------------------------------
void lcdDisplay() {
  if (true) {
    delay(10);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("");
    lcd.setCursor(0, 0);
    lcd.print(orbAzi);
    lcd.setCursor(0, 1);  // set the cursor to column 0, line 1
    lcd.print("");
    lcd.setCursor(0, 1);             // (note: line 1 is the second row, since counting begins with 0):
    lcd.print(orbElv);
    //-------sensors-----------------
   
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("nuttin");
  }
}
