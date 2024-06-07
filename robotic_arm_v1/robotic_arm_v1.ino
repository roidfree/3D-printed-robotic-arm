#include <Servo.h> // ensure you have the proper libraries installed within Arduino folders

Servo myservo0;  // create servo object to control it
Servo myservo1;
Servo myservo2;
Servo myservo3;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 3;  // the number of the pushbutton pin
const int claw = A3;      // the number of the electromagnet pin
const int elbowpot0 = A0;  //base mount motor analog pin used to connect the potentiometer
const int elbowpot1 = A1; //pan motor 
const int elbowpot2 = A2; 
bool buttonState = 0;  // variable for reading the pushbutton status
bool magnet_state = 0; // 
int elbowval0;             // variable to read the value from the analog pin
int elbowval1;
int elbowval2; // variables will change:
long nowmillis = 0;
long lastmillis = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(claw, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // settings for servo connections
  myservo0.attach(2);  // attaches the servo on pin 5 to the servo object for the grove
  myservo1.attach(4); //2nd
  myservo2.attach(6); 
  myservo3.attach(7);
  digitalWrite(claw, magnet_state);
}


void loop() {
  elbowval0 = analogRead(elbowpot0);        // reads the value of the potentiometer (value between 0 and 1023)
  elbowval0 = map(elbowval0, 0, 1023, 60, 170);  // scale it for use with the servo (value between 0 and 180)
  //elbowval0 = map(elbowval0, 0, 1023, 0, 200);  // scale it for use with the servo (value between 0 and 180)
  myservo0.write(elbowval0);           // sets the servo position according to the scaled value
  elbowval1 = analogRead(elbowpot1);        
  elbowval1 = map(elbowval1, 0, 1023, 0, 80);  
  myservo1.write(elbowval1);           
  elbowval1 = map(elbowval1, 0, 80, 80, 0);  
  myservo2.write(elbowval1);           
  elbowval2 = analogRead(elbowpot2);        
  elbowval2 = map(elbowval2, 0, 1023, 0, 120);  
  myservo3.write(elbowval2);       

  //-----------------------------------    
  buttonState = digitalRead(buttonPin);
  // check if the push0button is pressed. If it is, the buttonState is HIGH:
  //buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    nowmillis = millis();
    if(nowmillis >= lastmillis + 500) {
  if (buttonState == HIGH) { //if button is pressed
    digitalWrite(claw, HIGH); //Turn claw on
  }
  else {
    digitalWrite(claw, magnet_state);
  }
  delay(50);                           // waits for the servo to get there
}
   //-----------------------------------
    
    // turn LED on:
    if (magnet_state == 1){magnet_state = 0;}
    else if (magnet_state ==0){magnet_state =1;}
    //magnet_state = 1;
    //magnet_state = buttonState;
        digitalWrite(claw, magnet_state);
        lastmillis = nowmillis;
    }

          }