#define servoPin 4

#include <Servo.h>

Servo webo;
int angle=300;

void setup() {
  webo.attach(servoPin);
  Serial.begin(9600);

}

void loop() {
  //webo.write(0);
  if(Serial.available() > 0){
    angle = Serial.read();
    //angle = angle-48;
  }

  if(angle == '0'){
    webo.write(0);
    Serial.println("SERVO EN 0");
    angle=300;
  }else if(angle=='1'){
    webo.write(90);
    Serial.println("SERVO EN 90");
    angle=300;
  }
  else{
    Serial.println("SIN CAMBIO");
  }
}
