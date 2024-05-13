#include <sensor.h>
#include <bmp280.h>

#define minTemp 20
#define maxTemp 300
#define minPr 0
#define maxPr 500
#define minAlt 0
#define maxAlt 1100

BMP280 bmpSensor;

float TEMPERATURA;  
float PRESION;     
float ALTITUD;

void setup() {
  Serial.begin(9600);       
  Serial.println("Iniciando: ");  
  if (!bmpSensor.begin()) {       
    Serial.println("BMP280 no encontrado !");  
    while (1);            
  }
}

void loop() {
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

  delay(5000); // demora de 5 segundos entre lecturas
}
