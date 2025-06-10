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
    - Forgot to accoutn for negatives, which confused me for a bit
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
    -  Ok I found a way to increase the accel rang to 16g, which is the max. SAadly, I'm still maxing it on some punches, maybe i should try some padding
        - ![image](https://github.com/user-attachments/assets/0a36be53-1bfc-4820-9df9-e702e593c572)
  



1h planning (probably a little more than this)+1h coding + 0.5h Pad Acquisition+ 1.5h initial testing (so far)


**Time Spent: 4h**

