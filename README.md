# Electronic Thai Pad

A Thai pad that records and displays how hard you hit it with a strip of LEDs.

**What is a thai pad?**
- A thai pad is a handheld pad for kicking and punching
- However, it can be hard to guage how hard you are hitting to track your improvement
![image](https://github.com/user-attachments/assets/8ed7a2e0-8507-4925-b12a-c4d6ba41045c)
![image](https://github.com/user-attachments/assets/ea5d6d66-24eb-497e-b4f8-8ac19e8ba72e)

**What this electronic thai pad does**
- This project embedded an IMU (accelerometer) and a number of piezo sensors within a thai pad to detect the strengh of hits.
- It then uses an LED strip surrounding the pad to display visually the strength of hits
- Additionally, aim is very important, so the 5 piezo sensors, spread in a pentagon, can be used to highlight where on the pad your strike lands in order to help you center your following strikes

**Why I made this proejct**
As a fourth degree black belt, I value every source of feedback, but objective feedback can be difficult and expensive to acquire, so this is a cheap and low cost way to acquire objective feedback on my techniques.

## Pictures
### Full Project
- I would provide a 3d model, but it would just be an image of a thai pad, this system is mean to be fully embedded. However, below is a sketch of the sensor positioning. Additionally, the microcontroller will be surrounded in a TPU case to protect it from the repeated shocks.
- Note: These are meant to be flexible as there are many variation of thai pad designs.
![image](https://github.com/user-attachments/assets/06b3a453-3c4d-4ea4-b32f-c71c10dfaf04)
### Wiring Diagram
- As the thai pad is rather large, a PCB will not work, instead I have attached a wiring diagram.
![image](https://github.com/user-attachments/assets/e55787f7-3da6-441b-bc26-df8c8e7f5b89)


##BOM
| Part                        | Cost     | Count | Notes          | Link                                                                 | Total  |
|-----------------------------|----------|-------|----------------|----------------------------------------------------------------------|--------|
| Adafruit Feather nRF52840 Sense | $39.50   | 1     | Already Owned   | [Link](https://www.adafruit.com/product/4516)                        | $0     |
| Li-Po Battery              | $0       | 1     | Already Owned   | [Link](https://www.adafruit.com/product/4237)                        | $0     |
| STEVAL-MKI251A             | $16.81   | 1     | Free Shipping   | [Link](https://estore.st.com/en/steval-mki251a-cpn.html)            | $16.81 |
| Piezo Sensor               | $2.32    | 1     | 5-Pack          | [Link](https://www.aliexpress.us/item/3256808935246513.html)        | $2.32  |
| TPU Filament               | $10.09   | 1     | $8.42 shipping  | [Link](https://www.aliexpress.us/item/3256804775295760.html)        | $18.51 |
| Neopixel Light Strip       | $9.18    | 1     | 2m 60           | [Link](https://www.aliexpress.us/item/2251801850504415.html)        | $9.18  |
|                             |          |       |                |                                                                      |        |
| **Total:**                  |          |       |                |                                                                      | **$47** |



