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

// ports de branchements sur la carte arduino
int trigPin = 7;    // TRIG pin
int echoPin = 8;    // ECHO pin
int buzzerPin = 9;  // buzzer output

float duration_us, distance_cm;
// initialisation 
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
  // ajuster la fréquence en finction du son
  float freq = sonPercu;
  Serial.print("freq :");
  Serial.print(freq);
  Serial.print("\n");
  digitalWrite(buzzerPin, HIGH); // 1 clic
  delay(freq);
  digitalWrite(buzzerPin, LOW); // son
  delay(freq);  
}
/// @brief affiche les données
void affichage(float freq, float distance_cm){
  // affichage nb tours
    Serial.print("nombre de tours: ");
    Serial.print((int)(freq));
    Serial.print("\n");  
    // affichage distance
    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");    
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  // mesure de la durée de la pulsation 
  duration_us = pulseIn(echoPin, HIGH);

  // calcul de la distance
  distance_cm = 0.017 * duration_us;
  // distance entre 2 et 400 cm (2000 cm lorsque les données sotn mal captées)
  if (distance_cm < 410.0 && distance_cm > 2.0){
    // boucle pour jouer une intensité sonore en fonction de la distance
    for (int i=0;i<(int)((400-distance_cm)/40);i++){
        affichage((400-distance_cm)/40, distance_cm);
        Buzzer(distance_cm);
    }
  } else {
    Serial.print("bad value (out of range)\n");
  }

  // 500ms = 2 times/seconds = 0.5 s
  // latence entre chaque ondes captées
  delay(300);
}



