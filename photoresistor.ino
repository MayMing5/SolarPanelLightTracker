#include <Servo.h>
int ledPin = 2;
int count = 0;
int length = 10;
int vals[10] = {0};

Servo myservo;  // create servo object to control a servo

void setup() {
    Serial.begin(9600);
    pinMode(ledPin,  OUTPUT);
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    
    
}

void loop() {
    int avg;
    int val1;
    int value = analogRead(A0);

    Serial.println("Analog  Value: ");
    Serial.println(value);
    
    if (value > 650) {
        digitalWrite(ledPin, LOW);
    } else {
        digitalWrite(ledPin,  HIGH);
    }
    
    vals[count%length] = value;
    count += 1;
    for (int i=0;i<length; i++) {
      avg += vals[i]/length;
    };
    val1 = map(avg, 600, 720, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo.write(val1);                  // sets the servo position according to the scaled value

    Serial.println("avg: ");
    Serial.println(avg);
    delay(20);
}