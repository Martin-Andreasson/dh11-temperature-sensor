// Include libraries
#include <dht.h>
#include <LiquidCrystal.h>

// The setup routine runs once when you press reset:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
#define DHT11_PIN 7

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

// the loop routine runs over and over again forever:
void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature); 
  lcd.print((char)223);
  lcd.print("C"); 
  lcd.setCursor(0,1); 
  lcd.print("Humidity: "); 
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000); // 

  if (DHT.temperature < 25) { 
    digitalWrite(13, HIGH); 
    delay(1000); 
    digitalWrite(13, LOW); 
    delay(1000); 
  }
  else { 
    digitalWrite(14, HIGH); 
    delay(1000); 
    digitalWrite(14, LOW); 
    delay(1000);   
  }
 delay(1000); 
}
