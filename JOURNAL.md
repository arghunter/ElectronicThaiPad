---
title: "Electronic Thai Pad"
author: "Armaan Gomes"
description: "A Muay Thai Pad that uses a set of sensors to detect and respond to the strength of the hits."
created_at: "2025-06-9"
---


# June 9th
## Planning: 
- Needs to register hits
    - First Idea: IMU - Already have some Adafruit nrf 52840 sense boards (https://learn.adafruit.com/adafruit-feather-sense/overview) that would be great
    - Other Ideas:
        - Piezo sensors -  plan to hook up 4/5 to the ADCs of the nrf board for more detailed pressure/strike detection - Note: might need some voltage protection
        - FSR (Force Sensistive Resistors - A friend used these in one of their projects, but reportedly they aren't very precise, so probably won't use them.
     
- Signalling
    - LED strip around pad, neopixels embedded within pad below the fabric surface,
    - Can use bluetooth for web interface
    - First prototype will probably use serial while initial testing
 - Power
     - The nrf sense board already have a battery hookup and charger for lipo batteries
  
- Probably won't need a PCB just because the nrf sense boards already work so well.

## Programming:
- Found boards, updated bootloader
- Tried out the adafruit sensor demo
    - Took way to long to get the correct libaries installed
    -  ![image](https://github.com/user-attachments/assets/e89f43f3-7ec7-4315-a7c9-76b6738b8f1b)
    - Need to note that the acceleration also includes gravity when stationary so I may need to offset that later
-  After that, tired out neopixel demo, needed to find correct neopixel configuration to use the onboard pin
-  Combined the two to make a system that reflects both the direction and magnitude of the acceleration on the IMu built into the board
    - Forgot to accout for negatives, which confused me for a bit
    - Squaring the values caused it to become too sensitive and also flashbang me,
    - Settled on less sensitive brightness and color control, with offsets to account for stationary moments.
        - Stationary:
            - Dim and single color
            - ![image](https://github.com/user-attachments/assets/ef113a87-26f8-4cf1-a2cf-c42205d09bd2)
        - Accelerating:
            - Much brighter and between primary colors
            -   ![image](https://github.com/user-attachments/assets/3421a346-83bc-471d-8f4f-03a862300da3)

## Pad Acquisition:
- I talked to my taekwondo instructor and he gave me 4 old pads to experiment with
    - ![image](https://github.com/user-attachments/assets/663e797c-c21d-4c95-8435-cf039c794f55)
## Initial Testing
- Shoved the sense board (feather) into the pad
    - Kinda messy for a first test but if it work it works. Note will need padding to protect board from impact
    - ![image](https://github.com/user-attachments/assets/e4b23e65-0b41-421a-9ed2-6275a5897912)
- Did a tad more coding, intially to use the serial plotter, but that sucks so I got a serial decoder in python and am using that for testing
- It works - But now I appear to be maxing out the sensor:
    - Despite hitting with different power, the accel always seems to be suspiciously similar 
    -  ![image](https://github.com/user-attachments/assets/b2a567f2-5a4f-44a5-b573-5c6a06c486ff)
    -  Read the data sheet and it looks like the imu is set to +-4G of acceleration so I need to find a way around that.
    -  Ok I found a way to increase the accel range to 16g, which is the max. SAadly, I'm still maxing it on some punches, maybe i should try some padding
        - ![image](https://github.com/user-attachments/assets/0a36be53-1bfc-4820-9df9-e702e593c572)   
- Padding in front of the sensor did not work, I think i need some sort of springy substance both infront and behind the sensor to act as mechanical dampers.

## Cadding
- I made a rough case that has a space for a sliding platform with springs to dampen impact.
- However, i am currently failing at both making a screw and making a spring I am using the sweep tool wrong somehow and will figure it out later
- ![image](https://github.com/user-attachments/assets/8c1b04f7-b054-4612-bb5c-517e8673b0cf)




1h planning (probably a little more than this)+1h coding + 0.5h Pad Acquisition+ 2h initial testing + 1 h CADding


**Time Spent: 5.5h**

# June 10th
## Cad Pain
- I really need to learn CAD for real.
- I got a spring set up in possible the most awful way posible
- Then for somethin reason I thought I could print this in 1 piece without supports
    - ![image](https://github.com/user-attachments/assets/47203654-fa56-4be8-b6a2-2958be35d38e)
 - I also failed at screws again so I settled for dowels
 - I am also suspecting that I will need a high-G IMU like https://blog.st.com/lsm6dsv320x/
     - Its also smd so I have no shot of soldering that myself, so I'll probably need the expansion board
- Slice and printed for testing
    - ![image](https://github.com/user-attachments/assets/5609cf54-d4c5-41e2-8742-4c0263d375a6)

1h Cadding + 0.5h Research/Parts Search
   
**Time Spent: 1.5h**

# June 12th
## Assembly
- Not too deep, everything generally fits. The dowels didn't print very well but thats fine.
  - ![image](https://github.com/user-attachments/assets/aa0567c6-5d4b-4e8a-aceb-41c003317913)
  - ![image](https://github.com/user-attachments/assets/d34ace5f-b2f9-4f2f-a44c-7c961731c9a0)
  
## Wiring Diagram
-  Datasheet for imu: https://www.st.com/resource/ja/datasheet/lsm6dsv320x.pdf
-  Started work

**Time Spent: 0.5h**

# June 20th
## Wiring Diagram
- Made the wiring diagram, looked through datasheets and connected everything correctly
- Plan to directly solder to microcontroller due to the large distance from the micrcontroller to the peripherals
    -  May use a perf board if the wiring becomes too hairy.
 
## Case
- Minor tweaks, added stl files to repo, plan to print in TPU

**Time Spent: 1h**
  
  

