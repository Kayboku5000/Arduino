
void Orbitron_Telem_Recieve() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;}
     }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true; }
    }
    else if (rc == startMarker) {
      recvInProgress = true;  }
  }
   if (newData == true) {
     strcpy(tempChars, receivedChars);
     parseTelem(); }         //send to strtok to split data
}
  
//---------------------------------------------------------

void parseTelem() {      // split the telem into azi and elv
  char * strtokIndx; // this is used by strtok() as an index
  strtokIndx = strtok(tempChars, ",");     // get the first part - the string
  strcpy(messageFromPC, strtokIndx); // 
  strtokIndx = strtok(NULL, ","); // 
  orbAzi = atof(strtokIndx);     // convert this part to Azimuth
  strtokIndx = strtok(NULL, ",");
  orbElv = atof(strtokIndx);     // convert this part to ELevation
}
