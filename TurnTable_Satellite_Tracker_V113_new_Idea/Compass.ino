
void Compass()  {
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  float declinationAngle = 5.23;
  heading += declinationAngle;
  if (heading < 0)
    heading += 2 * PI;
  if (heading > 2 * PI)
    heading -= 2 * PI;
  headingDegrees = heading * 180 / M_PI;
 delay (100);
  //compassfilter();
  //Compassaverage = headingDegrees;
}

//-------------------------------------------
//
//void compassfilter() { //compass
//  // subtract the last reading:
//  Ctotal = Ctotal - Creadings[CreadIndex];
//  // read from the sensor:
//  Creadings[CreadIndex] = headingDegrees;
//  // add the reading to the total:
//  Ctotal = Ctotal + Creadings[CreadIndex];
//  // advance to the next position in the array:
//  CreadIndex = CreadIndex + 1;
//  // if we're at the end of the array...
//  if (CreadIndex >= CnumReadings) {
//    // ...wrap around to the beginning:
//    CreadIndex = 0;
//  }
//  // calculate the average:
//  Compassaverage = Ctotal / CnumReadings;
//  // send it to the computer as ASCII digits
//  //Serial.println(average);
//  delay(1);        // delay in between reads for stability
//
//}
