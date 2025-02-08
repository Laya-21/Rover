#include <PS4Controller.h>

#define RF_LPWM 27
#define RF_RPWM 26

#define RB_LPWM 25
#define RB_RPWM 33

#define LF_LPWM 5
#define LF_RPWM 17

#define LB_LPWM 19
#define LB_RPWM 18

#define PWMFreq 1000
#define PWMResolution 8


void forward(int speed)
{
  analogWrite(RF_LPWM, speed);
  analogWrite(RF_RPWM, 0);
  analogWrite(RB_LPWM, speed);
  analogWrite(RB_RPWM, 0);
  analogWrite(LF_LPWM, speed);
  analogWrite(LF_RPWM, 0);
  analogWrite(LB_LPWM, speed);
  analogWrite(LB_RPWM, 0);
}

void backward(int speed)
{
  analogWrite(RF_LPWM, 0);
  analogWrite(RF_RPWM, speed);
  analogWrite(RB_LPWM, 0);
  analogWrite(RB_RPWM, speed);
  analogWrite(LF_LPWM, 0);
  analogWrite(LF_RPWM, speed);
  analogWrite(LB_LPWM, 0);
  analogWrite(LB_RPWM, speed);
}

void left(int speed)
{
  analogWrite(RF_LPWM, 0);
  analogWrite(RF_RPWM, speed);
  analogWrite(RB_LPWM, 0);
  analogWrite(RB_RPWM, speed);
  analogWrite(LF_LPWM, 0);
  analogWrite(LF_RPWM, 0);
  analogWrite(LB_LPWM, 0);
  analogWrite(LB_RPWM, 0);
}

void right(int speed)
{
  analogWrite(RF_LPWM, 0);
  analogWrite(RF_RPWM, 0);
  analogWrite(RB_LPWM, 0);
  analogWrite(RB_RPWM, 0);
  analogWrite(LF_LPWM, speed);
  analogWrite(LF_RPWM, 0);
  analogWrite(LB_LPWM, speed);
  analogWrite(LB_RPWM, 0);
}

void sharpLeft(int speed)
{
  analogWrite(RF_LPWM, 0);
  analogWrite(RF_RPWM, speed);
  analogWrite(RB_LPWM, 0);
  analogWrite(RB_RPWM, speed);
  analogWrite(LF_LPWM, speed);
  analogWrite(LF_RPWM, 0);
  analogWrite(LB_LPWM, speed);
  analogWrite(LB_RPWM, 0);
}

void sharpRight(int speed)
{
  analogWrite(RF_LPWM, speed);
  analogWrite(RF_RPWM, 0);
  analogWrite(RB_LPWM, speed);
  analogWrite(RB_RPWM, 0);
  analogWrite(LF_LPWM, 0);
  analogWrite(LF_RPWM, speed);
  analogWrite(LB_LPWM, 0);
  analogWrite(LB_RPWM, speed);
}

void stop()
{
  analogWrite(RF_LPWM, 0);
  analogWrite(RF_RPWM, 0);
  analogWrite(RB_LPWM, 0);
  analogWrite(RB_RPWM, 0);
  analogWrite(LF_LPWM, 0);
  analogWrite(LF_RPWM, 0);
  analogWrite(LB_LPWM, 0);
  analogWrite(LB_RPWM, 0);
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  forward(0);
  Serial.println("Disconnected!.");    
}

void notify()
{
  if(PS4.LStickY() > 20)
  {
    forward(map(PS4.LStickY(),-127,127,-255,255));
  }
  else if(PS4.LStickY() < -20)
  {
    backward(map((-1) * PS4.LStickY(),-127,127,-255,255));
  }
  else if(PS4.RStickX() > 20)
  {
    sharpRight(map(PS4.RStickX(),-127,127,-255,255));
  }
  else if(PS4.RStickX() < -20)
  {
    sharpLeft(map((-1) * PS4.RStickX(),-127,127,-255,255));
  }
  else
  {
    stop();
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RB_LPWM, OUTPUT);
  pinMode(RB_RPWM, OUTPUT);
  pinMode(RF_LPWM, OUTPUT);
  pinMode(RF_RPWM, OUTPUT);
  pinMode(LB_LPWM, OUTPUT);
  pinMode(LB_RPWM, OUTPUT);
  pinMode(LF_LPWM, OUTPUT);
  pinMode(LF_RPWM, OUTPUT);
  

  analogWriteResolution(RF_LPWM, PWMResolution);
  analogWriteResolution(RF_RPWM, PWMResolution);
  analogWriteResolution(RB_LPWM, PWMResolution);
  analogWriteResolution(RB_RPWM, PWMResolution);
  analogWriteResolution(LF_LPWM, PWMResolution);
  analogWriteResolution(LF_RPWM, PWMResolution);
  analogWriteResolution(LB_LPWM, PWMResolution);
  analogWriteResolution(LB_RPWM, PWMResolution);

  analogWriteFrequency(RF_LPWM, PWMFreq);
  analogWriteFrequency(RF_RPWM, PWMFreq);
  analogWriteFrequency(RB_LPWM, PWMFreq);
  analogWriteFrequency(RB_RPWM, PWMFreq);
  analogWriteFrequency(LF_LPWM, PWMFreq);
  analogWriteFrequency(LF_RPWM, PWMFreq);
  analogWriteFrequency(LB_LPWM, PWMFreq);
  analogWriteFrequency(LB_RPWM, PWMFreq);
  
  

  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
