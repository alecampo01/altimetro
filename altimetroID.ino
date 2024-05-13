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
   if(TEMPERATURA<=maxTemp && TEMPERATURA>=minTemp){
    Serial.print("Temperatura: ");
    Serial.print(TEMPERATURA);
    Serial.println(" C");
  }else{
    Serial.println("Temperatura no válida");
  }

  PRESION = bmpSensor.readPressure()/100; 
  if(PRESION<=maxPr && PRESION>=minTemp){
    Serial.print("Presion: ");
    Serial.println(" hPa");
  }else{
    Serial.println("Presión no válida");
  }

  ALTITUD = bmpSensor.readAltitude();
  if(ALTITUD<=maxAlt && ALTITUD>=minAlt){
    Serial.print("Altitud: ");
    Serial.println(" m");
  }else{
    Serial.println("Altitud no válida");
  }


  delay(5000); // demora de 5 segundos entre lecturas
}
