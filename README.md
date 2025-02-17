# tdi-line-follower


//right motor
int enaRight=5;
int in1=6;
int in2=7;

//left motor
int enbLeft=10;
int in3=8;
int in4=9;

int switch1 = 11;

int switchstate = 0;

//hellooooooo

void setup() {
  pinMode(enaRight, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enbLeft, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(switch1, INPUT);

}

void loop() {

switchstate = digitalRead(switch1);   //reads state


if (switch1 == HIGH) {


//right motor speed clkw
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enaRight, 255);

  //left motor speed clkw
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enbLeft, 255);

}

else if (switch1 == LOW){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 

}




}




