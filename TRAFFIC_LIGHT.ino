  
int red = 7;
int calibrationTime = 30;
int yellow = 12;
int green = 8;
//int sensorinput = 3;
int threshold = 286;
int DA = A0;
int sensorvalue = 0;
int  t=10;
void setup(){
    
    //HIGH ! = LOW;
    Serial.begin(9600);
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    //digitalWrite(, LOW);
    Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++)
    {
      Serial.print(".");
      delay(300);
     }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
}
void loop(){
  

    changeLights();
    
}

void changeLights(){
    
    

    Serial.println("red light is ready to on");
    digitalWrite(yellow, HIGH);//low = high
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(3000);
    t = 10;
    
    while(t>0)
    {
      sensorvalue = analogRead(DA);
 
  Serial.println(sensorvalue,DEC );
  
  delay(300);
         
      Serial.println(sensorvalue,DEC);
      delay(400);
    if(sensorvalue > threshold){
      Serial.println("you are creating to much noise");
      Serial.println("then you have to wait more");
      //digitalWrite(yellow, LOW); 
      //digitalWrite(red, HIGH);
      //digitalWrite(green, LOW);
      delay(6000);
      t = 10;
      }
      delay(1000);
      Serial.println(t);
      t--;
     
      }
       Serial.println("you are not creating any kind of difference");
       Serial.println("then you can go");
       delay(300);
      Serial.println("here yellow light is ready to on ");
     digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    
    delay(3000);

    
    

    Serial.println("here green light is ready to on");
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    delay(3000);
}
