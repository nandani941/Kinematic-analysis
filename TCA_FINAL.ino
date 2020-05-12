#include <MPU9250.h>

#include <Wire.h>

MPU9250 IMU1(Wire,0x68);
MPU9250 IMU2(Wire,0x68);
MPU9250 IMU3(Wire,0x68);
void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);  
  Wire.write(1 << bus);          
  Wire.endTransmission();
}

void setup()
{
  Wire.begin();
  Serial.begin(115200);
 /*IMU1.begin();

  IMU1.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  
  IMU1.setGyroRange(MPU9250::GYRO_RANGE_500DPS);

  IMU1.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  
  IMU1.setSrd(19);*/
  
  TCA9548A(6);    
  if (!IMU1.begin())
  {
    Serial.println("Could not find a valid MPU9250 sensor, check wiring!");
    while (1) {}
  }
  IMU2.begin();
  if (IMU2.begin() < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(IMU2.begin());
    while(1) {}
  }
 
  IMU2.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  
  IMU2.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
  IMU2.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  
  IMU2.setSrd(19);
  
  TCA9548A(7);    
  if (!IMU2.begin())
  {
    Serial.println("Could not find a valid MPU9250 sensor, check wiring!");
    while (1) {}
  }

  IMU3.begin();
 if (IMU3.begin() < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(IMU3.begin());
    while(1) {}
  }
  
  IMU3.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  
  IMU3.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
  
  IMU3.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  
  IMU3.setSrd(19);
  TCA9548A(0);    
  if (!IMU3.begin())
  {
    Serial.println("Could not find a valid MPU9250 sensor, check wiring!");
    while (1) {}
  }
}



void loop()
{
    TCA9548A(6);    
  
IMU1.readSensor();
  
  Serial.print("SENSOR-1 = ");
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
    
    TCA9548A(7);    
  
IMU2.readSensor();
  
  Serial.print("SENSOR-2 = ");
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

  TCA9548A(0);    
  
IMU3.readSensor();

  Serial.print("SENSOR-3 = ");
  Serial.print(IMU3.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print(IMU3.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(IMU3.getAccelZ_mss(),6);
  Serial.print("\t");
  Serial.print(IMU3.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(IMU3.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.println(IMU3.getGyroZ_rads(),6);
  delay(1000);
}
