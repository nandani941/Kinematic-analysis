

#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU1(Wire,0x68);
MPU9250 IMU2(Wire,0x69);
//int status;

void setup() {
  // serial to display data
  Serial.begin(115200);
  IMU1.begin();
  IMU2.begin();
  while(!Serial) {}

  // start communication with IMU 
 /* status = IMU1.begin();
  status = IMU2.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }*/
}

void loop() {
  // read the sensor
  IMU1.readSensor();
  // display the data
  Serial.print(IMU1.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print(IMU1.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(IMU1.getAccelZ_mss(),6);
  Serial.print("\t");
  Serial.print(IMU1.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(IMU1.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print(IMU1.getGyroZ_rads(),6);
  Serial.print("\t");
  Serial.print(IMU1.getMagX_uT(),6);
  Serial.print("\t");
  Serial.print(IMU1.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print(IMU1.getMagZ_uT(),6);
  Serial.print("\t");
  Serial.println(IMU1.getTemperature_C(),6);
  delay(1000);

  IMU2.readSensor();
  // display the data
  Serial.print(IMU2.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print(IMU2.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(IMU2.getAccelZ_mss(),6);
  Serial.print("\t");
  Serial.print(IMU2.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(IMU2.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print(IMU2.getGyroZ_rads(),6);
  Serial.print("\t");
  Serial.print(IMU2.getMagX_uT(),6);
  Serial.print("\t");
  Serial.print(IMU2.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print(IMU2.getMagZ_uT(),6);
  Serial.print("\t");
  Serial.println(IMU2.getTemperature_C(),6);
  delay(1000);
}
