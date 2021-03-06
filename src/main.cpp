#include <Arduino.h>
#include <ESP.h>

String chipId;

void setup()
{

  Serial.begin(115200);

  // put your setup code here, to run once:
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  Serial.println("==================================");
  Serial.println("Hardware info");
  Serial.println("==================================");
  // identify the model:
  switch (chip_info.model)
  {
  case 1:
    Serial.println("ESP32");
    break;
  case 2:
    Serial.println("ESP32-S2");
    break;
  case 9:
    Serial.println("ESP32-S3");
    break;
  case 5:
    Serial.println("ESP32-C3");
    break;
  case 6:
    Serial.println("ESP32-H2");
    break;
  default:
    Serial.println("unknown ESP Model");
    break;
  }
  Serial.printf("%d cores Wifi %s%s\n", chip_info.cores, (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
  Serial.printf("Silicon revision: %d\n", chip_info.revision);
  Serial.printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
                (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embeded" : "external");

  // get chip id
  chipId = String((uint32_t)ESP.getEfuseMac(), HEX);
  chipId.toUpperCase();

  Serial.printf("Chip id: %s\n", chipId.c_str());

  Serial.printf("XTAL Freq: %d [MHz]\n", getXtalFrequencyMhz());
  Serial.printf("CPU Freq: %d [MHz]\n", getCpuFrequencyMhz());
  Serial.printf("APB Freq: %d [MHz]\n", getApbFrequency() / 1000000);
}

void loop()
{
  // put your main code here, to run repeatedly:
}