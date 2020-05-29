
//defines pins numbers:
int V=11;

int trigPin1 = 10;
int echoPin1 = 9;
int trigPin2 = 8;
int echoPin2 = 7;
int trigPin3 = 6;
int echoPin3 = 5;
const int DIO_buzzer=4;
const int InfraPin=2;
int Obstacle= HIGH;
// defines variables
long duration;
float distance1, distance2,distance3;


void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(InfraPin,INPUT);
  pinMode(V,OUTPUT);
Serial.begin(9600);
}
//fonction sert à calculer les distances 1,2 et 3.
float calcul_distance(int trigPin,int echoPin){
  float distance;
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
  return distance;
}
void loop() {
Obstacle= digitalRead(InfraPin);
if(Obstacle==HIGH){
  tone(DIO_buzzer,500,100);
  delay(50);
}
//ULTRASON1:
distance1=calcul_distance(trigPin1,echoPin1);
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
if(distance1>=1 && distance1<20){
  tone(DIO_buzzer,500,100);
  delay(50);
}else if(distance1>=20 && distance1<50){
  tone(DIO_buzzer,500,100);
  delay(500);
}else if(distance1>=50 && distance1<100){
  tone(DIO_buzzer,500,100);
  delay(1000);
}


//ULTRASON 2:
distance2=calcul_distance(trigPin2,echoPin2);
Serial.print("Distance2: ");
Serial.println(distance2);
if(distance2>=1 && distance2<20){
  tone(DIO_buzzer,500,100);
  delay(50);
}else if(distance2>=20 && distance2<50){
  tone(DIO_buzzer,500,100);
  delay(500);
}else if(distance2>=50 && distance2<100){
  tone(DIO_buzzer,500,100);
  delay(1000);
}

//ULTRASON 3:
distance3=calcul_distance(trigPin3,echoPin3);
// Prints the distance on the Serial Monitor
Serial.print("Distance3: ");
Serial.println(distance3);
if(distance3>=1 && distance3<20){
  tone(DIO_buzzer,500,100);
  delay(50);
}else if(distance3>=20 && distance3<50){
  tone(DIO_buzzer,500,100);
  delay(500);
}else if(distance3>=50 && distance3<100){
  tone(DIO_buzzer,500,100);
  delay(1000);
}


}
