// ESP32 (Use Arduino IDE / Platform IO)

int counter = 0;

void setup() {
  Serial.begin(115200); // Set baud rate, must be the same as in Raspberry Pi
  Serial.println("ESP32 Ready...");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n'); // read until \n
    command.trim(); // remove space

    if (command == "increment") {
      counter++;
      Serial.println("Counter incremented: " + String(counter));
    } else if (command == "decrement") {
      counter--;
      Serial.println("Counter decremented: " + String(counter));
    } else if (command == "reset") {
      counter = 0;
      Serial.println("Counter reset to zero.");
    } else if (command == "status") {
      Serial.println("Current counter value: " + String(counter));
    } else {
      Serial.println("Unknown command: " + command);
    }
  }
}