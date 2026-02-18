// Smart Traffic Light System - 4-Way Intersection 
// Components: 4 sets of Red, Yellow, and Green LEDs (12 LEDs total)

// --- PIN DEFINITIONS ---
// Lane 1 (North)
const int green1 = 2, yellow1 = 3, red1 = 4;
// Lane 2 (East)
const int green2 = 5, yellow2 = 6, red2 = 7;
// Lane 3 (South)
const int green3 = 8, yellow3 = 9, red3 = 10;
// Lane 4 (West)
const int green4 = 11, yellow4 = 12, red4 = 13;

void setup() {
  // Set all 12 pins as OUTPUT using a quick loop
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  // Initial State: Turn all RED lights ON
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, HIGH);
}

void loop() {
  // 🟢 LANE 1 GOES 🟢
  digitalWrite(red1, LOW);       // Lane 1 Red OFF
  digitalWrite(green1, HIGH);    // Lane 1 Green ON
  delay(5000);                   // Green for 5 seconds
  digitalWrite(green1, LOW);     // Lane 1 Green OFF
  digitalWrite(yellow1, HIGH);   // Lane 1 Yellow ON
  delay(2000);                   // Yellow for 2 seconds
  digitalWrite(yellow1, LOW);    // Lane 1 Yellow OFF
  digitalWrite(red1, HIGH);      // Lane 1 Red ON (Back to stop)

  // 🟢 LANE 2 GOES 🟢
  digitalWrite(red2, LOW);       
  digitalWrite(green2, HIGH);    
  delay(5000);                   
  digitalWrite(green2, LOW);     
  digitalWrite(yellow2, HIGH);   
  delay(2000);                   
  digitalWrite(yellow2, LOW);    
  digitalWrite(red2, HIGH);      

  // 🟢 LANE 3 GOES 🟢
  digitalWrite(red3, LOW);       
  digitalWrite(green3, HIGH);    
  delay(5000);                   
  digitalWrite(green3, LOW);     
  digitalWrite(yellow3, HIGH);   
  delay(2000);                   
  digitalWrite(yellow3, LOW);    
  digitalWrite(red3, HIGH);      

  // 🟢 LANE 4 GOES 🟢
  digitalWrite(red4, LOW);       
  digitalWrite(green4, HIGH);    
  delay(5000);                   
  digitalWrite(green4, LOW);     
  digitalWrite(yellow4, HIGH);   
  delay(2000);                   
  digitalWrite(yellow4, LOW);    
  digitalWrite(red4, HIGH);      
}