#include <Servo.h>

// --- Configuración ---
const int PIN_SERVO  = 9;   // Pin de salida del servo
const int PIN_BOTON  = 2;   // Pin del botón (con resistencia pull-up interna)
const int ANGULO_PASO = 90; // Grados por paso

Servo miServo;

int anguloActual = 0;
bool botonActual  = 0; // Estado previo del botón (HIGH = no presionado)
void setup() {
  miServo.attach(PIN_SERVO);
  miServo.write(anguloActual); // Posición inicial: 0°

  pinMode(PIN_BOTON, INPUT_PULLUP); // Activa la resistencia pull-up interna

  Serial.begin(9600);
  Serial.println("Servo iniciado en 0 grados.");
}

void loop() {
  bool botonActual = digitalRead(PIN_BOTON);


  // Detectar flanco de bajada: botón recién presionado (HIGH -> LOW)
  if (botonActual == HIGH) {
    anguloActual = (anguloActual + ANGULO_PASO) % 360;
    int anguloEscrito = anguloActual;

    miServo.write(anguloEscrito);

    Serial.print("Moviendo a: ");
    Serial.print(anguloActual);
    Serial.println(" grados");

    delay(500); // Pequeño debounce para evitar lecturas falsas
//    botonAnterior = botonActual;
  }
}
