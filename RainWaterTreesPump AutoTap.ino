int rainSensor = A0;
int rainSensorState = 0;
int led = 13;
int treesPump = 12;
int waterPump = 11;
int tapPump = 13;

int watarLevalDetactor = A4;
int watarLevalDetactorState = 0;

int motorR = A1;
int motorL = A2;

int treeSensor = A3;
int treeSensorState = 0;

int irSensor = A5;
int irSensorState = 0;

int flag = 0;
int flagA = 0;
void setup(){

  pinMode(rainSensor,INPUT);
  
  pinMode(treeSensor,INPUT);
  
  pinMode(led,OUTPUT);

  pinMode(motorR,OUTPUT);
  pinMode(motorL,OUTPUT);
  
  pinMode(treesPump,OUTPUT);
  pinMode(waterPump,OUTPUT);
  pinMode(tapPump,OUTPUT);

  pinMode(watarLevalDetactor,INPUT);
  pinMode(irSensor,INPUT);
  
  
  Serial.begin(9600);

  
}

void loop(){

/////Rain Water GATE
  rainSensorState = analogRead(rainSensor);
  

if(rainSensorState >= 300 && flag == 0){
  flag = 1;
  flagA = 0;
  

  digitalWrite(motorR,HIGH);
  digitalWrite(motorL,LOW);
  delay(1000);
  digitalWrite(motorR,LOW);
  digitalWrite(motorL,LOW);
}

if(rainSensorState < 290 && flagA == 0){
  flag = 0;
  flagA = 1;
  

  digitalWrite(motorR,LOW);
  digitalWrite(motorL,HIGH);
  delay(1000);
  digitalWrite(motorR,LOW);
  digitalWrite(motorL,LOW);
}

/////// Trees sensor

treeSensorState = analogRead(treeSensor);

if(treeSensorState >= 500){
  digitalWrite(treesPump,HIGH);
  delay(100);
  
}

if(treeSensorState < 490){
  digitalWrite(treesPump,LOW);
  
}




////watarLevalDetactor

watarLevalDetactorState = analogRead(watarLevalDetactor);

if(watarLevalDetactorState > 500){
  digitalWrite(waterPump,LOW);
}

if(watarLevalDetactorState < 490){
  digitalWrite(waterPump,HIGH);
  delay(100);
}


//// IR Sensor for water TAP

irSensorState = analogRead(irSensor);

if(irSensorState >= 300){  
  digitalWrite(tapPump,LOW);
  
}

if(irSensorState < 290){
  digitalWrite(tapPump,HIGH);
  delay(500);
  
}

Serial.println(irSensorState);
//delay(300);  
}
