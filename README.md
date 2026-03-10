# Traxxas Fire Detection Autonomous Vehicle
---

Our final aim for this project post MVP is to implement a fire detection mechanism to our autonomous vehicle. We purposely designed the fire detection to be very useful for both firefighters and 'hotshot' teams in forests that liable to catching fire, for instance California. This product will be used to alert nearby individuals in a harzadous area.


## Project Description

For this project, we have chosen to implement a robust fire detection system for the autonomous vehicle. I will be addressing the roles that each device plays in the design of this product. The main features of the car include: ESP32S3-Dev Module, ESP32-CAM, LED, Temperature Sensor and an LCD Display and lastly a buzzer. The ESP32S3-Dev Module is responsible for setting a personal area network for devices such as the ESP32-CAM and the Raspberry pi to receive data from the ESP32S3-Dev Module. 

The ESP32-CAM inititates the whole communication process, it is responsible for detecting an image of a fire. Once it has confirmed that there is truly a fire, it will send a 1 to the ESP32S3-Module, then the 1 will then be sent to the PICO which will command the car to STOP.

The Ky016-LED is also another feature that we implemented. The LED works hand in hand with the UART receiver protocol which is the PICO.The LED waits for the PICO to send data, when no fire is detected, the LED's colour is BLUE ,whereas when a fire is being detected the LED will indicate RED.

In addition to this, we also have a tempeature sensor and an LCD display. These two devices work hand in hand. The temperature sensor that we are using is called (DHT11). It detects the temperature and the relative humidity(RH) of the fire, however because we are not using a real fire due to safety hazards, we decided to randomise the temperature values in the ranges between 600 - 800℃. Once the pico receives the fire confirmation, the LCD display the temperature and humidity of the fire.

Lastly, we have the buzzer. We implemented the buzzer because we wanted to make the product to be more interactive with the real world. The buzzer works just like a fire alarm. Its only job is to make an emergerncy beeping sound when a fire is detected.

## Outlining The System Architecture
In this section, i will be showing you a block diagram on how on the software and hardware architecture.

---

### Software Architecture

The block diagram below illustrates the intricate design of the fire detection mechanism. It highlights the how the software components actually work.

![Software Architecture](https://i.ibb.co/B2c5SnzD/Software-Architecture.png)


**1.ESP32-CAM:** Firstly, we have the ESP32-CAM which is responsible for providing live video footage for the area we are monitoring for fires.

**2.OpenCV:** OpenCV connects to the ESP32-CAM stream and reads the video frame by frame, it then converts the video into images for the AI model to process.

**3.YOLOv8 Model:** YOLOv8 is an object detection neural network.It looks at each frame from OpenCV, then it detects for fire.

**4.OpenVINO:** Converts the YOLO model into a format optimised for intel hardware. Makes the model run faster and more efficiently

**5.CPU runs inference:** inference means the AI analyses new images to make predictions. It runs the detection in real time

**6.Fire Detection Output:** The fire detection output will be the bounding box around fire, you will see the Label "Fire" and also the confidence score


### Hardware Architecture
The block diagram below shows all the hardware devices that were implemented in the
product design

![Hardware Architecture](https://i.ibb.co/qLknkWh4/Hardware_Architecture.png)



## Getting Started
---

### Dependencies
Prequisites include: Arduino IDE, Python 3.11 + & Command prompt

Libraries used in Python: Ultralytics, YOLOv8, OpenVino and OpenCV

Libraries used in Arduino: BluetoothSerial, DHT Sensor Library, LiquidCrystal I2C

### Installing
In this section, we will show you all the libraries/packages that you will need for the python program

Step 1. Create a virtual environment to work with
```
python -m venv venv
```
Step 2. Upgrade pip to the latest version, to avoid errors when installing modern packages
```
pip install --upgrade pip
```
Step 3. Install OpenCV and Ultralytics
```
pip install opencv-python ultralytics
```
Step 4. Install OpenVino
```
pip install openvino 
```

### Executing Program
I will show you below in the codeblock how to run the python program. The python program is where the

Step 1. Start by activating the virtual environment
```
C:\Users\nwaeh>venv\scripts\activate 
```
Step 2. Then we paste in the path where the python program is located 
```
(venv) C:\Users\nwaeh>python "C:\Users\nwaeh\OneDrive\Documents\Computer Systems Engineering - Year 2\
CE201-Team Project Challenge\AA-Main Code Files
\ESP32-CAM_Fire_Detection_Updated.py"
```
## Version History
---
* 0.4
    * Latest Version
    * Fully Fixed & Optimised Version
    * Runs smoothly without any bugs
* 0.3
    * Various bug fixes and optimizations
    * Fixed latency issues
    * Progression and commited changes have been 
     made. 

* 0.2
    * Spotted various bugs and found the best methods to fix them
    * Progression made and commited changes were made
* 0.1
    * Initial Release

## License
---
This project is licensed under the GNU AFFERO GENERAL PUBLIC LICENSE - See the LICENSE link for more details [LICENSE] https://rebrand.ly/7mlu0pj

## Acknowledgments
---
Arduino Libaries Acknowledgments
- DHT-v1.4.6 Sensor Library By Adafruit
- BluetoothSerial-v1.1.0 Library By Henry Abrahamsen
- LiquidCrystalI2C-v1.1.2 Library By Frank De Brabander

