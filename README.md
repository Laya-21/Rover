
# ROVER

Welcome to the **Multi-Terrain Rover** repository!  
This project is developed by the **Robot Study Circle, COEP**.  
It is a robust all-terrain rover designed for rough surfaces like agricultural fields, capable of being controlled via serial console and integrated with basic image processing for smart navigation.




## Roadmap

- Custom PCB Design
-  Console-Based Manual Control
-  Image Processing for Terrain
-  PCB Assembly and Testing
-  Field Testing and Tuning



##  Hardware Components

| Component              | Description                           |
|------------------------|---------------------------------------|
| Microcontroller        | ESP32 (Speed Studio Board)            |
| Motor Driver           | BTS079 H-Bridge                       |
| Motors                 | Johnson Geared DC Motors              |
| Power Source           | 12V LiPo Battery                      |
| PCB                    | Custom-designed PCB for integration   |

---


##  PCB Design

The **Printed Circuit Board (PCB)** is designed to efficiently route power and signals between the ESP32, motor drivers, and other peripherals.

###  Tools Used

- **Design Software**: Altium Designer
- **Board Material**: FR4 Epoxy
- **Layers**: 1-layer (for better power distribution and compact layout)

### Design Highlights

1. **Schematic Design**  
   - Includes connections for: ESP32, BTS079 motor driver, power regulators, and protection circuitry  
   - Designed for stability, expandability, and ease of debugging

   ![Schematic](https://i.postimg.cc/jqfp0c6K/img-1.jpg)


2. **PCB Layout**  
   - Ground and Power planes for low-noise operation  
   - Wide traces for motor driver outputs to handle high current  
   - Compact routing to reduce wire clutter in final assembly

![Schematic](https://i.imgur.com/otm16gV.jpeg)
![Schematic](https://i.imgur.com/q2VZSD2.jpeg)


## Image Processing Modules (OpenCV)
The image processing for this rover is divided into two specialized modules:

1. Terrain Detection
Detects and classifies various terrains (e.g., soil, gravel, grass) using image filtering and color segmentation.

Helps in deciding optimal paths or switching motor control strategies.


| ![Rough Terrain](https://i.imgur.com/DjetkdB.png) | ![Smooth Terrain](https://i.imgur.com/lSd68b0.png) |
|:--:|:--:|
| *Rough Terrain* | *Smooth Terrain* |


2. Agricultural Analysis
Processes the field view to identify vegetation zones or detect crop health.

Useful for smart farming applications like irrigation or crop monitoring.

| ![Rough Terrain](https://i.imgur.com/Lo5TVNy.png) | ![Smooth Terrain](https://i.imgur.com/HFziLas.png) |
|:--:|:--:|
| *Green Feild* | *Plants* |


## DEMO
![Project Demo](https://s2.ezgif.com/tmp/ezgif-27ae4731bf59bf.gif)

