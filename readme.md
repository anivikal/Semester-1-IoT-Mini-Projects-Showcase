# Semester 1 IoT Mini-Projects Showcase 🛠️

> **A Throwback to My Engineering Roots** 🚀
> *Before diving into predictive AI models and complex architectures, I was learning the foundations of logic, hardware integration, and physical computing. This repository holds my very first 1st-semester practical projects built with the Arduino Uno.*

## 📑 Table of Contents
1. [Smart Water Dispenser](#-1-smart-water-dispenser)
2. [4-Way Smart Traffic Light](#-2-4-way-smart-traffic-light)
3. [Smart Smoke Alarm & Automated Sprinkler](#-3-smart-smoke-alarm--automated-sprinkler)
4. [Getting Started](#-getting-started)

---

## 💧 1. Smart Water Dispenser
A basic, automated IoT water dispenser. This system uses an infrared (IR) sensor to detect the presence of a glass and automatically triggers a 5V mini water pump to pour water without any manual button presses.

**Tech Stack & Components:**
* **Microcontroller:** Arduino Uno (C++)
* **Hardware:** 1x IR Object Tracking Sensor, 1x 5V Relay Module, 1x 5V DC Mini Water Pump

**How It Works:**

1. The IR sensor constantly emits and monitors for infrared reflections. 
2. When a glass is placed in front of it, the signal bounces back, sending a `LOW` signal to the Arduino.
3. The Arduino triggers the relay module, closing the power circuit and turning on the 5V water pump to dispense water.

---

## 🚦 2. 4-Way Smart Traffic Light
A fully functional prototype of a 4-way intersection (Choraha) traffic light system. This project manages the complex state-machine logic required to safely route traffic sequentially across four different lanes.

**Tech Stack & Components:**
* **Microcontroller:** Arduino Uno (C++)
* **Hardware:** 12x LEDs (4 Red, 4 Yellow, 4 Green), 12x 220Ω Resistors

**How It Works:**

1. The system starts with all 4 lanes on **RED** to establish a safe baseline.
2. The Arduino cycles through each lane one by one (North, East, South, West).
3. For the active lane, Red turns off and Green turns on for 5 seconds. It transitions to Yellow for 2 seconds (SLOW DOWN), before returning to Red (STOP). 
4. The system seamlessly passes the "GO" state to the next lane in the sequence indefinitely.

---

## 🔥 3. Smart Smoke Alarm & Automated Sprinkler
An active safety mechatronics system that not only detects hazardous conditions but physically reacts to them. If smoke surpasses a safe threshold, it sounds an alarm, activates a water pump, and uses a servo motor to sweep the water nozzle back and forth—simulating an automated fire sprinkler system.

**Tech Stack & Components:**
* **Microcontroller:** Arduino Uno (C++)
* **Hardware:** 1x MQ-2 Gas/Smoke Sensor, 1x Active Buzzer, 1x 5V Relay Module & Pump, 1x SG90 Micro Servo Motor

**How It Works:**

1. The MQ-2 sensor continually reads the concentration of combustible gases/smoke in the air.
2. The Arduino compares the incoming analog value against a hardcoded safety threshold.
3. If breached, the Arduino triggers the buzzer (alarm) and the relay module (turning on the water pump).
4. Simultaneously, the Servo motor sweeps the attached water nozzle back and forth between 45° and 135° to maximize the suppression area until the smoke clears.

---

## 🚀 Getting Started

To run any of these projects on your local machine:

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/anivikal/Semester-1-IoT-Mini-Projects-Showcase.git](https://github.com/anivikal/Semester-1-IoT-Mini-Projects-Showcase.git)

2. **Setup the Hardware:** Wire the components on your breadboard according to the pin configurations listed at the top of each `.ino` file. *(Tip: Always double-check your Ground (GND) and 5V connections before powering on!)*

3. **Upload the Code:** Open the desired project file in the Arduino IDE. Connect your Arduino Uno to your PC via USB, go to `Tools > Port` to select your active COM port, and click the **Upload** button.

4. **Monitor System Status:** Once uploaded, open the Serial Monitor (magnifying glass icon in the top right, or `Ctrl + Shift + M`). Set the Baud Rate to **9600** in the bottom right corner of the window to view real-time sensor logs, smoke levels, and active states.