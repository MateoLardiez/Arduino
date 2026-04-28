int LED_ROJO = 3;       // E  (root)
int LED_AMARILLO = 6;   // D
int LED_VERDE = 9;      // A

// Tempo: ~94 BPM  ->  1 beat ≈ 640 ms
const int SIXTEENTH = 160;   // duración de una nota corta
const int EIGHTH    = 320;
const int QUARTER   = 640;

// Helper: enciende un LED durante "ms" milisegundos y lo apaga
void hit(int pin, int ms) {
  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
}

void rest(int ms) {
  delay(ms);
}

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  // ----- Frase 1:  E . . .   E D . A -----
  hit(LED_ROJO, QUARTER);          // E (largo)
  rest(QUARTER + EIGHTH);          // silencio dramático

  hit(LED_ROJO, SIXTEENTH);        // E
  hit(LED_AMARILLO, SIXTEENTH);    // D
  rest(SIXTEENTH);
  hit(LED_VERDE, EIGHTH);          // A

  rest(EIGHTH);

  // ----- Frase 2:  E . . .   E D A E -----
  hit(LED_ROJO, QUARTER);          // E
  rest(QUARTER + EIGHTH);

  hit(LED_ROJO, SIXTEENTH);        // E
  hit(LED_AMARILLO, SIXTEENTH);    // D
  hit(LED_VERDE, SIXTEENTH);       // A
  hit(LED_ROJO, EIGHTH);           // E (cierre)

  rest(QUARTER);                   // respiro antes de repetir el riff
}

void simple_loop() {
  digitalWrite(LED_ROJO, HIGH); // Prenderlo
  delay(200);
  digitalWrite(LED_AMARILLO, HIGH);
  delay(200);
  digitalWrite(LED_VERDE, HIGH);
  delay(200);
  digitalWrite(LED_ROJO, LOW); // Apagarlo
  delay(200);
  digitalWrite(LED_AMARILLO, LOW);
  delay(200);
  digitalWrite(LED_VERDE, LOW);

}

