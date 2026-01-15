/*
TRAXXAS PICO/MBED BRIDGE SERVO TEST
Control motor and steering using onboard variable resistor.
At startup, servos are set to mid point for 5 seconds (LED3 is on during)
JW CSEE 01/09/23
*/
#include <Servo.h>
#define TRIG_PIN_RIGHT 7
#define ECHO_PIN_RIGHT 6
#define TRIG_PIN 15     //GP9
#define ECHO_PIN 14      //GP8
#define PULSE_MAX 8000  //pulseIn timeout
#define LED_PIN 25      //GP25
#define Trig_PIN_left 13
#define ECHO_PIN_Left 12

#define Trig_PIN_Backward 9
#define ECHO_PIN_Backward 8

#define Trig_PIN_BackwardLeft 5
#define ECHO_PIN_BackwardLeft 4

#define Trig_PIN_BackwardRIGHT 1
#define ECHO_PIN_BackwardRIGHT 0


Servo esc;
Servo steer;
int potpin = 28;
int val;
float FRONT_distance, RIGHT_distance,LEFT_distance,Backward_distance ,BackwardRIGHT_distance,BackwardLeft_distance;


void setup() {
// MOTOR SET UP
// pin set up
pinMode(26, OUTPUT);
digitalWrite(26, HIGH);
esc.attach(22); //link to GPIO pin 22
steer.attach(21); // attaching servo variable to pin 21
// initialise
esc.write(90); // 0 = backwards 90 = stop (neutral) 180 = full forward
steer.write(90); // 0 = full LEFT 90 = straight 180 = full RIGHT
delay(5000); // wait 5 seconds
digitalWrite(26, LOW);
//FRONT SENSOR
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(LED_PIN, OUTPUT);
digitalWrite(TRIG_PIN, LOW);
digitalWrite(LED_PIN, HIGH);
Serial.begin(115200);
//RIGHT SENSOR
pinMode(TRIG_PIN_RIGHT, OUTPUT);
pinMode(ECHO_PIN_RIGHT, INPUT);
//pinMode(LED_PIN, OUTPUT);
digitalWrite(TRIG_PIN_RIGHT, LOW);
// digitalWrite(LED_PIN, HIGH);
//left sensor
pinMode(Trig_PIN_left, OUTPUT);
pinMode( ECHO_PIN_Left, INPUT);
//pinMode(LED_PIN, OUTPUT);
digitalWrite(Trig_PIN_left, LOW);
digitalWrite(LED_PIN, HIGH);
//backward sensor
pinMode(Trig_PIN_Backward, OUTPUT);
pinMode( ECHO_PIN_Backward, INPUT);
//pinMode(LED_PIN, OUTPUT);
digitalWrite(Trig_PIN_Backward, LOW);
digitalWrite(LED_PIN, HIGH);

//backright sensor
pinMode(Trig_PIN_BackwardRIGHT, OUTPUT);
pinMode( ECHO_PIN_BackwardRIGHT, INPUT);
//pinMode(LED_PIN, OUTPUT);
digitalWrite(Trig_PIN_BackwardRIGHT, LOW);
digitalWrite(LED_PIN, HIGH);

//backleft sensor
pinMode(Trig_PIN_BackwardLeft, OUTPUT);
pinMode( ECHO_PIN_BackwardLeft, INPUT);
//pinMode(LED_PIN, OUTPUT);
digitalWrite(Trig_PIN_BackwardLeft, LOW);
digitalWrite(LED_PIN, HIGH);

}
void loop() {
val = analogRead(potpin);
val = map(val, 0, 1023, 0, 180); //maps a 10-bit value (0 - 1023) to 8-bit (0 - 255) value and controls PWM on pin 9 output
// 0 - 180 because 180 is full power for the motor and 0 is non
delay(15);

FRONT_distance =Distanceultra(TRIG_PIN,ECHO_PIN);
RIGHT_distance = Distanceultra(TRIG_PIN_RIGHT,ECHO_PIN_RIGHT);
LEFT_distance = Distanceultra(Trig_PIN_left,ECHO_PIN_Left);
Backward_distance = Distanceultra(Trig_PIN_Backward,ECHO_PIN_Backward);
BackwardRIGHT_distance=Distanceultra(Trig_PIN_BackwardRIGHT,ECHO_PIN_BackwardRIGHT);
BackwardLeft_distance=Distanceultra(Trig_PIN_BackwardLeft,ECHO_PIN_BackwardLeft);
if(FRONT_distance == 0){
  FRONT_distance=150;
}
if(RIGHT_distance == 0){
  RIGHT_distance=150;
}
if(LEFT_distance == 0){
  LEFT_distance=150;
}
if(Backward_distance == 0){
  Backward_distance=150;
}
if(BackwardLeft_distance == 0){
  BackwardLeft_distance=150;
}
if(BackwardRIGHT_distance == 0){
  BackwardRIGHT_distance=150;
}
Serial.print("front:");
Serial.println(FRONT_distance);
 Serial.print("BACK: ");
Serial.println(Backward_distance);
Serial.println("Right:");
Serial.println(RIGHT_distance);
Serial.print("Left:");
Serial.println(LEFT_distance);
Serial.print("backright:");
Serial.println(BackwardRIGHT_distance);
Serial.print("backLeft:");
Serial.println(BackwardLeft_distance);
Serial.println("");

//toggle LED "Heartbeat"
digitalWrite(LED_PIN, !digitalRead(LED_PIN));
delay(100);
if(FRONT_distance < 20){
  esc.write(90);
  return;

}
if(FRONT_distance > 50){
  esc.write(90);
      delay(100);
  // Serial.println("forward is working");
    if(LEFT_distance < 30 ){
      
      steer.write(160);
      delay(100);
      esc.write(160);
      //delay(200);

    }else if (RIGHT_distance < 30){
      
      steer.write(0);
      delay(100);
      esc.write(150);
     // delay(200);
    }
    else{
      steer.write(90); 
      esc.write(160); 
    }
}
else if(FRONT_distance < 45 ){

  esc.write(90);
  delay(100);
  

  if(((LEFT_distance > 10 && LEFT_distance < 50) || (RIGHT_distance > 10 && RIGHT_distance < 50)) && Backward_distance > 30 && (BackwardRIGHT_distance > 30 || BackwardLeft_distance > 30) ){
    
    if(LEFT_distance > RIGHT_distance && BackwardRIGHT_distance > 5){
          steer.write(180);
          delay(250);
        }
    else if (LEFT_distance < RIGHT_distance && BackwardLeft_distance > 5){
          steer.write(0);
          delay(250);
        }
    else{
          esc.write(90);
          delay(800000);

        }
    esc.write(60);
    delay(1000);
    esc.write(90);
    delay(50);


      
      
 
    if(LEFT_distance > RIGHT_distance){
      steer.write(0);
      delay(100);
    }else if(LEFT_distance < RIGHT_distance){
      // Serial.println("Right");
      steer.write(180);
      delay(100);
     
      
    }
    esc.write(150);
   
}else if(LEFT_distance > 50 || RIGHT_distance > 50){
  if(LEFT_distance > RIGHT_distance){
      
      steer.write(0);
      esc.write(130);
      delay(150);
      // Serial.println("Left");
     

    }
    else if(LEFT_distance < RIGHT_distance){
      // Serial.println("Right");
      steer.write(180);
      esc.write(130);
      delay(150);
      
    }
     else{
      steer.write(90);
      esc.write(90);
    }

 }}
 

}float Distanceultra(int trigpin,int ecopin){
  digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);  
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
float duration = pulseIn(ecopin, HIGH, PULSE_MAX);
return (duration * .0343) / 2.0;
}