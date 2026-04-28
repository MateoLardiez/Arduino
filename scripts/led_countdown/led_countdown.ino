int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  for (int i = 10; i >= 0; i--) {
    Serial.println(i);
    digitalWrite(ledPin, HIGH); // LED encendido
    delay(500);
    digitalWrite(ledPin, LOW);  // LED apagado
    delay(500);
  }
  Serial.println("¡Tiempo!");
  delay(3000);

}

void loop() {
}