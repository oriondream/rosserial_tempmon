#include <ros.h>
#include <std_msgs/Float32.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <temp_mon/Temperature.h>

#define ONE_WIRE_PIN 2 

temp_mon::Temperature temp;

ros::NodeHandle nh;
ros::Publisher tempPub("Temperature", &temp);

OneWire oneWire(ONE_WIRE_PIN); 
DallasTemperature sensors(&oneWire);

long nReading;

void setup() {
    nReading = 0;
    
    nh.initNode();
    nh.advertise(tempPub);
    
    sensors.begin();
}

void loop() {
    sensors.requestTemperatures();
    
    temp.data = sensors.getTempCByIndex(0);
    temp.counter = nReading;
    // temp.timestamp = ros::Time::now();
    
    tempPub.publish(&temp);
    
    ++nReading;
    
    nh.spinOnce();
    delay(1000);
}
