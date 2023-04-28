/*
 * Created by ArduinoGetStarted, https://arduinogetstarted.com
 *
 * Arduino - Ultrasonic Sensor HC-SR04
 *
 * Wiring: Ultrasonic Sensor -> Arduino:
 * - VCC  -> 5VDC
 * - TRIG -> Pin 9
 * - ECHO -> Pin 8
 * - GND  -> GND
 *
 * Tutorial is available here: https://arduinogetstarted.com/tutorials/arduino-ultrasonic-sensor
 */

int trigPin = 7;    // TRIG pin
int echoPin = 8;    // ECHO pin
int buzzerPin = 9;  // buzzer output

float duration_us, distance_cm;

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // buzzer conf/init
	pinMode(buzzerPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);

}
/// @brief calcule l'intensité du son en fonction de la distance perçue (d/2) le max est 205 donc et le min est 1)
void Buzzer(float sonPercu){

  float freq = sonPercu;
  Serial.print("freq :");
  Serial.print(freq);
  Serial.print("\n");
  digitalWrite(buzzerPin, HIGH); // 1 clic
  delay(freq);
  digitalWrite(buzzerPin, LOW);
  delay(freq);  
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;
  // distance entre 2 et 400 cm (2000 cm or more is false value)
  if (distance_cm < 410.0 && distance_cm > 2.0){
    // print the value to Serial Monitor

    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    // buzzer

    for (int i=0;i<(int)(10+(400-distance_cm)/20);i++){
    Serial.print("nombre de tours: ");
    Serial.print((int)(10+(400-distance_cm)/20));
    Serial.print("\n");      
        Buzzer(distance_cm);
    }
  } else {
    Serial.print("bad value (out of range)\n");
  }

  // 500ms = 2 times/seconds = 0.5 s
  delay(500);
}



