#include <MPU9250.h>



#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "my-gait-analysis.firebaseio.com"
#define FIREBASE_AUTH "GZ5tSt8ubQOnDEYDZ7x2d95oofuhCJTi9XjO7AHk"
#define WIFI_SSID "POCO PHONE"
#define WIFI_PASSWORD "12345678910"

MPU9250 IMU(Wire,0x68);
int status;


void setup() {
  Serial.begin(115200);
   status = IMU.begin();

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

 

 

void loop() {
 
  float ax = IMU.getAccelX_mss();
 float ay = IMU.getAccelY_mss();
float az = IMU.getAccelZ_mss();
 float gx = IMU.getGyroX_rads();
 float gy = IMU.getGyroY_rads();
 float gz = IMU.getGyroZ_rads();

float mx = IMU.getMagX_uT();
 float my = IMU.getMagY_uT();
  float mz = IMU.getMagZ_uT();
   
 

 Serial.print("Accel X: ");  Serial.print(ax);
  String fireAccela  = String(ax); 
 
Serial.print("\t");
 
  Serial.print("Accel Y: ");  Serial.print(ay);
  String fireAccelb  = String(ay); 

Serial.print("\t");

   Serial.print("Accel Z: ");  Serial.print(az);
  String fireAccelc  = String(az); 
 Serial.print("\n");

  Serial.print("Gyro X: ");  Serial.print(gx);
  String fireGyroa = String(gx); 

Serial.print("\t");

   Serial.print("Gyro Y: ");  Serial.print(gy);
  String fireGyrob  = String(gy); 

Serial.print("\t");

   Serial.print("Gyro Z: ");  Serial.print(gz);
  String fireGyroc  = String(gz); 

Serial.print("\t");
    Serial.print("Mag X: ");  Serial.print(mx);
  String fireMaga  = String(mx); 
Serial.print("\t");

  Serial.print("Mag Y: ");  Serial.print(my);
  String fireMagb  = String(my); 
Serial.print("\t");
  Serial.print("Mag Z: ");  Serial.print(mz);
  String fireMagc  = String(mz); 
Serial.print("\n");

Firebase.pushString("/sensor 1/Accel X",fireAccela );    

Firebase.pushString("/sensor 1/Accel Y",fireAccelb ); 

Firebase.pushString("/sensor 1/Accel Z",fireAccelc ); 


Firebase.pushString("/sensor 1/Gyro X",fireGyroa ); 

Firebase.pushString("/sensor 1/Gyro Y",fireGyrob ); 

Firebase.pushString("/sensor 1/Gyro Z",fireGyroc ); 

Firebase.pushString("/sensor 1/Mag X",fireMaga );

Firebase.pushString("/sensor 1/Mag Y",fireMagb );

Firebase.pushString("/sensor 1/Mag Z",fireMagc );

 delay(0.0001);
}
