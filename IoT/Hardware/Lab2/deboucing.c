#include <wiringPi.h>
#include <stdio.h>
#include <stdbool.h>
int LED = 0;
int BUTTON = 2;
bool lastButtonState = LOW;

int main() {
	wiringPiSetup();
	pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
    while (1) {
        if (lastButtonState != digitalRead(BUTTON)) {
            lastButtonState = digitalRead(BUTTON);
            if (lastButtonState == HIGH) {
                digitalWrite(LED, !digitalRead(LED));
            }
        }
        delay(100);
    }
}