// Smart Smoke Alarm & Fire Fighter (With Sweeping Sprinkler)
// Components: MQ-2 Sensor, Active Buzzer, Relay (Pump), and Servo Motor

#include <Servo.h>

const int smokeSensorPin = A0; // MQ-2 Analog output
const int buzzerPin = 8;       // Buzzer pin
const int pumpRelayPin = 9;    // Relay for fire-fighting pump
const int servoPin = 10;       // Signal pin for the Sprinkler Servo
const int threshold = 400;     // Smoke detection threshold (calibrate as needed)

Servo sprinklerServo;          // Create a servo object to control the sprinkler

void setup() {
  pinMode(smokeSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pumpRelayPin, OUTPUT);
  
  digitalWrite(pumpRelayPin, HIGH); // Keep pump OFF initially (Active-LOW relay)
  
  sprinklerServo.attach(servoPin);  // Attach the servo on pin 10
  sprinklerServo.write(90);         // Set sprinkler to neutral (center) position
  
  Serial.begin(9600);
  Serial.println("System Initialized. Scanning for smoke...");
}

void loop() {
  int smokeLevel = analogRead(smokeSensorPin);
  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  if (smokeLevel > threshold) {
    // 🔥 Fire/Smoke detected!
    digitalWrite(buzzerPin, HIGH);     // Sound the alarm
    digitalWrite(pumpRelayPin, LOW);   // Activate water pump
    Serial.println("ALERT: Fire detected! Activating pump & sprinkler system.");

    // 💦 Sprinkler Sweeping Action
    // Sweeps the nozzle from 45 degrees to 135 degrees to cover the fire area
    for (int angle = 45; angle <= 135; angle += 5) {
      sprinklerServo.write(angle);
      delay(30); // Speed of the sweep
    }
    for (int angle = 135; angle >= 45; angle -= 5) {
      sprinklerServo.write(angle);
      delay(30);
    }
    
  } else {
    // ✅ Normal conditions
    digitalWrite(buzzerPin, LOW);      // Turn off alarm
    digitalWrite(pumpRelayPin, HIGH);  // Turn off pump
    sprinklerServo.write(90);          // Reset sprinkler to center position
  }
  
  delay(100); // Short delay before the next sensor reading
}