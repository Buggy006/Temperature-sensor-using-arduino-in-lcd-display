#include "DHT.h"
#define DHTPIN 6  // what pin we're connected to
#define DHTTYPE DHT11  // DHT 22  (AM2302)
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
 
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.print("Failed to read from DHT sensor!");
    return;
  }



  lcd.print("Humidity: ");
  lcd.print(h);
  delay(1000);
  lcd.clear();
  lcd.print("Temperature: ");
  lcd.print(t);
  delay(1000);
  lcd.clear();
  lcd.print(" *C ");
  lcd.print(f);
  lcd.print(" *F\t");


delay(1000);
}
