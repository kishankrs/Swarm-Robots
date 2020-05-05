#define B1 4
#define B2 5
#define B3 6
#define B4 7
void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT); 
  pinMode(11,OUTPUT);
  pinMode(B1,OUTPUT);
  pinMode(B2,OUTPUT);
  pinMode(B3,OUTPUT);
  pinMode(B4,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

  void moveRobot(String motion)
  {
    if(motion == "Forward")
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      Serial.println("Forward");
    }

     if(motion == "Backward")
    {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      Serial.println("Backward");
    }

     if(motion == "Right")
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);   
      digitalWrite(11,HIGH);
      Serial.println("Left");

    }

     if(motion == "Left")
    {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      Serial.println("Right");
    }

     if(motion == "Stop")
    {
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      Serial.println("Stop");
    }
    
   }



void loop() {
  // put your main code here, to run repeatedly:
  int Right = analogRead(A0);//reads values from pin A0 and stores in Right
  int Left = analogRead(A1);//reads values from pin A1 and stores in Left
  //Serial.print("Value of Right sensor is" + String(Right));
  //Serial.print("\t");
  //Serial.println("Value of Left sensor is" + String(Left));
  //delay(1000);
  if((Right > 600)&&(Left > 600))//both sensor detects white surface
  {
    moveRobot("Forward");
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
  if((Right < 600)&&(Left < 600))//both sensor detects black line
  {
    moveRobot("Stop");
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }

  if((Right < 600)&&(Left > 600))//Right sensor detects black line and left sensor white surface
  {
    moveRobot("Right");
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   if((Right > 600)&&(Left < 600))//Right sensor detects white surface and left sensor black line
  {
    moveRobot("Left");
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }
}
