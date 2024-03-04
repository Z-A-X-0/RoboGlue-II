# RoboGlue-II

## Project Description

"Robotics for Cultural Preservation (RoboGlue II)", is dedicated to the planning and development of a gripper system for picking up paper fragments with a manipulator. This project includes both theoretical development and the creation of a prototype, which will be evaluated using a collaborative robot (cobot), such as the UR10. The proposed system is based on vacuum technology to ensure gentle yet stable handling and movement of the fragments. A thorough theoretical analysis of the current state of technology precedes the development efforts.

## How to Use

The included code utilizes an Arduino Mega 2560 Microcontroller to control a vacuum-based gripping system, leveraging components such as the VL53L0X Time-of-Flight (ToF) Sensor for distance measurement, a Festo VN-14-H-T4-PQ2-VQ3-RO2 Vacuum Generator for creating a vacuum, and an Electric Pneumatic Solenoid Valve 3V210-08 24VDC for controlling the airflow. A 5V Relay KF-301 is used to manage power distribution, and a Siemens 6AG1333 Series PLC Power Supply provides the necessary power.

### Code Description

The code starts by including necessary libraries and initializing variables for the VL53L0X sensor and the pump control pin. The setup function initializes serial communication, configures the VL53L0X sensor, and sets up the pump control pin.

The main loop of the code continuously reads the distance from the VL53L0X sensor. If the distance is within a specified range (less than or equal to 30mm), it toggles the state of the pump to either turn on the vacuum (if it's off) or turn it off (if it's on), depending on the current state. This logic ensures that the gripper system can react to the proximity of paper fragments for picking them up or releasing them. The pump remains off if the distance is greater than 60mm, readying the system for the next operation.

This control scheme allows for precise manipulation of paper fragments, vital for the project's goal of preserving cultural documents.

### Components Used

- **Power Supply:** Siemens 6AG1333 Series PLC
- **Microcontroller:** Arduino Mega 2560
- **Vacuum Generator:** Festo VN-14-H-T4-PQ2-VQ3-RO2
- **Solenoid Valve:** Electric Pneumatic Solenoid Valve 3V210-08 24VDC
- **Relay:** 5V KF-301
- **Distance Sensor:** VL53L0X Time-of-Flight (ToF) Sensor

### Usage Instructions

1. Ensure all hardware components are correctly connected as per the project schematics.
2. Upload the provided code to the Arduino Mega 2560.
3. Power on the system and bring a paper fragment within 30mm of the VL53L0X sensor to trigger the vacuum grip. Moving the fragment away beyond 60mm releases the grip.
