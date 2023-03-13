# Concurrent-Processing-and-Bare-Metal-Project

#Purpose of this project is to demonstrate my experience in 
1. Controlling and running multiple processes on a single microcontroller.
2. Controlling the digital pins of the Arduino microcontroller ATMEGA328P in a bare-metal fashion.

TASKS INVOLVED IN THIS PROJECT.

I wrote code modules that run concurrently in a non-blocking fashion. These modules include,
1. Control of Traffic lights.
2. Heart beat indicator module
3. Switch debounce module for detecting keypresses.
4. Switch debounce module for changing modes 
5. Counter module on a 7 segment display using a shift register.
6. Orientation indicator by the use of accelerometer MPU6050.

SUMMARY OF THE CODE ATTACHED ABOVE.
1. The code attached above containes a schedular that allows the user to change through modules and for each of the modules individually.
2. The code above is also written in an object oriented form and each of the skeleton modules mentioned above have been placed in a different class.

![image](https://user-images.githubusercontent.com/105231479/224717454-4b77bb66-0785-41e7-b886-0d3757c5a0da.png)


HARDWARE USED IN THIS PROJECT.
1. 6 led's for the traffic lights controller module with appropriate resistors.
2. One Seven segment digital display with appropriate resistors.
3. One 74HC595 shift register.
4. Two Push button.
5. One GY-521 module with MPU6050 accelerometer
6. Resistors for current limitation.

TRAFFIC LIGHTS MODULE.

The traffic lights controller module controlls 2 ways

~ Traffic lights Station1 control the North to South path.
~ Traffic lights Station2 control the East to West path.

![image](https://user-images.githubusercontent.com/105231479/224699986-f311c4e6-aff1-4c09-9db9-3312cfa1d4ff.png)

The table above demonstrates how the traffic lights operate in this project. 

If there are lights switched on in any of the states, it means that the other lights are switched off.

1. The safe state is at 0, where all the traffic lights are in order. This state runs once each time traffic lights has started and then the system will continue with the normal cycle.
2. The traffic lights priority will change when either station of light is green and when triggered.
3. When the trafficlights controller isn't running the LED's are switched off.
4. The LED's that are used to represent traffic lights are driven in a bare-metal approach.

HEART BEAT MODULE.

The heart beat is represented by the decimal point segment on the 7 segment display. It blinks on and off as a heart beat to indicate that the system is active. The heart beat segment is on for 340 milliseconds and off for 340 milliseconds.

The seven segment module in this project is driven in a bare metal fashion by the Arduino using the shift register.

PUSHBUTTON SWITCH MODULES.

I used 2 pushbutton switches in this project.

1. Switch 1 is used to count button presses and the counter for each press is displayed on the 7 segment.
2. Switch 2 is used to change modes.

In both of the cases for the switch button used in this project a debounce routine was used. The debounce time of 300milliseconds was used.

The pushbutton switch are also in a bare metal fashion by the Arduino.

COUNTER MODULE.

In this project, the system increments the counter when switch 1 is pressed after 300 milliseconds. The seven segment displays numbers 0 - 9 and letters A,b,C,D,E and F after 300 milliseconds when the pushbutton switch 1 is pressed.

When the counter module in this project is restarted, the system in this project starts the count from where it was left off.

ACCELEROMETER MODULE.

In this project, when the accelerometer module is running, the 7 segment LED display displays the orientation of the board. It represents as follows,

1. F for flat.
2. L for landScape
3. U for upside down
4. l for left when rotated left.
5. r for right potrait.

When the board is flat or landscape the system in this project sets the traffic lights to equal priority.

The system in this project sets traffic lights to Station1 priority when the board is oriented left and Station 2 priority when the board is oriented right.

MODES 

The software in this project starts at mode 1. The Switch 2 triggers change to the next mode. If Switch 2 is pressed when the system is at mode 5, the software directs the system back to mode 1 and the cycle continues.

Consider the image below,

![image](https://user-images.githubusercontent.com/105231479/224709389-824708ae-59e0-46f9-8904-34650010be55.png)

The table above describes how the system in this project runs.

In the first mode above when the counter and accelerometer modules are not running, the seven segment displays letter 't'

Thank you for showing interest in the project that I have done.

This project is from one of the assignments that I have done whilst at De-Montfort University.
