This is a basic motor control project using a arduino code with keypad control and a lcd 16*2 display for visualising the output.

Components Details:

1. Arduino Uno

2. Motor with encoder (model: rmcs-5033)
 - Encoder type : Quad Encoder (Usually all encoders are of this type)
 - Lines on Encoder : 41 (might vary in your case, so do check the datahseet before using it for your project)
 - End shaft Counts per rotation : 8545 counts
 - 300 RPM 12V Rhino High Torque Quad Encoder DC Geared Motor with Metal Planetary Motor, Quad Encoder and Metal Gears
 - 18000 RPM base motor
 - Motor rated Torque is 10 kgcm along with gearbox and stall torque is even higher than 40 kgcm.
 - No-load current : 800 mA, Load current : upto 7.5 A(Max) 
Reference - https://rhinomc.com/products/dc-servo-encoder-12v-motor/rhino-300rpm-5kgcm-12v-dc-planetary-geared-quad-encoder-servo-motor-rmcs-5033/

3. Motor driver (model: rmcs - 2303)
RHINO DC SERVO DRIVER 10V-30V 50W 5A COMPATIBLE WITH MODBUS UART ASCII FOR ENCODER DC SERVO MOTOR with various modes in built with its library arduino library.
Datasheet : https://robokits.co.in/downloads/RMCS-2303%20updated%20datasheet.pdf

4. Keypad (4*4)
It is a basic keypad with 16 buttons in total, with 0,9 number keys, A to D keys adn the remaining 2 are * and #.
5. LCD I2C display (16*2)
This is a LCD display which is coupled with an I2C for interfacing and simplicity.

7. Power source 12V ( to power the driver and motor)
8. Jumper cable

Circuit diagram
1. Motor - > driver -> Arduino Uno              
![alt text](https://github.com/raghvendra44/Angular-and-maunal-motor-keypad-control-with-display/blob/circuit_1.PNG?raw=true)





 
