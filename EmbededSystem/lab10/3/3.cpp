#include <Arduino.h>

TaskHandle_t Task1;
TaskHandle_t Task2;
QueueHandle_t queue;

// Task1code: blinks an LED every 1000 ms
void Task1code(void *pvParameters)
{
  char msg[50];
  queue = xQueueCreate(5, sizeof(msg)); 

  for (;;)
  {
    if (Serial.available() > 0)
    {
      String input = Serial.readStringUntil('\n');
      if (input.length() > 0)
      {
        input.toCharArray(msg, 50);
        xQueueGenericSend(queue, (void *)msg, portMAX_DELAY, queueSEND_TO_BACK) == pdPASS;
      }
    }
    delay(10); // Small delay to prevent high CPU usage
  }
}

// Task2code: blinks an LED every 700 ms
void Task2code(void *pvParameters)
{
  char msg[50];
  for (;;)
  {
    // Receive a message from the queue
    if (xQueueReceive(queue, (void *)msg, portMAX_DELAY) == pdPASS)
    {
      Serial.print("Received from queue: ");
      Serial.println(msg);
    }
    delay(10); // Small delay to prevent high CPU usage
  }
}

void setup()
{
  Serial.begin(115200);
  //queue = xQueueCreate(5, sizeof(char) * 50);
  // create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreate(
      Task1code, /* Task function. */
      "Task1",   /* name of task. */
      10000,     /* Stack size of task */
      NULL,      /* parameter of the task */
      1,         /* priority of the task */
      &Task1     /* Task handle to keep track of created task */
  );
  // create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreate(
      Task2code, /* Task function. */
      "Task2",   /* name of task. */
      10000,     /* Stack size of task */
      NULL,      /* parameter of the task */
      1,         /* priority of the task */
      &Task2     /* Task handle to keep track of created task */
  );             /* pin task to core 1 */
}
void loop()
{
}
