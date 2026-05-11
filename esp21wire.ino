#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR_PIN 4 
#define READ_INTERVAL 1000 
#define TX_PIN 17  
#define RX_PIN 16  
#define UART_BAUD 9600 

OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);

unsigned long lastReadTime = 0;

void setup() {
  Serial.begin(115200);
  Serial2.begin(UART_BAUD, SERIAL_8N1, RX_PIN, TX_PIN);
  sensors.begin();
  Serial.println(F("System start. Stała ramka: 10 bajtów."));
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastReadTime >= READ_INTERVAL) {
    lastReadTime = currentMillis;

    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);

    char frame[12]; // Bufor na ramkę

    if (tempC != DEVICE_DISCONNECTED_C) {
      dtostrf(tempC, 7, 2, frame); 
      
      // Wysyłamy sformatowany ciąg
      Serial2.println(frame); 
      
      // Debug na USB
      Serial.print(F("Ramka: ["));
      Serial.print(frame);
      Serial.println(F("]"));
    } else {
      Serial2.println("  ERROR "); 
    }
  }
}