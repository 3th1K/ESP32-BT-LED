#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int LED_PIN = BUILTIN_LED;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("Ethik-ESP32-LED");
  Serial.println("Bluetooth Started! Pair with Ethik-ESP32-LED");
}

void loop()
{
  if(SerialBT.available())
  {
    char inp = SerialBT.read();
    if (inp == '1') 
    {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    } 
    else if (inp == '0') 
    {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    }
  }
}