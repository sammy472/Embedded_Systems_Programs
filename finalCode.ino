//MotorA pins configuration,left motor
int enA = 11;
int IN1 = 12;
int IN2 = 13;
//MotorB pins configuration,right motor
int enB = 3;
int IN3 = 4;
int IN4 = 7;
//IR Sensors configuration
int left = 8;
int center = 9;
int right = 10;

//stop counter
int motorSpeed = 100;
void setup() {
  Serial.begin(9600);
  //MotorA
  pinMode(enA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  //MotorB
  pinMode(enB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //Sensors pinMode
  pinMode(left,INPUT);
  pinMode(center,INPUT);
  pinMode(right,INPUT);
}

void loop() {
  /*******stop the robot if the counter is equal to 5.If not move forward.********/
  if((digitalRead(left)==1) && (digitalRead(center)==1) && (digitalRead(right)==1)){
      forward();
  }
  /******move forward*********/
  if((digitalRead(left)==0) && (digitalRead(center)==0) && (digitalRead(right)==0)){forward();};
  if((digitalRead(left)==1) && (digitalRead(center)==0) && (digitalRead(right)==1)){forward();};
  if((digitalRead(left)==0) && (digitalRead(center)==1) && (digitalRead(right)==0)){forward();};
  /***********left-turn conditions*********/
  if((digitalRead(left)==1) && (digitalRead(right)==0)){turnLeft();};
  //if((digitalRead(left)==1) && (digitalRead(center)==0) && (digitalRead(right)==0)){turnLeft();};
  /**********right-turn conditions*********/
  if((digitalRead(left)==0) && (digitalRead(center)==1) && (digitalRead(right)==1)){turnRight();};
  if((digitalRead(left)==0) && (digitalRead(center)==0) && (digitalRead(right)==1)){turnRight();};
  
//Serial.println(analogRead(center));
//delay(1000);
}


void forward(){
  analogWrite(enA,motorSpeed);
  analogWrite(enB,motorSpeed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
};

void stopEngine(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
};
void turnLeft(){
  analogWrite(enA,80);
  analogWrite(enB,30);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
};
void turnRight(){
  analogWrite(enB,80);
  analogWrite(enA,30);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
