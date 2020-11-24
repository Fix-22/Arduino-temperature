#include <SimpleDHT.h>
#include <LiquidCrystal.h>
// for DHT11,
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2

#define DHTPIN 7
SimpleDHT11 dht11;

int buzzer = 3;
int led1 = 13;
int led2 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  Serial.println("");
  Serial.println("Calcolando...");

  byte temp = 0;
  byte umid = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(DHTPIN, &temp, &umid, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Lettura fallita, err=");
    Serial.println(err);
    delay(1000);
    return;
  }
  if (temp > 30) {
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
  }
  else {
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
    delay(1000);
  }

  Serial.print("Temperatura: ");
  Serial.print((int)temp); Serial.print(" *C, ");
  Serial.print((int)umid); Serial.println(" H");
  if (temp > 30) {
    Serial.print("Temperatura oltre il limite!");
  }
  else {
    Serial.print("Temperatura nella norma!");
  }

  // DHT11 sampling rate is 1HZ.
  delay(1500);

  
}
