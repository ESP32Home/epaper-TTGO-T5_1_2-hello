#include <Arduino.h>

#include <SPIFFS.h>
#include <epaper.h>

EPaper epaper;

void setup()
{
    Serial.begin(115200);
    SPIFFS.begin();

    epaper.init();

    delay(500);

    if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_UNDEFINED) {
        epaper.display.fillScreen(GxEPD_WHITE);
        epaper.drawBitmap("/esp_home.bmp", 0, 50, true);
        epaper.displayText("Hello simple", 20, EPaper::RIGHT_ALIGNMENT);
        epaper.display.update();
    }
}

void loop()
{
    delay(5000);
    Serial.print(".");
}
