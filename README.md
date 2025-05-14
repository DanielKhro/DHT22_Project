# DHT22_Project
ECE 425 real world application project

Introduction:
This project implements what was taught in ECE 425 lecture of embedded systems into a real-world application revolving something that is important to every individual, temperature, and humidity. Day-to-day life is revolving around these systems that inform us of these two parameters, affecting the way we dress, the plans we make, and the precautions that we must take globally to protect against dangerous consistent levels. To fulfill this objective, UART, SysTick Timers, and GPIO configurations were set with a DHT22 sensor. This sensor will provide accurate readings of the temperature and humidity within the room it is located in. These are handy as they can be manipulated anywhere to measure readings.

Results
![image](https://github.com/user-attachments/assets/d3593fad-231c-4c5f-8eed-a88565d22ef2)
![image](https://github.com/user-attachments/assets/45006880-04dc-4ba7-a192-9dc05f89f15e)
![image](https://github.com/user-attachments/assets/f5089593-ae4e-4b93-b2fb-a8cc14c56d20)
![image](https://github.com/user-attachments/assets/21c1483f-b17a-4522-b893-c256f82c4caf)

Video Demonstration link: https://www.youtube.com/watch?v=hv1eZDRZvY8&t=2s&ab_channel=DanielKhrlobian

Background and Methodology:
The concepts I have applied are forms of serial communication from the microcontroller to a computer terminal when data logging bits of data from a sensor device. The sensor is the one hardware component I used besides the microcontroller. With the sensor, it has a Vcc and ground as usual with a minimum of 3.3V needed which matched the 3.3V on our microcontroller. It had a single data pin that produced digital values based off the length of its high signals.
One of the peripherals I implemented was UART which fulfills communication between the microcontroller and computer. SysTick timer was implemented to create accurate time delays that the sensor needs to run properly as the initialization sequence and data sequence is delicate while sensitive. To fulfill the startup sequence and yet receive data, a GPIO pin needed to be initialized which will flip back and forth as an input and output. All the data and implementation will move over onto a computer terminal ttermpro to display our results from the collected data array from the C program.


Block Diagram:![image](https://github.com/user-attachments/assets/caa06891-690e-4538-ba5f-3c9bfeda4800)

Components Used: 
Component	Quantity
Microcontroller (TM4C123GH6PM)	1
DHT22 Temperature/Humidity Sensor	1
Jumper Wires	6
Breadboard	1


Pinout:
DHT Sensor (DATA)	PA2 (GPIO)	Sensor Data Pin communication input and output
DHT Sensor (VCC)	3.3V Microcontroller Pin	Power supply for sensor
DHT Sensor (GND)	Ground Microcontroller Pin	Ground Pin for sensor
