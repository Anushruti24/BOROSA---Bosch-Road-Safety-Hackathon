#define trigPin1 9
#define echoPin1 10
#define trigPin2 3
#define echoPin2 4
#define trigPin3 13
#define echoPin3 2
#define trigPin4 11
#define echoPin4 12
#define trigPin5 8
#define echoPin5 7
#define trigPin6 5
#define echoPin6 6

// Define buzzer pin
#define buzzerPin A0

void setup() {
  Serial.begin(9600);
  
  // Ultrasonic sensor pins as outputs and inputs
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);
  
  // Buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read distances from all sensors
  int distance1 = readDistance(trigPin1, echoPin1);
  int distance2 = readDistance(trigPin2, echoPin2);
  int distance3 = readDistance(trigPin3, echoPin3);
  int distance4 = readDistance(trigPin4, echoPin4);
  int distance5 = readDistance(trigPin5, echoPin5);
  int distance6 = readDistance(trigPin6, echoPin6);
  
  // Check for any object within 0 to 20 cm
  if ((distance1 >= 0 && distance1 <= 20) ||
      (distance2 >= 0 && distance2 <= 20) ||
      (distance3 >= 0 && distance3 <= 20) ||
      (distance4 >= 0 && distance4 <= 20) ||
      (distance5 >= 0 && distance5 <= 20) ||
      (distance6 >= 0 && distance6 <= 20) ||
      (distance1 >= 0 && distance1 <= 20) && (distance2 >= 0 && distance2 <= 20)||
      (distance2 >= 0 && distance2 <= 20) && (distance3 >= 0 && distance3 <= 20)||
      (distance4>= 0 && distance4 <= 20) && (distance5 >= 0 && distance5 <= 20)||
      (distance5 >= 0 && distance5 <= 20) && (distance6 >= 0 && distance6 <= 20) ){
    activateBuzzer(distance1, distance2, distance3, distance4, distance5, distance6);
    Serial.println("Buzzer activated!");
  } 

  if ((distance1 > 20 && distance1 <= 30) ||
      (distance2 > 20 && distance2 <= 30) ||
      (distance3 > 20 && distance3 <= 30) ||
      (distance4 > 20 && distance4 <= 30) ||
      (distance5 > 20 && distance5 <= 30) ||
      (distance6 > 20 && distance6 <= 30) ||
      (distance1 > 20 && distance1 <= 30) && (distance2 > 20 && distance2 <= 30)||
      (distance2 > 20 && distance2 <= 30) && (distance3 > 20 && distance3 <= 30)||
      (distance4 > 20 && distance4 <= 30) && (distance5 > 20 && distance5 <= 30)||
      (distance5 > 20 && distance5 <= 30) && (distance6 > 20 && distance6 <= 30)){
    deactivateBuzzer(distance1, distance2, distance3, distance4, distance5, distance6);
  } 

  
}

// Function to read distance from HC-SR04 ultrasonic sensor
int readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 58; // Convert pulse duration to distance in cm
}

// Function to activate buzzer alarm
void activateBuzzer(int distance1, int distance2, int distance3, int distance4, int distance5, int distance6) {
  digitalWrite(buzzerPin, LOW); // Turn on buzzer
  Serial.print("Buzzer activated by: ");

  if ((distance1 >= 0 && distance1 <= 20) && (distance2 >= 0 && distance2 <= 20)) {
    Serial.print("Sensor 1 (Distance: ");
    Serial.print(distance1);
    Serial.print("cm) ");
    Serial.print("Sensor 2 (Distance: ");
    Serial.print(distance2);
    Serial.print("cm) ");
    Serial.println("Angle: 70 degrees");
  }
  if ((distance2 >= 0 && distance2 <= 20) && (distance3 >= 0 && distance3 <= 20)) {
    Serial.print("Sensor 2 (Distance: ");
    Serial.print(distance2);
    Serial.print("cm) ");
    Serial.print("Sensor 3 (Distance: ");
    Serial.print(distance3);
    Serial.print("cm) ");
    Serial.println("Angle: 110 degrees");
  }
  if ((distance4 >= 0 && distance4 <= 20) && (distance5 >= 0 && distance5 <= 20)) {
    Serial.print("Sensor 4 (Distance: ");
    Serial.print(distance4);
    Serial.print("cm) ");
    Serial.print("Sensor 5 (Distance: ");
    Serial.print(distance5);
    Serial.print("cm) ");
    Serial.println("Angle: 250 degrees");
  }
  if ((distance5 >= 0 && distance5 <= 20) && (distance6 >= 0 && distance6 <= 20)) {
    Serial.print("Sensor 5 (Distance: ");
    Serial.print(distance5);
    Serial.print("cm) ");
    Serial.print("Sensor 6 (Distance: ");
    Serial.print(distance6);
    Serial.print("cm) ");
    Serial.println("Angle: 290 degrees");
  }

  if (distance1 >= 0 && distance1 <= 20) {
    Serial.print("Sensor 1 (Distance: ");
    Serial.print(distance1);
    Serial.print("cm) ");
    Serial.println("Angle: 50 degrees");
  }
  if (distance2 >= 0 && distance2 <= 20) {
    Serial.print("Sensor 2 (Distance: ");
    Serial.print(distance2);
    Serial.print("cm) ");
    Serial.println("Angle: 90 degrees");
  }
  if (distance3 >= 0 && distance3 <= 20) {
    Serial.print("Sensor 3 (Distance: ");
    Serial.print(distance3);
    Serial.print("cm) ");
    Serial.println("Angle: 130 degrees");
  }
  if (distance4 >= 0 && distance4 <= 20) {
    Serial.print("Sensor 4 (Distance: ");
    Serial.print(distance4);
    Serial.print("cm) ");
    Serial.println("Angle: 230 degrees");
  }
  if (distance5 >= 0 && distance5 <= 20) {
    Serial.print("Sensor 5 (Distance: ");
    Serial.print(distance5);
    Serial.print("cm) ");
    Serial.println("Angle: 270 degrees");
  }
  if (distance6 >= 0 && distance6 <= 20) {
    Serial.print("Sensor 6 (Distance: ");
    Serial.print(distance6);
    Serial.print("cm) ");
    Serial.println("Angle: 310 degrees");
  }

  delay(500);
  digitalWrite(buzzerPin, HIGH); // Turn on buzzer

}

