



void lcdDisplay() {
  if (Compassaverage > 0 && Compassaverage < 360) {
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
    lcd.setCursor(7, 0);
    lcd.print("A");
    lcd.setCursor(10, 0);
    lcd.print(Compassaverage);
    lcd.setCursor(7, 1);  // set the cursor to column 0, line 1
    lcd.print("E");
    lcd.setCursor(10, 1);             // (note: line 1 is the second row, since counting begins with 0):
    lcd.print(Bn55);


  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("nuttin");
  }
}
