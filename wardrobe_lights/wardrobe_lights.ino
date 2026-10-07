#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_1 2
#define LED_2 3
#define LED_3 4

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  // Genera un impulso di 10 µs sul pin TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Misura la durata dell'eco
  long durata = pulseIn(ECHO_PIN, HIGH);

  // Calcola la distanza in cm
  float distanza = durata * 0.0343 / 2;
  Serial.print("distanza:");
  Serial.print(distanza);
  Serial.print("cm \n");

  if(distanza > 70){
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2,HIGH);
    digitalWrite(LED_3,HIGH);
  }else{
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2,LOW);
    digitalWrite(LED_3,LOW);
  }

  

  delay(500);
}