# **This is a basic motor control project using an arduino code with keypad control and a lcd 16*2 display for visualising the output**

## Components Details:

**1. Arduino Uno**

**2. Motor with encoder (model: rmcs-5033)**
 - _Encoder type : Quad Encoder (Usually all encoders are of this type)_
 - _Lines on Encoder : 41 (might vary in your case, so do check the datahseet before using it for your project)_
 - _End shaft Counts per rotation : 8545 counts_
 - _300 RPM 12V Rhino High Torque Quad Encoder DC Geared Motor with Metal Planetary Motor, Quad Encoder and Metal Gears_
 - _18000 RPM base motor_
 - _Motor rated Torque is 10 kgcm along with gearbox and stall torque is even higher than 40 kgcm._
 - _No-load current : 800 mA, Load current : upto 7.5 A(Max)_

Reference - https://rhinomc.com/products/dc-servo-encoder-12v-motor/rhino-300rpm-5kgcm-12v-dc-planetary-geared-quad-encoder-servo-motor-rmcs-5033/

**3. Motor driver (model: rmcs - 2303)**
- _Rhino DC servo driver 10V -30V 50W 5A Compatible with modbus URAT ASCII mainly for encoder DC motors. usually used along with various modes in built with its library arduino library._

Datasheet : https://robokits.co.in/downloads/RMCS-2303%20updated%20datasheet.pdf

**4. Keypad (4*4)**
- _It is a basic keypad with 16 buttons in total, with 0,9 number keys, A to D keys adn the remaining 2 are * and #._

**5. LCD I2C display (16*2)**
- _This is a LCD display which is coupled with an I2C for interfacing and simplicity._

**7. Power source 12V ( to power the driver and motor)**

**8. Jumper cable**

## **Circuit diagram**

**1. Motor - > driver -> Arduino Uno**
![Motor_2_Uno](https://github.com/raghvendra44/Angular-and-maunal-motor-keypad-control-with-display/blob/main/circuit_1.PNG?raw=true)

**2. Keypad and Lcd connected to Arduino Uno**
 ### - Small change: The image shows the keypad is connected from 9 to 2, but in the code, the keypad is connected from 13 to 6 (Note the change)
![Keypad_LCD_2_Uno](https://github.com/raghvendra44/Angular-and-maunal-motor-keypad-control-with-display/blob/main/circuit_2.PNG?raw=true)
 
## **Information about the code and keypad function for each mode and their working**

It has mainly 4 functions

**A. Home position**
- This Function moves the motor to the 0th position.

**Working**

You can choose to go to home position( 0th degrees) no matter in which mode you are.

**B. Angular mode**

- This functions take the angle in degrees from the keypad and then moves to that position. The position is relative to the actual 0 of the motor.

_Keypad Functions:_

- Numbers - to enter the Speed and Angle.
- Asterisk : backspace. used in case of error in entering angle. or it is also works as back button( only at a particular point).
- Hash : This sends the angle to the driver.
- B : Increments the angle given.
- 2 or 8 : To increase or decrease speed value by 5% ( This works after you have submitted the angle value)
- A : To go back to home position.
- C : To shift to manual mode.
- D : Exit out of the current mode.

**Working:**

- First, enter the RPM(speed) of your shaft, then press *hash* to submit your value, and if you make an error in entering u can press *asterisk* (before pressing hash). (Note : Since my motor has 41 lines per rotation, so approximately 23.74 pulses is rquired for the shaft to give by 1 degree. and 8545 pulses is required to move the shaft 360 degrees. This might vary in your case)
- then you enter the angle you required the shaft to move, then press *hash* to submit your value, and if you make an error in entering u can press *asterisk* (before pressing hash).
- Now you will be displayed your entered values. On pressing *Hash* at this stage would start the motor. (If you are willing to change the values, press *Asterisk*, acts as back button), this would take you at the start position where you restart the process of entering values for speed and angle.)
- After the motor reaches the angle given, it displays prev ( that is basically the position in which it is) and the speed that was given.
- At this step, if you press *B* , it will rotate the same distance again ( incremental). 
- Or if you wish to change the speed value by a small fraction, then you may press *2* or *8* to increase/decrease the speed by 5%.
- Or if you are willing to change the value completely then you can press *Asterisk* and repeat the whole process.
- At any point of time, if you are willing to go at *Home position* or shift to *manual mode* then you can press *A* for home position or *C* for manual mode.
- Pressing *D* would automatically exit the mode. 


**C. Manual mode**
- This function is used to move the motor to and fro using 2 buttons at a particular speed given by the user.

_Keypad Functions:_

- Numbers - to enter the Speed
- Asterisk : backspace. used in case of error in entering angle. or it is also works as back button( only at a particular point).
- Hash : This sends the angle to the driver. 
- 4 or 6 : moves the motor in Clockwise direction or Counter-Clockwise direction.
- 2 or 8 : To increase or decrease speed value by 5% ( This works after you have submitted the speed value)
- A : To go back to home position.
- C : To shift to manual mode.
- D : Exit out of the current mode.

**Working**

- First you get the range of RPM i.e 2 -> 300 ( might vary in your case).
- You may enter the speed you desire. then either press *Asterisk* to fix the error made in entering value.
- After entering the desired value. press *hash* to submmit value.
- Then you will be prompted the operations that will be helpful.
- Once *MAN* is seen on the screen, you can move the motor using *4* or *6* to move it in CW or CCW direction.
- If you wish to change the speed value, you may press *2* or *8* to increase/decrease the speed by 5%.
- If you wish to change the speed completely then you may press *Asterisk* for that purpose and repeat the process
- At any point of time, if you are willing to go at *Home position* or shift to *Angular mode* then you can press *A* for home position or *B* for manual mode.
- Pressing *D* would automatically exit the mode. 

**D. Reset**
- This basically resets the whole code, to overcome any malfunctioning

Note: The speed refered here is basically RPM of the Shaft.
