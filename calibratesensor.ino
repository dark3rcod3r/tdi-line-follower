#define numSensors 4

int sensorPins[numSensors] = {A0, A1, A2, A3};

//converts analog 0v-5v to digital val from 0-1023
//outputs low value for black and high value for white
//int minValues[numSensors] = {1023, 1023, 1023, 1023};   
//int maxValues[numSensors] = {0, 0, 0, 0};
//int thresholds[numSensors];


int minValues[numSensors] = {66, 75, 82, 124}
int maxValues[numSensors] = {74, 189, 251, 160}
float sensorDistances = [numSensors] = {-40, -9, 9, 40}  //sensor distrances from middle of robot 




float linePosition(){    //returns a float
  
  long weightedSum = 0;
  long totalReading = 0;

  //reads sensor values
  for (int i = 0; i < numSensors; i++){
      int rawValue = analogRead(sensorPins[i]);   //reads each sensor
      int mappedReading = map(rawReading, minValues, maxValues, 1000,0);  //scales on a range from 0-1000

      weightedSum += (long)mappedReading * sensorDistances[i]
      totalReading += mappedReading;
    }

    
    if (totalReading == 0) return 0;  //doesnt divide by zero

    return (float) weightedSum/totalReading;   //returns position relative to center

}



void setup() {
  Serial.begin(9600);

}

void loop() {
  
  //tells you position of the centerline relative to the robot
  float position = linePosition();
  Serial.print("Line position: ");
  Serial.println(position);
  delay(100);

  }





  // void calculateThreshold(){

  //   for(int i = 0; i < numSensors; i++){
  //     thresholds[i] = (minValues[i] + maxValues[i]) /2;
  //     Serial.println(thresholds[i]);
  //   }
  //    delay(1000);
  // }


// // Updates min/max calibration values
    //     if (sensorValue < minValues[i]) minValues[i] = sensorValue;
    //     if (sensorValue > maxValues[i]) maxValues[i] = sensorValue;
    // }

    // //Prints calibrated values every 1 second

    // static unsigned long lastPrintTime = 0;    //positive variable used for millis() timing
    // if (millis() - lastPrintTime > 1000) {
    //     lastPrintTime = millis();
    //     Serial.println("Calibration Data:");

    //     //prints value for each sensor
    //     for (int i = 0; i < numSensors; i++) {
    //         Serial.print("Sensor ");
    //         Serial.print(i);
    //         Serial.print(": Min=");
    //         Serial.print(minValues[i]);
    //         Serial.print(" Max=");
    //         Serial.println(maxValues[i]);
    //     }

    //     Serial.println("Keep moving the robot...");  //repeats
