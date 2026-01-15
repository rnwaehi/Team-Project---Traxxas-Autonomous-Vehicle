# Traxxas Autonomous Vechicle

In introduction, 
this project is all about programming a car
to drive by itself by using the Pico microntroller
of the car. In addition to this, it also has
to avoid any obstacles ahead or behind it by utilising 
sensors.


## Description

As mentioned previously in our introduction,
the overview of our project is about programming
an autonoumous vehicle. However, we have decided
to come up with an in-depth use of our product.
We plan to make our vehicle more robust
by adding a fire detection drone.

So for example, if a fire was to occur
in a forest, the drone will be 
responsible to ensure that the 
fires can be identified rapidly
before the fire spreads.

We are also going to be implementing
a temperature/infrared sensor called MLX90614.
The field of view of the infrared sensors will affect the overall effectiveness of the drone’s operation. 
The idea is that by placing the sensors in a certain configuration,
360 degrees will be covered, allowing for thorough fire detection capability.

The product being developed requires full coverage 
of the surrounding area. 
This means sensor placement is crucial. The sensors selected will provide 90 degrees field of view. 
In theory, 4 sensors with 90 degrees view should add to 360 degrees, however, tolerances in the sensor housing and no overlap means that there is a high possibility of blind spots. 
This can be rectified by adding another 1 or 2 sensors, as this will allow for a slight overlap, meaning there is a much higher chance that all the relevant information will be captured.

## Getting Started

### Dependencies

* The arduino IDE is recommended for use to program the vechile
as it will contain the packages that you will
need to install to programme the vehicle.

* Before installing the program you will need
to have Mbed Pico OS Package installed 
in the arduino IDE.

* The OS version needs to be a Windows 10 and above


### Installing

The program can be downloaded from the gitlab
repository.


## Version History

* 0.2
    * Various bug fixes and optimizations
    * Progression and commited changes have been 
     made.
* 0.1
    * Initial Release

