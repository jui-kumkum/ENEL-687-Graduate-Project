// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
int maxDistance = 20; // Maximum distance to detect in centimeters

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Check if distance is within the maximum limit
  if (distance <= maxDistance) {
    // Object detected within range, print distance
    Serial.print("Distance: ");
    Serial.println(distance);
  } else {
    // Object not detected within range, print out of range message
    Serial.println("Out of range");
  }

  // Add a small delay to improve readability of the output
  delay(1000); // Adjust as needed
}