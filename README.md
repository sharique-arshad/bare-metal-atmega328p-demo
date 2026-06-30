# Bare-Metal ATmega328P Development Board with OLED & MPU6050

> A custom standalone ATmega328P development board built on a perfboard to learn embedded systems, bare-metal AVR hardware design, sensor interfacing, and firmware development. The project communicates with an MPU6050 IMU over I²C, displays real-time data on an SSD1306 OLED, and was programmed using an Arduino Uno configured as an ISP programmer.

---

## Preview

### Final Perfboard Prototype

![Development Board](images/board.jpg)

*A custom-built standalone ATmega328P development board featuring an SSD1306 OLED, MPU6050 IMU, LED, buzzer, push buttons, and ISP programming header.*

---

### Programming using Arduino Uno as ISP

![Arduino ISP](images/Arduino_Isp.jpg)

*Uploading firmware to the standalone ATmega328P using an Arduino Uno configured as an ISP programmer during development.*

---

# Features

- Standalone ATmega328P (Bare-Metal AVR)
- External 16 MHz Crystal Oscillator
- SSD1306 128×64 OLED Display
- MPU6050 Accelerometer & Gyroscope
- Status LED
- Piezo Buzzer
- Push Button Input
- Arduino Uno ISP Programming
- Perfboard Hardware Prototype
- Real-time Tilt Detection
- I²C Communication

---

# Hardware Used

| Component | Description |
|-----------|-------------|
| ATmega328P-PU | Main Microcontroller |
| SSD1306 OLED | 128×64 I²C Display |
| MPU6050 | Accelerometer + Gyroscope |
| 16 MHz Crystal | System Clock |
| 22 pF Capacitors | Crystal Oscillator |
| Push Buttons | Reset / User Input |
| Piezo Buzzer | Alert Output |
| LED | Status Indicator |
| 10kΩ Resistor | Reset Pull-up |
| Perfboard | Hardware Prototyping |
| Arduino Uno | ISP Programmer |

---

# Software

- Arduino IDE
- Arduino AVR Core
- Adafruit SSD1306 Library
- Adafruit GFX Library
- Adafruit MPU6050 Library
- Adafruit Unified Sensor Library

---

# Programming Method

Unlike a standard Arduino Uno project, this hardware uses a **standalone ATmega328P**.

The firmware was uploaded using an **Arduino Uno configured as an ISP (In-System Programmer)**.

Development workflow:

```
Arduino IDE
      │
      ▼
Arduino Uno (ArduinoISP)
      │
      ▼
Standalone ATmega328P
```

This approach provides experience working directly with AVR microcontrollers without relying on a complete Arduino development board.

---

# Hardware Architecture

```
                 +----------------+
                 |   ATmega328P   |
                 +-------+--------+
                         |
      +------------------+------------------+
      |                  |                  |
      ▼                  ▼                  ▼
 SSD1306 OLED      MPU6050 IMU        Status LED
     (I²C)             (I²C)

      |
      ▼
 Piezo Buzzer

      |
      ▼
 Push Button

      |
      ▼
 Arduino ISP Header
```

---

# Firmware

The firmware demonstrates:

- Initializing the OLED display
- Reading acceleration values from the MPU6050
- Displaying sensor data on the OLED
- Detecting excessive tilt
- Activating LED and buzzer alerts
- Resetting alerts using a push button

---

# Repository Structure

```
ATmega328P-OLED-MPU6050
│
├── firmware
│   └── atmega328p_oled_mpu6050.ino
│
├── images
│   ├── board.jpg
│   └── arduino_isp.jpg
│
├── docs
│   └── hardware.md
│
├── README.md
└── LICENSE
```

---

# Learning Outcomes

This project helped me understand:

- Standalone AVR microcontroller design
- ATmega328P minimum system
- Crystal oscillator circuitry
- ISP programming
- I²C communication
- Sensor interfacing
- OLED graphics
- Embedded firmware development
- Hardware debugging
- Perfboard prototyping
- Soldering and circuit assembly

---

# Skills Demonstrated

- Embedded Systems
- AVR Microcontrollers
- Bare-Metal Hardware Design
- ATmega328P
- Arduino IDE
- Arduino as ISP
- I²C Protocol
- MPU6050 Interfacing
- SSD1306 OLED
- Hardware Debugging
- Embedded C / Arduino
- Electronics Prototyping

---

# Future Improvements

- Design a custom PCB using KiCad
- Add battery power management
- Integrate UART debugging
- Implement EEPROM configuration storage
- Add menu navigation on the OLED
- Expand sensor support

---

# Author

**Mohammad Sharique Arshad**

Electronics & Communication Engineering

Interested in:

- Embedded Systems
- PCB Design
- IoT
- Hardware Product Development
- AVR & ESP32 Development

---

## License

This project is licensed under the MIT License.
