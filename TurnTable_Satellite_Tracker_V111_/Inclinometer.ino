



void Inclinometer() {   // Elevation
  sensors_event_t event;
  bno.getEvent(&event);
  Bn55 = (90 + ((float)event.orientation.y));
  //Serial.print("Inclinometer (degrees): "); Serial.print(Bn55);
  uint8_t sys, gyro, accel, mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
  delay(100);

}
