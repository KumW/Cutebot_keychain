#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long lastActionTime = 0;
int interval = 3000; // 每 3 秒随机换一次表情

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  unsigned long currentTime = millis();
  
  // 当到达随机时间间隔时，自动切换表情
  if (currentTime - lastActionTime > interval) {
    lastActionTime = currentTime;
    
    // 生成一个 1 到 4 的随机数，模拟Claude宠物的自主行为
    int mood = random(1, 5); 
    
    display.clearDisplay();
    switch (mood) {
      case 1: drawBlinkEyes(); break;   // 眨眼
      case 2: drawHappyEyes(); break;  // 高兴/笑脸
      case 3: drawLookingAround(); break; // 左右看
      case 4: drawSleepyEyes(); break;  // 犯困/闭眼
    }
    display.display();
    
    // 随机下一次动作的间隔（2秒到6秒不等），显得更有生命力
    interval = random(2000, 6000); 
  }
}

// 各种表情的绘制函数（例如画眼睛、弧线等）...
void drawBlinkEyes() { /* 绘制眨眼的代码 */ }
void drawHappyEyes() { /* 绘制笑脸的代码 */ }
void drawLookingAround() { /* 绘制移动视线的代码 */ }
void drawSleepyEyes() { /* 绘制睡觉的代码 */ }