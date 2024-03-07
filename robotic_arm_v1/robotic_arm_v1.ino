#include <Servo.h>

Servo myservo0;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;
Servo myservo3;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = A3;  // the number of the pushbutton pin
const int claw = 8;      // the number of the electromagnet pin
const int elbowpot0 = A0;  //base mount motor analog pin used to connect the potentiometer
const int elbowpot1 = A1; //pan motor 
const int elbowpot2 = A2; 
int buttonState = 0;  // variable for reading the pushbutton status
bool magnet_state = false; // 
int elbowval0;             // variable to read the value from the analog pin
int elbowval1;
int elbowval2;

// variables will change:
//int buttonState = 0; variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(claw, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // settings for servo connections
  myservo0.attach(2);  // attaches the servo on pin 5 to the servo object for the grove
  myservo1.attach(4); //2nd
  myservo2.attach(6); 
  digitalWrite(claw, magnet_state);
}


void loop() {
  elbowval0 = analogRead(elbowpot0);        // reads the value of the potentiometer (value between 0 and 1023)
  elbowval0 = map(elbowval0, 0, 1023, 0, 200);  // scale it for use with the servo (value between 0 and 180)
  myservo0.write(elbowval0);           // sets the servo position according to the scaled value
  elbowval1 = analogRead(elbowpot1);        // reads the value of the potentiometer (value between 0 and 1023)
  elbowval1 = map(elbowval1, 0, 1023, 0, 180);  // scale it for use with the servo (value between 0 and 180)
  myservo1.write(elbowval1);           // sets the servo position according to the scaled value
  elbowval2 = analogRead(elbowpot2);        // reads the value of the potentiometer (value between 0 and 1023)
  elbowval2 = map(elbowval2, 0, 1023, 0, 120);  // scale it for use with the servo (value between 0 and 180)
  myservo2.write(elbowval2);           // sets the servo position according to the scaled value
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) { //if button is pressed
    digitalWrite(claw, HIGH); //Turn claw on
  }
  else {
    digitalWrite(claw, 
  }
  delay(50);                           // waits for the servo to get there
}

/* This is Aurora's changes */