#define SENSOR A0
#define RELAY 8
//Change thresh to suit physical calibration of microphone accordingly
const int thresh = 475;
int input = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
}

void loop() {
  input = analogRead(SENSOR);
  Serial.println(input);
  
  if (input > thresh) {
    digitalWrite(RELAY, HIGH);
    delay(100);
    digitalWrite(RELAY, LOW);
  } else {
    digitalWrite(RELAY, LOW);
  }
  

}
