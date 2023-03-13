# Concurrent-Processing-and-Bare-Metal-Project

#Purpose of this project is to demonstrate my experience in 
1. Controlling and running multiple processes on a single microcontroller.
2. Controlling the digital pins of the Arduino microcontroller ATMEGA328P in a bare-metal fashion.

TASKS INVOLVED IN THIS PROJECT.

I wrote code modules that run concurrently in a non-blocking fashion. These modules include,
1. Control of Traffic lghts.
2. Heart beat indicator module
3. Switch debounce module for detecting keypresses.
4. Switch deounce module for changing modes 
5. Counter module on a 7 segment display using a shift register.
6. Orientation indicator by the use of accelerometer MPU6050.

SUMMARY OF THE CODE ATTACHED ABOVE.
1. The code attached above containes a schedular that allows the user to change through modules and for each of the modules individually.
2. The code above is also written in an object oriented form and each of the skeleton modules mentioned above have been placed in a different class.

HARDWARE USED IN THIS PROJECT.
1. 6 led's for the traffic lights controller module with appropriate resistors.
2. One Seven segment digital display with appropriate resistors.
3. One 74HC595 shift register.
4. One Push button.
5. One GY-521 module with MPU6050 accelerometer
6. Resistors for current limitation.
