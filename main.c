#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "dht11.h"

#define CONFIG_DHT11_PIN GPIO_NUM_26
#define CONFIG_CONNECTION_TIMEOUT 5
void app_main(){
  dht11_t dht11_sensor;
  dht11_sensor.dht11_pin = CONFIG_DHT11_PIN;
}
while(1)
    {
      if(!dht11_read(&dht11_sensor, CONFIG_CONNECTION_TIMEOUT))
      {  
      printf("Temperature %.2f \n",dht11_sensor.temperature);
      printf("Humidity %.2f \n",dht11_sensor.humidity);
      }
      vTaskDelay(pdMS_TO_TICKS(50));
