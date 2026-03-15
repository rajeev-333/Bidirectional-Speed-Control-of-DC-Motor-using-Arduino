/*
------------------------------------------------------------
 Project: Bidirectional DC Motor Control using Arduino
 Description:
 Controls the speed and direction of a DC motor using
 Arduino Uno, L293D motor driver, two push buttons, and
 a potentiometer.

 - Potentiometer controls motor speed
 - Button 1 controls forward rotation
 - Button 2 controls reverse rotation
 - PWM signal regulates motor speed
------------------------------------------------------------
*/


/* ---------------- Pin Definitions ---------------- */

// Motor direction control pins (connected to L293D inputs)
const int forwardPin  = 8;     // Controls forward rotation
const int backwardPin = 12;    // Controls reverse rotation

// Motor speed control (PWM pin connected to L293D Enable pin)
const int speedPin = 11;

// Push button pins
const int button1Pin = 2;      // Forward button
const int button2Pin = 3;      // Reverse button

// Potentiometer analog input pin
const int potPin = A0;


/* ---------------- Variables ---------------- */

int button1State;   // Stores state of forward button
int button2State;   // Stores state of reverse button

int potValue;       // Stores potentiometer analog value (0–1023)
int motorSpeed;     // Stores mapped PWM value (0–255)


/* ---------------- Setup Function ---------------- */

void setup()
{
  // Configure motor direction pins as outputs
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);

  // Configure push buttons as inputs with internal pull-up resistors
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}


/* ---------------- Main Loop ---------------- */

void loop()
{
  
  // Read push button states
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // Read potentiometer value (0–1023)
  potValue = analogRead(potPin);

  // Convert potentiometer value to PWM range (0–255)
  motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Send PWM signal to motor driver enable pin
  analogWrite(speedPin, motorSpeed);


  /* -------- Motor Direction Control -------- */

  // If Button 1 is pressed → rotate motor forward
  if (button1State == LOW)
  {
    digitalWrite(forwardPin, HIGH);
  }
  else
  {
    digitalWrite(forwardPin, LOW);
  }

  // If Button 2 is pressed → rotate motor in reverse
  if (button2State == LOW)
  {
    digitalWrite(backwardPin, HIGH);
  }
  else
  {
    digitalWrite(backwardPin, LOW);
  }

}