#include <sensor.h>
#include <bmp280.h>

BMP280 bmpSensor;

float TEMPERATURA;  
float PRESION;     
float ALTITUD;

unsigned long previousMillis=0;
const long interval=5000;

void setup() {
  Serial.begin(9600);     
  Serial.println("Iniciando: ");  
  if (!bmpSensor.begin()) {       
    Serial.println("BMP280 no encontrado!");  
    while (1);            
  }
}

void loop() {

unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {
  previousMillis = currentMillis;

  TEMPERATURA = bmpSensor.readTemperature(); 
  PRESION = bmpSensor.readPressure()/100; 
  ALTITUD = bmpSensor.readAltitude();

  Serial.print("Temperatura: "); 
  Serial.print(TEMPERATURA);  
  Serial.print(" C ");  

  Serial.print("Presion: ");  
  Serial.print(PRESION);  
  Serial.println(" hPa");  

  Serial.print("Altitud: ");  
  Serial.print(ALTITUD);  
  Serial.println(" m");  

}
  
}