
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <MPU9250.h>

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "POCO PHONE"
#define WLAN_PASS       "12345678910"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "NANDANI"
#define AIO_KEY         "aio_kWcg13XNSOICLu8uMX4AP1duJUQm"

/************ Global State (you don't need to change this!) ******************/


WiFiClient client;



Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/


// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish FIELD_1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/accel x");
Adafruit_MQTT_Publish FIELD_2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/accel y");
Adafruit_MQTT_Publish FIELD_3 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/accel z");
Adafruit_MQTT_Publish FIELD_4 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/gyro x");
Adafruit_MQTT_Publish FIELD_5 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/gyro x");
Adafruit_MQTT_Publish FIELD_6 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/gyro x");


/*************************** Sketch Code ************************************/


MPU9250 IMU(Wire,0x68);
int status;


void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(1000);
  status = IMU.begin();

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
}

void loop() 
{
MQTT_connect();
float ax = IMU.getAccelX_mss();
 float ay = IMU.getAccelY_mss();
float az = IMU.getAccelZ_mss();
 float gx = IMU.getGyroX_rads();
 float gy = IMU.getGyroY_rads();
 float gz = IMU.getGyroZ_rads();

 if (isnan(ax) || isnan(ay)  || isnan(az) || isnan(gx)|| isnan(gy) || isnan(gz) ) {
Serial.println("Failed to read from DHT sensor!");
return;
}

Serial.print("Accel X: ");  Serial.print(ax);
Serial.print("\t");
 
  Serial.print("Accel Y: ");  Serial.print(ay);
Serial.print("\t");

   Serial.print("Accel Z: ");  Serial.print(az); 
 Serial.print("\n");

  Serial.print("Gyro X: ");  Serial.print(gx);
Serial.print("\t");

   Serial.print("Gyro Y: ");  Serial.print(gy); 
Serial.print("\t");

   Serial.print("Gyro Z: ");  Serial.print(gz);
Serial.print("\n");

delay(1000);
  

  if (! FIELD_1.publish(ax)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

    if (! FIELD_2.publish(ay)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

    if (! FIELD_3.publish(az)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

    if (! FIELD_4.publish(gx)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

    if (! FIELD_5.publish(gy)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

    if (! FIELD_6.publish(gz)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

   
}



void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(1000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
