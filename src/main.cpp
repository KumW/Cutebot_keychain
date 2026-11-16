#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 函数前置声明
void drawNormalEyes();
void drawBlinkEyes();
void drawHappyEyes();

void setup() {
  Serial.begin(115200);

  // 初始化 SSD1306 屏幕（I2C 地址通常为 0x3C）
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.display();
}

void loop() {
  // 状态一：正常睁眼持续 2 秒
  drawNormalEyes();
  delay(2000);

  // 状态二：眨眼（快速闭眼 150 毫秒）
  drawBlinkEyes();
  delay(150);

  // 状态三：恢复睁眼 1.5 秒
  drawNormalEyes();
  delay(1500);

  // 状态四：切换到开心表情 1.5 秒
  drawHappyEyes();
  delay(1500);
}

void drawNormalEyes() {
  display.clearDisplay();
  display.fillRoundRect(24, 20, 24, 28, 6, SSD1306_WHITE);
  display.fillRoundRect(80, 20, 24, 28, 6, SSD1306_WHITE);
  display.display();
}

void drawBlinkEyes() {
  display.clearDisplay();
  display.fillRect(24, 32, 24, 4, SSD1306_WHITE);
  display.fillRect(80, 32, 24, 4, SSD1306_WHITE);
  display.display();
}

void drawHappyEyes() {
  display.clearDisplay();
  display.drawLine(24, 36, 36, 24, SSD1306_WHITE);
  display.drawLine(36, 24, 48, 36, SSD1306_WHITE);
  display.drawLine(80, 36, 92, 24, SSD1306_WHITE);
  display.drawLine(92, 24, 104, 36, SSD1306_WHITE);
  display.display();
}