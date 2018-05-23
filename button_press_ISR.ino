
int relayPin = 4; //attach relay to pin D4
int ledPin = 5; //attach relay to pin D5
int btn1Pin = 2; //attach relay to pin D2 (interrupt 0)
int btn2Pin = 3; //attach relay to pin D2 (interrupt 1)

volatile int btnValue1 = 0; //button state for button 1
volatile int btnValue2 = 0; //button state for button 2

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT); //initalize relay pin as output
  pinMode(ledPin, OUTPUT);  //initalize ledPin pin as output
  pinMode(btn1Pin, INPUT);  //initalize button1 pin as input
  pinMode(btn2Pin, INPUT);  //initalize button2 pin as input
  Serial.begin(9600);

  //attach interrupt for the various pins
  attachInterrupt(digitalPinToInterrupt(btn1Pin), pinEventLED, CHANGE);
  attachInterrupt(digitalPinToInterrupt(btn2Pin), pinEventRelay, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
 
}

void pinEventLED(){
  btnValue1 = digitalRead(btn1Pin); //read value from button 1
  digitalWrite(ledPin, btnValue1);
  
}

void pinEventRelay(){
   btnValue2 = digitalRead(btn2Pin); //read value from button 2
   Serial.println(btnValue2);
   digitalWrite(relayPin, btnValue2);
 
}

