#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
const int LED_PIN = BUILTIN_LED;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("Ethik-ESP32-LED");
  Serial.println("Bluetooth Started! Pair with Ethik-ESP32-LED");
}

void blinkLED(int interval) {
  // Continue blinking until a new Bluetooth command is received
  while (!SerialBT.available()) {
    digitalWrite(LED_PIN, HIGH);
    delay(interval);
    digitalWrite(LED_PIN, LOW);
    delay(interval);
  }
}

void loop() {
  if (SerialBT.available()) {
    char inp = SerialBT.read();
    switch (inp) {
      case '1':
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED ON");
        break;

      case '0':
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED OFF");
        break;

      case '2': blinkLED(4000); break;
      case '3': blinkLED(3500); break;
      case '4': blinkLED(2800); break;
      case '5': blinkLED(2200); break;
      case '6': blinkLED(1600); break;
      case '7': blinkLED(1000); break;
      case '8': blinkLED(600); break;
      case '9': blinkLED(200); break;
      default:
        Serial.println("Invalid input");
        break;
    }
  }
}
