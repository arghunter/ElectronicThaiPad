// SPDX-FileCopyrightText: 2020 Carter Nelson for Adafruit Industries
//
// SPDX-License-Identifier: MIT
//
#include <Adafruit_APDS9960.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_LIS3MDL.h>
#include <Adafruit_LSM6DS33.h>
#include <Adafruit_LSM6DS3TRC.h>
#include <Adafruit_SHT31.h>
#include <Adafruit_Sensor.h>
#include <PDM.h>

Adafruit_APDS9960 apds9960; // proximity, light, color, gesture
Adafruit_BMP280 bmp280;     // temperautre, barometric pressure
Adafruit_LIS3MDL lis3mdl;   // magnetometer
Adafruit_LSM6DS3TRC lsm6ds3trc; // accelerometer, gyroscope
Adafruit_LSM6DS33 lsm6ds33;
Adafruit_SHT31 sht30;       // humidity

uint8_t proximity;
uint16_t r, g, b, c;
float temperature, pressure, altitude;
float magnetic_x, magnetic_y, magnetic_z;
float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;
float humidity;
int32_t mic;
long int accel_array[6];
long int check_array[6]={0.00, 0.00, 0.00, 0.00, 0.00, 0.00};

extern PDMClass PDM;
short sampleBuffer[256];  // buffer to read samples into, each sample is 16-bits
volatile int samplesRead; // number of samples read

bool new_rev = true;

void setup(void) {
  Serial.begin(115200);
  // while (!Serial) delay(10);


  // initialize the sensors

  lis3mdl.begin_I2C();
  lsm6ds33.begin_I2C();
  // check for readings from LSM6DS33
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  lsm6ds33.getEvent(&accel, &gyro, &temp);
  accel_array[0] = accel.acceleration.x;
  accel_array[1] = accel.acceleration.y;
  accel_array[2] = accel.acceleration.z;
  accel_array[3] = gyro.gyro.x;
  accel_array[4] = gyro.gyro.y;
  accel_array[5] = gyro.gyro.z;
  // if all readings are empty, then new rev
  for (int i =0; i < 5; i++) {
    if (accel_array[i] != check_array[i]) {
      new_rev = false;
      break;
    }
  }
  // and we need to instantiate the LSM6DS3TRC
  if (new_rev) {
    lsm6ds3trc.begin_I2C();
  }


}

void loop(void) {

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  if (new_rev) {
    lsm6ds3trc.getEvent(&accel, &gyro, &temp);
  }
  else {
    lsm6ds33.getEvent(&accel, &gyro, &temp);
  }
  accel_x = accel.acceleration.x;
  accel_y = accel.acceleration.y;
  accel_z = accel.acceleration.z;

  
  Serial.println("\nFeather Sense Sensor Demo");
  Serial.println("---------------------------------------------");
  Serial.print("Acceleration: ");
  Serial.print(accel_x);
  Serial.print(" ");
  Serial.print(accel_y);
  Serial.print(" ");
  Serial.print(accel_z);
  Serial.println(" m/s^2");
  delay(30);
}

