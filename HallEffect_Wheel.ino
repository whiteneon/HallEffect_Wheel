
int led = 13;
int hall = 3;
int reading = 0;
int counter = 0;
int prevcounter = 0;
int prevmillis = 0;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(hall, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, interrupt_handler, RISING);
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  //reading = digitalRead(hall);
  //digitalWrite(led, !reading);
  prevmillis = millis();
  prevcounter = counter;
  delay(5000);
  prevmillis = millis() - prevmillis;
  prevcounter = counter - prevcounter;
  if (prevcounter > 0) {
    //We received pulses....print time elapsed and number of pulses
    Serial.print(prevmillis);
    Serial.print(":");
    Serial.println(prevcounter);
  }
  //Serial.println(reading);
}

void interrupt_handler() {
  counter++;
  if (digitalRead(led) == HIGH) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}
