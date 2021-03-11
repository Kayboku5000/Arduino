```
Name    : MMA8453_n0m1 Library                         
Author  : Noah Shibley, NoMi Design Ltd. http://socialhardware.net       
		: Michael Grant, Krazatchu Design Systems. http://krazatchu.ca/                  
Date    : October 10th 2013                                 
Version : 0.3                                               
Notes   : Arduino Library for use with the Freescale MMA8453Q and MMA8452Q via i2c. 
          Some of the lib source from Kerry D. Wong
	  http://www.kerrywong.com/2012/01/09/interfacing-mma8453q-with-arduino/
	  This library has been tested with the Freescale MMA8453Q and MMA8452Q
	  Accelerometer chips. MMA8451 has 14bits digital resolution and it is
	  not implemented in this version.
	  Refer to the examples for how to use this library.
	  To use with MMA8452, uncomment #define MMA8452 in MMA8453_n0m1.h
			
Dependencies:	
	none
```	
			
List of Functions:

```
Function: setI2CAddr
Description: set the i2c device address to a new value, default is 0x1C
Parameters: (int) device address: a common value is 0x1D
------------------------------------------------------	
Function: dataMode
Description: set the device to return raw data values
Parameters: (boolean) enable highRes 10bit,
	    (int) set g force range: [2g,4g,8g]
------------------------------------------------------
Function: x
Return: (int) returns the x axis value
------------------------------------------------------
Function: y
Return: (int) returns the y axis value
------------------------------------------------------ 
Function: z
Return: (int) returns the z axis value
------------------------------------------------------
Function: shakeMode
Description: set to transient detection mode
Parameters: (int) threshold [0-127] formula: 6g/ 0.063g = 95.2 counts, round to 96,
   	    (boolean) enable X, 
   	    (boolean) enable Y,
   	    (boolean) enable Z, 
   	    (boolean) enable MMA8453Q INT pin 2 (false= pin 1), 
   	    (int) arduino INT pin number
------------------------------------------------------
Function: shake
Return: (boolean) returns true if there is shaking (high pass filtered motion)
------------------------------------------------------
Function: shakeAxisX
Return: (boolean) returns true if there is shake on the x axis
------------------------------------------------------
Function: shakeAxisY
Return: (boolean) returns true if there is shake on the y axis
------------------------------------------------------
Function: shakeAxisZ
Return: (boolean) returns true if there is shake on the z axis
------------------------------------------------------ 
Function: motionMode
Description: set to motion detection mode
Parameters: (int) threshold [0-127] formula: 6g/ 0.063g = 95.2 counts, round to 96,
   	    (boolean) enable X, 
   	    (boolean) enable Y,
   	    (boolean) enable Z, 
   	    (boolean) enable MMA8453Q INT pin 2 (false= pin 1), 
   	    (int) arduino INT pin number
------------------------------------------------------  
Function: motion
Return: (boolean) returns true if there is motion
------------------------------------------------------ 
Function: update
Description: update data values, or clear interrupts. Use at start of loop()
------------------------------------------------------ 
Function: regRead
Description: read one of the accelerometer registers
------------------------------------------------------ 
Function: regWrite
Description: set one of the accelerometer registers
------------------------------------------------------
Function: setRangeSetting
Parameters: (int) gScaleRange set g force range: [2g,4g,8g]
Description: Compatibilty Function
------------------------------------------------------
Function: setFullResBit
Parameters: (boolean) highRes enable highRes 10bit
Description: Compatibilty Function
------------------------------------------------------
Function: readAccel
Parameters: (int) *x pass x pointer
	    (int) *y pass y pointer
	    (int) *z pass z pointer
Description: Compatibilty Function
```
