// ESP32 (Use Arduino IDE / Platform IO)

void setup() {
  Serial.begin(115200); // Set baud rate, must be the same as in Raspberry Pi
  Serial.println("ESP32 Ready...");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n'); // read until \n
    command.trim(); // remove space

    Serial.println(command);

    if (command == "status") {
      Serial.println("Status: Ready");
    } else if (command == "blink") {
      Serial.println("ESP32 Blinking...");
      for(int i=0; i<3; i++) {
        digitalWrite(2, HIGH); // If we connect LED on pin 2 of ESP32
        delay(200);
        digitalWrite(2, LOW);
        delay(200);
      }
      Serial.println("Done");
    } else {
      Serial.println("Unknown command: " + command);
    }
  }
}
