void motorsMove() {                 //Rotation/ Azimuth
    if (integerFromPC > 1){    
        AZforwardStep();    
    }
}
    
void motorsMove2() {             //Elevation
    
  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("    y:");
  Serial.println((float)event.orientation.y);
  delay(BNO055_SAMPLERATE_DELAY_MS);
  int Mstop = (floatFromPC == ((float)event.orientation.y));
    
    if(floatFromPC >((float)event.orientation.y)){
        ELforwardStep();
    }
    
    else if(floatFromPC <((float)event.orientation.y)){    
        ELbackwardStep();  
    }
     else { digitalWrite(stepPinY,LOW);
}
}


void sensY() {
  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("    y:");
  Serial.println((float)event.orientation.y);
  delay(BNO055_SAMPLERATE_DELAY_MS);
}  

integerFromPC change to orbAzi
floatFromPC change to orbElv


orbElv = 1 or 180
if ((orbElv < Bn55 -1) && (orbElv > Bn55 +1))
