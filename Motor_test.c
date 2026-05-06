#include <Wire.h>
#include "ICM_20948.h"


ICM_20948 imu;

void setup() {
  Serial.begin(115200); 
  Wire.begin();

  Serial.println("正在初始化 ICM20948...");
  
  // 初始化传感器
  if (!imu.begin(Wire, 0x68)) { // 默认 I2C 地址通常是 0x68
    Serial.println("未检测到传感器，请检查接线！");
    while (1);
  }
  Serial.println("ICM20948 初始化成功！");
}

void loop() {
  // 读取传感器数据
  imu.readSensor();

  // 输出加速度数据 (Accelerometer)
  Serial.print("Acc: ");
  Serial.print(imu.accelX()); Serial.print(", ");
  Serial.print(imu.accelY()); Serial.print(", ");
  Serial.print(imu.accelZ()); 

  // 输出陀螺仪数据 (Gyroscope)
  Serial.print(" | Gyro: ");
  Serial.print(imu.gyroX()); Serial.print(", ");
  Serial.print(imu.gyroY()); Serial.print(", ");
  Serial.print(imu.gyroZ());

  Serial.println();
  delay(200);
}
