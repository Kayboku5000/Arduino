#include <HCSR04.h>

int a = 5;
int b = 6;
int c = 7;

String LFT= "j = ";


HCSR04 hc(2,new int{a},3);//initialisation class HCSR04 (trig pin , echo pin, number of sensor)
HCSR04 hc(2,new int{b},3);//initialisation class HCSR04 (trig pin , echo pin, number of sensor)
HCSR04 hc(2,new int{c},3);//initialisation class HCSR04 (trig pin , echo pin, number of sensor)


void setup()
{ Serial.begin(9600); }

 void loop(){
 Serial.print(LFT);
 for (int i = 0; i < 3; i++ ) {Serial.print( hc.dist(i) ); Serial.print("    "); }
 Serial.println();
 
 }//return curent distance in serial for sensor 1 to 3



 //void loop(){
  //Serial.print(LFT);
  
//{ Serial.print( hc.dist( a ) );  //return current distance (cm) in serial
//Serial.print( hc.dist( b ) );
//Serial.print( hc.dist( c ) );}
//Serial.println();
  
 
