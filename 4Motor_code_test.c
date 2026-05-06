#include <Arduino.h>
#include <Wire.h>
#include <Motoron.h>

MotoronI2C mc;

// 四个电机
const uint8_t MOTOR_1 = 1;
const uint8_t MOTOR_2 = 2;
const uint8_t MOTOR_3 = 3;
const uint8_t MOTOR_4 = 4;

// 快速测试
// Motoron 常用范围大约 -800 到 800
const int16_t MOTOR_SPEED = 600;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  // 注意：使用 Wire1
  Wire1.begin();
  mc.setBus(&Wire1);

  mc.reinitialize();
  mc.disableCrc();
  mc.clearResetFlag();

  mc.setMaxAcceleration(MOTOR_1, 300);
  mc.setMaxDeceleration(MOTOR_1, 500);

  mc.setMaxAcceleration(MOTOR_2, 300);
  mc.setMaxDeceleration(MOTOR_2, 500);

  mc.setMaxAcceleration(MOTOR_3, 300);
  mc.setMaxDeceleration(MOTOR_3, 500);

  mc.setMaxAcceleration(MOTOR_4, 300);
  mc.setMaxDeceleration(MOTOR_4, 500);

  mc.setSpeed(MOTOR_1, 0);
  mc.setSpeed(MOTOR_2, 0);
  mc.setSpeed(MOTOR_3, 0);
  mc.setSpeed(MOTOR_4, 0);

  Serial.println("Four motors fast test");
  Serial.println("2 seconds later start...");
  delay(2000);
}

void loop()
{
  mc.setSpeed(MOTOR_1, MOTOR_SPEED);
  mc.setSpeed(MOTOR_2, MOTOR_SPEED);
  mc.setSpeed(MOTOR_3, MOTOR_SPEED);
  mc.setSpeed(MOTOR_4, MOTOR_SPEED);

  Serial.println("All four motors running fast");

  delay(200);
}
