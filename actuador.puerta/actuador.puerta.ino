#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <FirebaseArduino.h>

//    WIFI
#define _SSID "Pozzy"  //Speedy-Fibra-
#define _PASSWORD "Gusiteamamos" //12345678

//    FIREBASE

#define _HOST "fir-domotica-3f5c2.firebaseio.com"
#define _AUTH "XpTERKjhfDAwmWXhPRiCapKOHkyDAxzZAETsDkAl"

uint32_t SLEEP_TIME = 10e6;
const int ActPin = 2;

int temp;

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
  
  int Estado = Firebase.getInt ("users/Estados/agusdantuoni25/SpinnActuadores/a6/rele de estado solido(ventilador)");
  
  String Auto = Firebase.getString ("users/Modo/Automatico");
  
  temp = Firebase.getInt("users/utilizacion/SpinnSensores/s1/temp");

  if(Auto == "Activado"){

if(temp >= 25){
  
  digitalWrite(ActPin , HIGH);
} else {
  
  if(temp<25){
    
     digitalWrite(ActPin , LOW);
  } 
}
    
  } else {
    
    Auto = "Descativado";

  if(Estado == 1)
  {
     digitalWrite(ActPin , HIGH); 
  }
  if(Estado == 0)
  {
    digitalWrite(ActPin , LOW); 
  }

  }

  Serial.println(Estado);
  
 /* if (millis() >= 1000){        
    ESP.deepSleep(SLEEP_TIME, WAKE_RF_DEFAULT);
    }
*/
}
