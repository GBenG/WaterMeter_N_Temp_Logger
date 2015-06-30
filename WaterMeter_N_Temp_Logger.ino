int echoPin1 = 9;
int trigPin1 = 8;
int echoPin2 = A1;
int trigPin2 = A0;
int sensorValue = 0;             // значение / 5.8
int newSensorValue = 0;          // значение / 5.8
int duration = 0;                // считанное значение
const byte averageFactor = 5;    // коэффициент сглаживания показаний (0 = не сглаживать)
                                 // чем выше, тем больше "инерционность"



void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
} 

void loop() { 
  
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW); 
  
  duration = pulseIn(echoPin1, HIGH);
  sensorValue = duration / 5.8; 
 /* newSensorValue = duration / 5.8;
  

  if (averageFactor > 0)        // усреднение показаний для устранения "скачков"
  {      
    sensorValue = (sensorValue * (averageFactor - 1) + newSensorValue) / averageFactor;  
    // <новое среднее> = (<старое среднее>*4 + <текущее значение>) / averageFactors я тут немного поправил
  } else {
    sensorValue=newSensorValue; // не делаем усреднений, что прочитали то и считаем выводом
  }
*/
  Serial.print("HC1 = ");
  Serial.print(sensorValue);
  Serial.print(" / ");

  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW); 
  
  duration = pulseIn(echoPin2, HIGH); 
 // newSensorValue = duration / 5.8;
  sensorValue = duration / 5.8;
/*
  if (averageFactor > 0)        // усреднение показаний для устранения "скачков"
  {      
    sensorValue = (sensorValue * (averageFactor - 1) + newSensorValue) / averageFactor;  
    // <новое среднее> = (<старое среднее>*4 + <текущее значение>) / averageFactors я тут немного поправил
  } else {
    sensorValue=newSensorValue; // не делаем усреднений, что прочитали то и считаем выводом
  }
  */
  Serial.print("HC2 = ");
  Serial.print(sensorValue);
  Serial.write(13);
  
  delay(1000);
}

  

