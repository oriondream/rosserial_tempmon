# Introduction

This ROS-serial project uses an arduino board to read a DS18B20 temperature 
sensor and publish the temperature in the /Temperature topic as it is
connected to a ROS computer.

# Hardware connection
The output pin of the sensor should be connected to digital pin 2. A pull up
resistor of 4.7kohm should be placed between the Vin and the data pin of the 
sensor.

# Prerequisits

## rosserial_arduino and rosserial must be installed. 
    sudo apt-get install ros-indigo-rosserial-arduino

# Updating the arduino library
Once the package is built, the message should be imported to arduino IDE
using as followed:
    rosrun rosserial_arduino make_libraries.py <Arduino>/libraries 

# Compile and upload the arduino sketch
Open the rosserial_tempmon.ino in arduino IDE. Compile and upload it to the
arduino board.

# Connect the board to ROS 
Connect the board to using its device id (e.g. ttyUSB0) as followed:
    rosrun rosserial_python serial_node.py /dev/ttyUSB0

# Monitor output
Open a new terminal and read the ROS topic Temperature
    rostopic echo /Temperature
