#include <Adafruit_LSM6DS33.h>
#include <Adafruit_LSM6DS3TRC.h>
#include <Adafruit_NeoPixel.h>


Adafruit_LSM6DS3TRC lsm6ds3trc; // accelerometer, gyroscope
Adafruit_LSM6DS33 lsm6ds33;

#define LED_PIN     8


#define LED_COUNT  1


#define BRIGHTNESS 50 // Set BRIGHTNESS to about 1/5 (max = 255)


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);



float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;


long int accel_array[6];
long int check_array[6]={0.00, 0.00, 0.00, 0.00, 0.00, 0.00};



bool new_rev = true;

void setup(void) {
  Serial.begin(115200);
  // while (!Serial) delay(10);


  // initialize the sensors


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

  for (int i =0; i < 5; i++) {
    if (accel_array[i] != check_array[i]) {
      new_rev = false;
      break;
    }
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);
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
  strip.setPixelColor(0,strip.Color(abs(accel_x),   abs(accel_y),   abs(accel_z)));
  strip.setBrightness(abs(accel_x)*abs(accel_y)*abs(accel_z)+25);
  strip.show();
  
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

