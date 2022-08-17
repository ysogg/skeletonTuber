import processing.serial.*;
import de.voidplus.leapmotion.*;

LeapMotion leap;
Serial port;
boolean isRightUp = false;
boolean isLeftUp = false;
int convRight = 0, convLeft = 0;

void setup() {
  leap = new LeapMotion(this);
  
  // List all available ports.
  println(Serial.list());
   
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw() { //

background(0); //

//idk how to make this get both hands at once lol
for (Hand hand : leap.getHands()) {     
  pushMatrix();     
  float left = 0, right = 0;
  //String output;
  PVector pos = hand.getPalmPosition();
  if (hand.isLeft() == true) {
    left = pos.y;
    convLeft = int(left);
    
    if ( (convLeft < 50) && (isLeftUp == false) ) {
      isLeftUp = true;
      port.write('1');
    } else if ( (convLeft > 50) && (isLeftUp == true) ) {
      isLeftUp = false;
      port.write('2');
    } else {
      port.write('3');
    }
  } else if (hand.isRight() == true) {
    right = pos.y;
    convRight = int(right);
    
    if ( (convRight < 50) && (isRightUp == false) ) {
      isRightUp = true;
      port.write('A');
    } else if ( (convRight > 50) && (isRightUp == true) ) {
      isRightUp = false;
      port.write('B');
    } else {
      port.write('C');
    }
  }
  
  println("Left: " + convLeft + " | Right: " + convRight);  
  
  popMatrix();    
}}
