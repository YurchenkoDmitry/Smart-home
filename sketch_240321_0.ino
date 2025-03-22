//call the relevant library file
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Set the communication address of I2C to 0x27, display 16 characters every line, two lines in total
LiquidCrystal_I2C mylcd(0x27, 16, 2);

//set ports of two servos to digital 9 and 10
Servo servo_10;
Servo servo_9;

volatile int btn1_num;//set variable btn1_num
volatile int btn2_num;//set variable btn2_num
volatile int button1;//set variable button1
volatile int button2;//set variable button2

void setup() {
  mylcd.begin(); // Initialize LCD
  mylcd.backlight(); // Turn on backlight
  servo_10.attach(10);
  servo_9.attach(9);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  button1 = digitalRead(2);
  button2 = digitalRead(3);

  if (button1 == HIGH) {
    servo_10.write(90);
    mylcd.setCursor(0, 0);
    mylcd.print("Servo 10 ON");
  }
  
  if (button2 == HIGH) {
    servo_9.write(90);
    mylcd.setCursor(0, 1);
    mylcd.print("Servo 9 ON");
  }
  
  delay(500);
  
  // Добавлено новое поведение
  if (button1 == LOW && button2 == LOW) {
    mylcd.clear();
    mylcd.setCursor(0, 0);
    mylcd.print("All off");
  }
  
  // Новое изменение: мигание светодиода на пине 13
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
}
