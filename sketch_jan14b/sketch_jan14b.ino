/*  Accelerometer Test
   Written by Allen Lee (alee@sparke.ca)
   Uses the Lilypad Accelerometer (ADXL335)
   IMPORTANT:  SUPPLY THE ACCELEROMETER WITH VDD=3.3 V  JUMPER 3.3 V ON AN UNO TO AREF
   A good tutorial on accelerometers is on Instructables at: http://www.instructables.com/id/Accelerometer-Gyro-Tutorial
*/


// Setup global variables for analog read (x,y & z), voltages (vx,vy & vz) and g-readings (gx,gy & gz)
int x;
int y;
int z;
float vx; 
float vy;
float vz;
float gx;
float gy;
float gz;

void setup(){
 Serial.begin(9600);
 // analogReference(EXTERNAL);    //set aref to 3.3v, if you use built in 3.3v for value, use a 15K resistor to limit current
pinMode (x, INPUT);
pinMode (y, INPUT);
pinMode (z, INPUT);
}


void loop()
{
 // Read in accelerometer values
 x = analogRead(A0);
 y = analogRead(A1);
 z = analogRead(A2);
 
 // Convert ADC values to voltages and G values
 // The formula for voltage conversion is v = (ADCREAD*VREF/1023)-ZGV, where ZGV is "Zero-G voltage" (voltage at 0G)
 // ZGV is found in the spec sheet and happens to be 1.5 in our case.  Warning: you need to make the variable signed!
 // The formula for G conversion is g = v/SENSITIVITY.  The sensitvity is also found in the spec sheet and happens to be 300 mV/g here.
 // Remember to make your units consistent! (g = v[V]*1000 / SEN [mV] )
 vx = (x*3.3/1023)-1.62;
gx = vx*10/8;
 vy = (y*3.3/1023)-1.62;
gy = vy*10/8;
 vz = (z*3.3/1023)-1.62;
gz = vz*10/8;
 
 Serial.print("vx=");
 Serial.print(vx,DEC);   // delet the dec?
 Serial.print("  ");
 Serial.print("vy=");
 Serial.print(vy,DEC);   //delete the dec?
 Serial.print("  ");
 Serial.print("vz=");
 Serial.println(vz,DEC);   //delete the dec?
 
 delay(50);
 
}
 