void deactivateBuzzer(int distance1, int distance2, int distance3, int distance4, int distance5, int distance6) {
  digitalWrite(buzzerPin, HIGH); // Turn on buzzer
  
  if ((distance1 > 20 && distance1 <= 30) && (distance2 > 20 && distance2 <= 30)) {
    
    Serial.print("Sensor 1 (Distance: ");
    Serial.print(distance1);
    Serial.print("cm) ");
    Serial.print("Sensor 2 (Distance: ");
    Serial.print(distance2);
    Serial.print("cm) ");
    Serial.println("Angle: 70 degrees");
  }
  if ((distance2 > 20 && distance2 <= 30) && (distance3 > 20 && distance3 <= 30)) {

    Serial.print("Sensor 2 (Distance: ");
    Serial.print(distance2);
    Serial.print("cm) ");
    Serial.print("Sensor 3 (Distance: ");
    Serial.print(distance3);
    Serial.print("cm) ");
    Serial.println("Angle: 110 degrees");
  }
  if ((distance4 > 20 && distance4 <= 30) && (distance5 > 20 && distance5 <= 30)) {
  
    Serial.print("Sensor 4 (Distance: ");
    Serial.print(distance4);
    Serial.print("cm) ");
    Serial.print("Sensor 5 (Distance: ");
    Serial.print(distance5);
    Serial.print("cm) ");
    Serial.println("Angle: 250 degrees");
  }
  if ((distance5 > 20 && distance5 <= 30) && (distance6 > 20 && distance6 <= 30)) {
    Serial.print("Sensor 5 (Distance: ");
    Serial.print(distance5);
    Serial.print("cm) ");
    Serial.print("Sensor 6 (Distance: ");
    Serial.print(distance6);
    Serial.print("cm) ");
    Serial.println("Angle: 290 degrees");
  }

  if(distance1 > 20 && distance1 <= 30) 
  {
    Serial.print("Sensor 1 (Distance: ");
    Serial.print(distance1);
    Serial.print("cm) ");
    Serial.println("Angle: 50 degrees");
  }
  if(distance2 > 20 && distance2 <= 30) 
  {
    Serial.print("Sensor 2 (Distance: ");
    Serial.print(distance2);
    Serial.print("cm) ");
    Serial.println("Angle: 90 degrees");
  }
  if(distance3 > 20 && distance3 <= 30) 
  {
    Serial.print("Sensor 3 (Distance: ");
    Serial.print(distance3);
    Serial.print("cm) ");
    Serial.println("Angle: 130 degrees");
  }
  if(distance4 > 20 && distance4 <= 30) 
  {
    Serial.print("Sensor 4 (Distance: ");
    Serial.print(distance4);
    Serial.print("cm) ");
    Serial.println("Angle: 230 degrees");
  }
  if(distance5 > 20 && distance5 <= 30) 
  {
    Serial.print("Sensor 5 (Distance: ");
    Serial.print(distance5);
    Serial.print("cm) ");
    Serial.println("Angle: 270 degrees");
  }
  if(distance6 > 20 && distance6 <= 30) 
  {
    Serial.print("Sensor 6 (Distance: ");
    Serial.print(distance6);
    Serial.print("cm) ");
    Serial.println("Angle: 310 degrees");
  }


  delay(500); // Reduce delay between readings for faster detection


}
