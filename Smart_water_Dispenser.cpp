// Smart Water Dispenser
// Components: IR Sensor, 5V Relay Module, Mini Water Pump

const int irSensorPin = 2; // IR sensor digital pin
const int relayPin = 3;    // Relay module pin controlling the pump

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  // Ensure pump is off initially (Assuming active-low relay)
  digitalWrite(relayPin, HIGH); 
  Serial.begin(9600);
  Serial.println("Smart Water Dispenser Initialized.");
}

void loop() {
  int sensorStatus = digitalRead(irSensorPin);

  // IR sensors usually output LOW when an object is detected
  if (sensorStatus == LOW) {
    Serial.println("Glass detected. Dispensing water...");
    digitalWrite(relayPin, LOW); // Turn ON pump
    delay(1000); // Keep pouring for a second to avoid rapid toggling
  } else {
    digitalWrite(relayPin, HIGH); // Turn OFF pump
  }
  delay(100); // Small delay for stability
}