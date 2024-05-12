#include <sensor.h>
#include <bmp280.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define minTemp 20
#define maxTemp 300
#define minPr 0
#define maxPr 500
#define minAlt 0
#define maxAlt 1100

Adafruit_BMP280 bmpSensor;

float TEMPERATURA;
float PRESION;
float ALTITUD;

// obtener datos del sensor y mostrarlos

void leerTemp(Adafruit_BMP280& bmpSensor) {
  TEMPERATURA = bmpSensor.readTemperature();
  if(TEMPERATURA<=maxTemp && TEMPERATURA>=minTemp){
    Serial.print("Temperatura: ");
    Serial.print(TEMPERATURA);
    Serial.println(" C");
  }else{
    Serial.println("Temperatura no válida");
  }
}

void leerP(Adafruit_BMP280& bmpSensor) {
  PRESION = bmpSensor.readPressure();
  if(PRESION<=maxPr && PRESION>=minTemp){
    Serial.print("Presion: ");
    Serial.println(" hPa");
  }else{
    Serial.println("Presión no válida");
  }
}

void leerAlt(Adafruit_BMP280& bmpSensor) {
  ALTITUD = bmpSensor.readAltitude();
  if(ALTITUD<=maxAlt && ALTITUD>=minAlt){
    Serial.print("Altitud: ");
    Serial.println(" m");
  }else{
    Serial.println("Altitud no válida");
  }
}

//
void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");

  if (!bmpSensor.begin()) {
    Serial.println("No se pudo encontrar el sensor BMP280. Verifica las conexiones.");
    while (1); // detiene el programa si el sensor no está disponible
  }
}

//
void loop() {
  //obtenerDatosYMostrar(bmpSensor);
}
