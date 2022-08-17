int dirA = 2;
int pwmA = 3;
//--//
int dirB = 4;
int pwmB = 5;
//--//
bool direction = false;

int left, right;

int val;
int numL = 0, numR = 0;
int firstChar;
bool isRightUp = false;
bool isLeftUp = false;

void setup() {
  Serial.begin(9600);

  pinMode(dirA, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(pwmB, OUTPUT);
}

void loop() {
  //When not moving it should hold so no need to fire motor
  //No motor encoder so you have to move it like you would the hand drone
 
  /* Control Instructions
   * - If hand moves up (past thresh) spin the motor really fast
   * - If hand returns below thresh, unwind it
   * - The motor only moves for like 1-2 seconds
   * - This way the motor winds and unwinds equalish amounts, plus
   *   you just gesture up to talk and the arm moves up.
   *   This does mean though that the arm won't move tiny amounts in the air
   */

  if (Serial.available()) {
    val = Serial.read();
  }

  if (val == '1') {
    digitalWrite(dirA, HIGH);
    analogWrite(pwmA, 100);
    delay(500);
    digitalWrite(pwmA, LOW);
    delay(300);
  } else if (val == '2') {
    digitalWrite(dirA, LOW);
    analogWrite(pwmA, 100);
    delay(500);
    digitalWrite(pwmA, LOW);
    delay(300);
  } else if (val == '3') {
    digitalWrite(pwmA, LOW);
    delay(10);
  } else if (val == 'A') {
    digitalWrite(dirB, HIGH);
    analogWrite(pwmB, 100);
    delay(500);
    digitalWrite(pwmB, LOW);
    delay(300);
  } else if (val == 'B') {
    digitalWrite(dirB, LOW);
    analogWrite(pwmB, 100);
    delay(500);
    digitalWrite(pwmB, LOW);
    delay(300);
  } else if (val == 'C') {
    digitalWrite(pwmB, LOW);
    delay(10);
  }




}
