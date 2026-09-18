// Pin Definitions
const int SENSOR_PIN = A0;
const int LED_PIN_9 = 9;
const int LED_PIN_10 = 10;

int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  
  // Set LED pins as outputs
  pinMode(LED_PIN_9, OUTPUT);
  pinMode(LED_PIN_10, OUTPUT);
}

void loop() {
  // Read analog value from sensor (0 to 1023)
  sensorValue = analogRead(SENSOR_PIN);
  
  // Print sensor reading to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  // Control outputs based on threshold
  if (sensorValue < 200) {
    digitalWrite(LED_PIN_10, HIGH); // Turn ON LED at Pin 10 when value < 200
    digitalWrite(LED_PIN_9, LOW);   // Turn OFF LED at Pin 9
  } else {
    digitalWrite(LED_PIN_10, LOW);  // Turn OFF LED at Pin 10 when value >= 200
    digitalWrite(LED_PIN_9, HIGH);  // Turn ON LED at Pin 9
  }
  
  delay(100); // Small delay to stabilize readings and prevent Serial buffer flood
}