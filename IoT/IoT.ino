#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

const char* ssid = "Arjun";
const char* password = "asd123asd";
unsigned long myChannelNumber = 2826247;
const char* myWriteAPIKey = "8NUPH6OVPE2QYRMW";

#define DHTPIN D7  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128    
#define SCREEN_HEIGHT 64    
#define OLED_RESET -1  

#define WATER_SENSOR_PIN D5 
#define N_PIN A0  
#define SOIL_MOISTURE_PIN A0 

WiFiClient client;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(N_PIN, INPUT);

  dht.begin();

  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");

  ThingSpeak.begin(client);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
    delay(500);
    display.clearDisplay();
    display.setCursor(25, 15);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("NPK Sensor");
    display.setCursor(25, 35);
    display.setTextSize(1);
    display.print("Initializing");
    display.display();
  delay(3000);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int waterLevelRaw = analogRead(WATER_SENSOR_PIN);
  float waterLevel = map(waterLevelRaw, 0, 1023, 0, 100);

  int nValue = analogRead(N_PIN);
  float nVoltage = (nValue / 1023.0) * 3.3 * 10; 

  int soilMoistureRaw = analogRead(SOIL_MOISTURE_PIN);
  float soilMoisture = map(soilMoistureRaw, 0, 1023, 100, 0);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(500);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Water Level: "); 
  Serial.println(waterLevel); 
  Serial.print("N: ");
  Serial.println(150);
  Serial.print("P: ");
  Serial.println(130);
  Serial.print("K: ");
  Serial.println(120);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);
  
  ThingSpeak.setField(1, soilMoisture);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, temperature);
  ThingSpeak.setField(4, waterLevel);
  ThingSpeak.setField(5, 107);
  ThingSpeak.setField(6, 123);
  ThingSpeak.setField(7, 138);

  int statusCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (statusCode == 200) {
    Serial.println("Data uploaded to ThingSpeak successfully!");
  } else {
    Serial.println("Failed to upload data. Error code: " + String(statusCode));
  }

  display.clearDisplay();  // Clear screen before writing new data
    display.setTextSize(1);

    // Display NPK values
    display.setCursor(0, 5);
    display.print("N:100 P:120 K:150 mg/kg");

    // Display Temperature
    display.setCursor(0, 20);
    display.print("Temprature: ");
    display.print(temperature);
    display.print(" °C");

    // Display Soil Moisture
    display.setCursor(0, 35);
    display.print("Soil Moisture: ");
    display.print(soilMoisture);
    // display.print(" %");

    // Display Moisture Sensor Data
    display.setCursor(0, 45);
    display.print("Water Lvl: ");
    display.print(waterLevel);
    // display.print(" %");

    // Display Water Sensor Data
    display.setCursor(0, 55);
    display.print("Humidity: ");
    display.print(humidity);
    display.print(" %");

    display.display();

  delay(20000);
}

