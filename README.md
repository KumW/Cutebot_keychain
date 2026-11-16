
---

# ESP32-C3 Expression Keychain (表情挂件)

本项目是一个基于 **ESP32-C3** 微控制器和 **OLED 屏幕** 的微型可编程动态表情挂件。它支持通过代码实现丰富的像素风动态表情（如眨眼、睁眼、笑脸等），并支持在浏览器中进行零硬件模拟仿真。

---

## 📌 项目特性 (Features)

* **超小体积**：采用 ESP32-C3 SuperMini / 模块，完美适配小型挂件外壳。
* **低功耗与连接性**：支持 Wi-Fi 与蓝牙，方便未来扩展互动功能。
* **像素风动态表情**：通过 Adafruit GFX 库实现流畅的眼睛眨动与状态切换。
* **双模开发**：支持本地 **VS Code + PlatformIO** 开发，也支持 **Wokwi** 网页在线模拟测试。

---

## 🛠 硬件清单 (Bill of Materials)

| 零件名称 | 型号推荐 | 说明 |
| --- | --- | --- |
| **主控芯片** | ESP32-C3 SuperMini / XIAO ESP32-C3 | 体积极小，自带无线功能 |
| **显示屏** | 1.3英寸 OLED 屏幕 (128x64分辨率, I2C接口) | 用于显示动态表情 |
| **电池** | 200mAh - 300mAh 超薄锂聚合物电池 | 供电电源 |
| **外壳** | 3D 打印外壳 (PLA / PETG) | 可在开源社区搜索相关模型 |

---

## 🔌 接线指南 (Pinout)

如果使用标准 I2C 接口的 OLED 屏幕，请将引脚按如下方式连接：

| OLED 屏幕引脚 | ESP32-C3 引脚 | 说明 |
| --- | --- | --- |
| **GND** | GND | 地线 |
| **VCC** | 3.3V | 电源正极 |
| **SCL** | GPIO 22 | I2C 时钟线 |
| **SDA** | GPIO 21 | I2C 数据线 |

---

## 💻 快速开始与模拟仿真 (Simulation)

如果你目前没有实体硬件，可以通过以下两种方式进行测试：

### 1. 网页端在线模拟 (Wokwi)

1. 访问 [Wokwi 官网](https://wokwi.com/) 并新建一个 **ESP32** 项目。
2. 添加 **SSD1306 OLED Display** 屏幕组件，并按照上方接线表完成连线。
3. 在项目依赖文件 `libraries.txt` 中添加依赖：
```text
Adafruit SSD1306
Adafruit GFX Library

```


4. 将 `src/main.cpp` 的核心表情代码复制到编辑器中，点击运行即可实时查看动态表情。

### 2. 本地开发 (VS Code + PlatformIO)

1. 使用 VS Code 打开本项目文件夹。
2. 确保 `platformio.ini` 配置正确：
```ini
[env:esp32c3]
platform = espressif32
board = esp32-c3-devkitm-1
framework = arduino
monitor_speed = 115200
lib_deps =
    adafruit/Adafruit SSD1306 @ ^2.5.7
    adafruit/Adafruit GFX Library @ ^1.11.9
    adafruit/Adafruit BusIO @ ^1.14.5

```


3. 点击底部状态栏的 **✓ (Build)** 按钮进行编译检查，确认无误后通过数据线连接硬件并点击 **→ (Upload)** 烧录固件。

---

## 📂 代码结构 (Code Structure)

* `src/main.cpp`：核心主程序，包含初始化逻辑以及 `drawNormalEyes()`（正常睁眼）、`drawBlinkEyes()`（眨眼）、`drawHappyEyes()`（笑脸）等状态切换函数。
* `platformio.ini`：PlatformIO 编译环境与依赖库配置文件。