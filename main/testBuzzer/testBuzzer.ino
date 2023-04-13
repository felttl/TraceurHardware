
void setup(){
	
	pinMode(9, OUTPUT);

	
}
void loop(){
  // 
  //analogWrite(9, 255);

  int sonPercu = 0;

  digitalWrite(9, HIGH); // 1 clic
  delay(sonPercu);
  digitalWrite(9, LOW);
  delay(sonPercu);    

}


