#include <Arduino.h>

TaskHandle_t Task1;
TaskHandle_t Task2;
SemaphoreHandle_t xSemaphore = NULL;

// Task1code: blinks an LED every 1000 ms
void Task1code(void *pvParameters)
{

  for (;;)
  {
    Serial.print("{");
    Serial.print("This is task1");
    Serial.println("}");
    xSemaphoreGive(xSemaphore);
    vTaskDelay(1000);
  }
}

// Task2code: blinks an LED every 700 ms
void Task2code(void *pvParameters)
{
  for (;;)
  {
    if (xSemaphoreTake(xSemaphore, portMAX_DELAY))
    {
      Serial.print("(");
      Serial.print("This is task2");
      Serial.println(")");
      vTaskDelay(1000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  xSemaphore = xSemaphoreCreateBinary();
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
