
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <FirebaseArduino.h>

//    WIFI
#define _SSID "Pozzy"  //Estudiantes Speedy-Fibra-
#define _PASSWORD "Gusiteamamos" //educar_2018 12345678

//    FIREBASE

#define _HOST "fir-domotica-3f5c2.firebaseio.com"
#define _AUTH "XpTERKjhfDAwmWXhPRiCapKOHkyDAxzZAETsDkAl"

uint32_t SLEEP_TIME = 10e6;
const int ActPin = 2;

void setup() {
  Serial.begin(115200);
  delay(10);
  
  WiFi.begin(_SSID, _PASSWORD);
  delay(2000);
  
  Serial.println("Conectando…"); 
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(3000);
  }
   Serial.println("Conectado");
   Serial.println(WiFi.localIP());

   pinMode(ActPin , OUTPUT);

   Firebase.begin(_HOST, _AUTH);
   
}

void loop() {
  
  int Estado = Firebase.getInt ("users/Estados/agus dantuoni/SpinnActuadores/a6/rele de estado solido ventilador");

  if(Estado == 1)
  {
     digitalWrite(ActPin , HIGH);
  }
  if(Estado == 0)
  {
    digitalWrite(ActPin , LOW);
  }
  
 /* if (millis() >= 1000){        
    ESP.deepSleep(SLEEP_TIME, WAKE_RF_DEFAULT);
    }
*/
}
