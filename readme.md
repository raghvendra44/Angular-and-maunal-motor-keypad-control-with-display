# **This is a basic motor control project using an arduino code with keypad control and a lcd 16*2 display for visualising the output**

## Components Details:

**1. Arduino Uno**

**2. Motor with encoder (model: rmcs-5033)**
_ - Encoder type : Quad Encoder (Usually all encoders are of this type)
 - Lines on Encoder : 41 (might vary in your case, so do check the datahseet before using it for your project)
 - End shaft Counts per rotation : 8545 counts
 - 300 RPM 12V Rhino High Torque Quad Encoder DC Geared Motor with Metal Planetary Motor, Quad Encoder and Metal Gears
 - 18000 RPM base motor
 - Motor rated Torque is 10 kgcm along with gearbox and stall torque is even higher than 40 kgcm.
 - No-load current : 800 mA, Load current : upto 7.5 A(Max) 
Reference - https://rhinomc.com/products/dc-servo-encoder-12v-motor/rhino-300rpm-5kgcm-12v-dc-planetary-geared-quad-encoder-servo-motor-rmcs-5033/_

**3. Motor driver (model: rmcs - 2303)**
_Rhino DC servo driver 10V -30V 50W 5A Compatible with modbus URAT ASCII mainly for encoder DC motors. usually used along with various modes in built with its library arduino library.
Datasheet : https://robokits.co.in/downloads/RMCS-2303%20updated%20datasheet.pdf_

**4. Keypad (4*4)**
_It is a basic keypad with 16 buttons in total, with 0,9 number keys, A to D keys adn the remaining 2 are * and #._

**5. LCD I2C display (16*2)**
_This is a LCD display which is coupled with an I2C for interfacing and simplicity._

**7. Power source 12V ( to power the driver and motor)**
**8. Jumper cable**

## **Circuit diagram**

**1. Motor - > driver -> Arduino Uno**
![Motor_2_Uno](https://github.com/raghvendra44/Angular-and-maunal-motor-keypad-control-with-display/blob/main/circuit_1.PNG?raw=true)

**2. Keypad and Lcd connected to Arduino Uno**
![Keypad_LCD_2_Uno](https://github.com/raghvendra44/Angular-and-maunal-motor-keypad-control-with-display/blob/main/circuit_2.PNG?raw=true)
 
## **Information about the code and keypad function for each mode**

It has mainly 4 functions
**A. Home position**
This Function moves the motor to the 0th position.
**B. Angular mode**
This functions take the angle in degrees from the keypad and then moves to that position. The position is relative to the actual 0 of the motor.
_Keypad Functions:_
Numbers - to enter the angle.
* - backspace. used in case of error in entering angle.
D - Exit out of the current mode.
#(hash) - This sends the angle to the driver.

**C. Manual mode**
This function is used to move the motor to and fro using 2 buttons at a particular speed given by the user.
_Keypad Functions:_
* - backspace. used in case of error in entering angle.
D - Exit out of the current mode and to also submit speed entered.
#(hash) - This sends the angle to the driver.
C - moves the motor in Clockwise direction.
A - moves the motor in Anit-Clockwise direction.
B - to apply breaks on the motor

**D. Reset**
This basically resets the whole code, to overcome any malfunctioning 
 
