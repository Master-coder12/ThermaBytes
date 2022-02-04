//#include <Adafruit_MotorShield.h>
#include<Wire.h>
#include <Adafruit_MLX90614.h>



Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // using I2c Address 
//Adafruit_DCMotor *myMotor = AFMS.getMotor(1); // calling motor M1 
//Adafruit_StepperMotor *myMotor1 = AFMS.getStepper(200, 2);



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  mlx.begin();
// AFMS.begin();  // create with the default frequency 1.6KHz

// Set the speed to start, from 0 (off) to 255 (max speed)
//  myMotor->setSpeed(255);
//  myMotor->run(FORWARD);
  // turn on motor
//  myMotor->run(RELEASE);

//  myMotor1->setSpeed(10);  // 10 rpm   

  pinMode(4, OUTPUT); //This LED will light up when temperature is too high (green))
  pinMode(3, OUTPUT); //This LED will light up when temperature is too low (blue)
  pinMode(2, OUTPUT); //LED test heater (orange color)
  pinMode(6, OUTPUT); // heat port
  pinMode(7, OUTPUT); //water pump port

  digitalWrite(6, LOW); //everything off 
  digitalWrite(7, LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t i;
  unsigned data[2];

 // Serial.print("*C\tObject= "); 
  Serial.print(mlx.readObjectTempC()); //Serial.println("*C");
  //Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();

  if(mlx.readObjectTempC() > 38.6){
    digitalWrite(4,HIGH);  //LED cool on
    digitalWrite(3,LOW);
    digitalWrite(6, LOW); //heat off
    digitalWrite(7, HIGH);
   // Serial.println("Cooling");
//  myMotor->run(FORWARD);
//  for (i=0; i<255; i++) {
//    myMotor->setSpeed(i);
//    delay(500);     
//  }
  }
  
  else if(mlx.readObjectTempC() < 36.5
  ){
//  myMotor1->step(100, FORWARD, SINGLE);
  digitalWrite(3,HIGH); //LED heat light up
  digitalWrite(6, HIGH); // turn heat on
  digitalWrite(4,LOW); 
  digitalWrite(7, LOW); //water pump off
 //Serial.println("Heating");
  }
  
  else {
    digitalWrite(6, LOW); //everything off 
    digitalWrite(7, LOW);
    digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     //Serial.println("Temp OK");
    
}
delay(60000);


}

