#define ENA 13   // right motor PWM
#define IN1 12
#define IN2 11
#define ENB 8  // leftt motor PWM
#define IN3 10
#define IN4 9

int sensorPins[4] = {A0, A1, A2, A3};
int sensorMin[4] = {66, 75, 82, 124};
int sensorMax[4] = {74, 189, 251, 160};
float sensorPositions[4] = {-40.0, -9.0, 9.0, 40.0};

int baseSpeed = 130;
float Kp = 0.75;          // Starting Kp value
float KpIncrement = 0.5; // Increase per cycle
float maxKp = 5.0;       // Maximum Kp to test
unsigned long testDuration = 5000; // Test time per Kp (ms)
unsigned long lastTestTime = 0;

void setupMotors() {
  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  digitalWrite(IN1, leftSpeed >= 0); digitalWrite(IN2, leftSpeed < 0);
  digitalWrite(IN3, rightSpeed >= 0); digitalWrite(IN4, rightSpeed < 0);
  analogWrite(ENA, constrain(abs(leftSpeed), 0, 255));
  analogWrite(ENB, constrain(abs(rightSpeed), 0, 255));
}

float calculateLinePosition() {
  long weightedSum = 0, totalReading = 0;
  for (int i = 0; i < 4; i++) {
    int reading = analogRead(sensorPins[i]);
    int mappedReading = map(reading, sensorMin[i], sensorMax[i], 1000, 0);
    weightedSum += (long)mappedReading * sensorPositions[i];
    totalReading += mappedReading;
  }
  return totalReading ? (float)weightedSum / totalReading : 0;
}

void setup() {
  Serial.begin(9600);
  setupMotors();
  lastTestTime = millis();
  Serial.println("Starting Kp tuning...");
}

void loop() {
  float position = calculateLinePosition();
  float error = -position;
  int correction = Kp * error;

  int leftSpeed = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;
   setMotorSpeeds(baseSpeed, baseSpeed);

  // Print data for analysis
  Serial.print("Kp: "); Serial.print(Kp);
  Serial.print(" | Error: "); Serial.print(error);
  // Serial.print(" | Left: "); Serial.print(leftSpeed);
  // Serial.print(" | Right: "); Serial.println(rightSpeed);

  // // Increase Kp after testDuration
  // if (millis() - lastTestTime > testDuration) {
  //   Kp += KpIncrement;
  //   lastTestTime = millis();
  //   Serial.println("-----------------------------");
  //   Serial.print("Increasing Kp to: "); Serial.println(Kp);

  //   if (Kp > maxKp) {
  //     Serial.println("Kp tuning complete.");
  //     while (true); // Stop after maxKp reached
    }
  

  //delay(2000); // Small delay for stability

