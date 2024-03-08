// OLED Setup (Copied from CPR Lab Handout)
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_ADDRESS 0x3C
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, OLED_RESET);

// Pin definitions
const int trigPinLR = 2;  // Trigger pin for US-100 Ultrasonic Sensor
const int echoPinLR = 3;  // Echo pin for US-100 Ultrasonic Sensor
const int ledPinG = 13;   // Pin for the green LED
const int ledPinR = 12;   // Pin for the red LED

const int trigPinFB = 5;
const int echoPinFB = 6;
const int ledPinB = 9;
const int ledPinA = 8;

// Threshold values for distance detection
const int rightThreshold = 15;   // Distance (in cm) to register a "right" indication (green LED)
const int leftThreshold = 5;     // Distance (in cm) to register a "left" indication (red LED)
const int forwardThreshold = 5;  // Distance (in cm) to register a "forward" indication (amber LED)
const int backThreshold = 15;    // Distance (in cm) to register a "back" indication (blue LED)

// The following accounts for when head moves out of range of the sensor. Prevents improper display of direction
const int maxDist = 50; 
const int maxRange = 150;  // Distance (in cm) that will prompt user to "Move into range" if exceeded

// String definition for OLED Efficiency
String lastDirection = "";

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 bps
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);  // Initialize serial communication with the OLED display
  display.clearDisplay();                               // Clear buffer

  initPins();  // Call the function to initialize pin modes
}

void loop() {
  int distanceLR = measureDistance(trigPinLR, echoPinLR);  
  int distanceFB = measureDistance(trigPinFB, echoPinFB);  
  updateLEDs(distanceLR, distanceFB);                      
  
  // Print distances to the serial monitor
  Serial.print("LR Distance: ");
  Serial.print(distanceLR);
  Serial.print(" cm and FB Distance: ");
  Serial.print(distanceFB);
  Serial.println(" cm");

  delay(500);  // Delay before the next measurement cycle to reduce sensor noise
}

void initPins() {
  // Set pin modes for ultrasonic sensor and LEDs along the LR axis
  pinMode(trigPinLR, OUTPUT);  // Set the trigger pin as output for left/right
  pinMode(echoPinLR, INPUT);   // Set the echo pin as input for left/right
  pinMode(ledPinR, OUTPUT);    // Set the red LED pin as output
  pinMode(ledPinG, OUTPUT);    // Set the green LED pin as output

  // Set pin modes for ultrasonic sensor and LEDs along the FB axis
  pinMode(trigPinFB, OUTPUT);  // Set the trigger pin as output for front/back
  pinMode(echoPinFB, INPUT);   // Set the echo pin as input for front/back
  pinMode(ledPinB, OUTPUT);    // Set the blue LED pin as output
  pinMode(ledPinA, OUTPUT);    // Set the amber LED pin as output
}

int measureDistance(int trigPin, int echoPin) {
  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // Ensure clean high pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // Send 10us high pulse
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the duration of the echo
  int distance = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and return)
  return distance;                      // Return the calculated distance
}

void updateLEDs(int distanceLR, int distanceFB) {
  String direction = "";  // Initialize an empty direction string

  // If both distances are greater than maxRange, display "Move into range"
  if (distanceLR > maxRange && distanceFB > maxRange) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, DISPLAY_HEIGHT / 2 - 10);  // Adjust vertical position
    display.println("Move into range");
    display.display();
    return;
  }

  // Determine Left/Right direction
  if (distanceLR <= leftThreshold) {
    digitalWrite(ledPinR, HIGH);
    direction += "Left";
  } else if (distanceLR >= rightThreshold && distanceLR <= maxDist) {
    digitalWrite(ledPinG, HIGH);
    direction += "Right";
  } else {
    // Turn off left and right LEDs if no condition is met
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, LOW);
  }

  // Add space between directions if necessary
  if (direction.length() > 0) {
    direction += " ";
  }

  // Determine Front/Back direction
  if (distanceFB <= forwardThreshold) {
    digitalWrite(ledPinA, HIGH);
    direction += "Front";
  } else if (distanceFB >= backThreshold && distanceFB <= maxDist) {
    digitalWrite(ledPinB, HIGH);
    direction += "Back";
  } else {
    // Turn off front and back LEDs if no condition is met
    digitalWrite(ledPinA, LOW);
    digitalWrite(ledPinB, LOW);
  }

  // If no direction is determined, assume center
  if (direction.length() == 0) {
    direction = "Center";
  }

  displayDirection(direction);
}




void displayDirection(String direction) {
  // Only update the direction if it has changed
  if (direction != lastDirection) {
    display.clearDisplay();
    display.setTextSize(2);  // Set text size to 2, you can adjust this value for larger or smaller text
    display.setTextColor(SSD1306_WHITE);

    // Calculate the position to center the text horizontally
    int textWidth = direction.length() * 6 * 2;  // 6 pixels per character, multiplied by text size
    int xPos = (DISPLAY_WIDTH - textWidth) / 2;  // Calculate the x position to center the text

    display.setCursor(xPos, DISPLAY_HEIGHT / 2 - 20);  // Set the cursor position to center horizontally and vertically
    display.println(direction);

    display.display();

    lastDirection = direction;  // Update last direction
  }
}