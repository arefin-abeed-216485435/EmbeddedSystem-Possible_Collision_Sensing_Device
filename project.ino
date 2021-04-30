// All the constants are declared here

const int trig = 12; // This is the trigger port for ultrasonic sensor 1
const int echo = 13; // This is the echo port for ultrasonic sensor 1

const int trig2 = 22; // This is the trigger port for ultrasonic sensor 2
const int echo2 = 23; // This is the echo port for ultrasonic sensor 2

const int buzzer1 = 2; // This is the port for buzzer for ultrasonic sensor 1
const int buzzer2 = 3; // This is the port for buzzer for ultrasonic sensor 2

const int LED1 = 8; // This is LED 1 port for ultrasonic sensor 1
const int LED2 = 7; // This is LED 2 port for ultrasonic sensor 1
const int LED3 = 6; // This is LED 3 port for ultrasonic sensor 1
const int LED4 = 5; // This is LED 4 port for ultrasonic sensor 1
const int LED5 = 4; // This is LED 5 port for ultrasonic sensor 1

const int LED6 = 24; // This is LED 1 port for ultrasonic sensor 2
const int LED7 = 25; // This is LED 2 port for ultrasonic sensor 2
const int LED8 = 26; // This is LED 3 port for ultrasonic sensor 2
const int LED9 = 27; // This is LED 4 port for ultrasonic sensor 2
const int LED10 = 28; // This is LED 5 port for ultrasonic sensor 2

int distance = 0; // This is used to store the distance of the object from ultrasonic sensor 1

int distance2 = 0; // This is used to store the distance of the object from ultrasonic sensor 2

void setup() // This method is used to do the initial setup
{
  // The trigger and echo ports are initialized for ultrasonic sensor 1
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);

  // The trigger and echo ports are initialized for ultrasonic sensor 2
  pinMode(trig2 , OUTPUT);
  pinMode(echo2 , INPUT);
  
  pinMode(buzzer1,OUTPUT); // The buzzer for ultrasonic sensor 1 is initialized
  pinMode(buzzer2,OUTPUT); // The buzzer for ultrasonic sensor 2 is initialized

  // The LEDs for ultrasonic sensor 1 is initialized
  pinMode(LED1 , OUTPUT); 
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);

  // The LEDs for ultrasonic sensor 2 is initialized
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);
  pinMode(LED8 , OUTPUT);
  pinMode(LED9 , OUTPUT);
  pinMode(LED10 , OUTPUT);
  
  Serial.begin(9600); // A connection is being setup with the sensors and microcontroller

}

void loop()
{
    // This is used to store the distance of the object from ultrasonic sensor 1
    distance = measure(trig, echo); 
    // This is used to store the distance of the object from ultrasonic sensor 2
    distance2 = measure(trig2, echo2);
    
  // These conditions and codes are for ultrasonic sensor 1
  // This if-else statement is used to generate the alert when a object is closest
  if ( distance <= 10){
    digitalWrite(buzzer1,HIGH); // Buzzer is set active
    // The LEDs are lighted up
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    delay(50); // A short delay to show constant LED blinking and generate high beeping frequency
    // The LEDs are turned off
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    delay(50); // A short delay to show constant LED blinking and generate high beeping frequency
    // The LEDs are lighted up
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
  }
  
  // This if-else statement is used to generate the alert when a object is a little bit far
  if ( distance <= 20 && distance > 10)
  {
    // The LEDs are lighted up
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(buzzer1,HIGH); // Buzzer is set active
    delay(100); // A delay to get desired beeping frequency
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
    delay(100); // A delay to get desired beeping frequency
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
  }
  
  // This if-else statement is used to generate the alert when a object is a more far
  if ( distance <= 30 && distance > 20)
  {
    // The LEDs are lighted up
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(buzzer1,HIGH); // Buzzer is set active
    delay(200); // A delay to get desired beeping frequency
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
    delay(200); // A delay to get desired beeping frequency
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
  }

  // This if-else statement is used to generate the alert when a object is far
  if ( distance <= 40 && distance > 30)
  {
    // The LEDs are lighted up
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(buzzer1,HIGH); // Buzzer is set active
    delay(300); // A delay to get desired beeping frequency
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
    delay(300); // A delay to get desired beeping frequency
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
  }

  // This if-else statement is used to generate the alert when a object is farthest
  if ( distance <= 50 && distance > 40)
  {
    // The LED is lighted up
    digitalWrite(LED5, HIGH);
    digitalWrite(buzzer1,HIGH); // Buzzer is set active
    delay(400); // A delay to get desired beeping frequency
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
    delay(400); // A delay to get desired beeping frequency
  }
  else
  {
    // The LED is turned off
    digitalWrite(LED5, LOW);
    digitalWrite(buzzer1,LOW); // Buzzer is turned off
  }

  // These conditions are for ultrasonic sensor 2
  // This if-else statement is used to generate the alert when a object is closest
  if ( distance2 <= 10){
    digitalWrite(buzzer2,HIGH); // Buzzer is set active
    // The LEDs are lighted up
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED8, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
    delay(50); // A short delay to show constant LED blinking and generate high beeping frequency
    // The LEDs are turned off
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED10, LOW);
    delay(50); // A short delay to show constant LED blinking and generate high beeping frequency
    // The LEDs are lighted up
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED8, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED10, LOW);
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
  }

  // This if-else statement is used to generate the alert when a object is a little bit far
  if ( distance2 <= 20 && distance2 > 10)
  {
    // The LEDs are lighted up
    digitalWrite(LED7, HIGH);
    digitalWrite(LED8, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
    digitalWrite(buzzer2,HIGH); // Buzzer is set active
    delay(100); // A delay to get desired beeping frequency
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
    delay(100); // A delay to get desired beeping frequency
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED10, LOW);
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
  }

  // This if-else statement is used to generate the alert when a object is a more far
  if ( distance2 <= 30 && distance2 > 20)
  {
    // The LEDs are lighted up
    digitalWrite(LED8, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
    digitalWrite(buzzer2,HIGH); // Buzzer is set active
    delay(200); // A delay to get desired beeping frequency
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
    delay(200); // A delay to get desired beeping frequency
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED8, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED10, LOW);
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
  }

  // This if-else statement is used to generate the alert when a object is far
  if ( distance2 <= 40 && distance2 > 30)
  {
    // The LEDs are lighted up
    digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
    digitalWrite(buzzer2,HIGH); // Buzzer is set active
    delay(300); // A delay to get desired beeping frequency
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
    delay(300); // A delay to get desired beeping frequency
  }
  else
  {
    // The LEDs are turned off
    digitalWrite(LED9, LOW);
    digitalWrite(LED10, LOW);
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
  }

  // This if-else statement is used to generate the alert when a object is farthest
  if ( distance2 <= 50 && distance2 > 40)
  {
    // The LED is lighted up
    digitalWrite(LED10, HIGH);
    digitalWrite(buzzer2,HIGH); // Buzzer is set active
    delay(400); // A delay to get desired beeping frequency
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
    delay(400); // A delay to get desired beeping frequency
  }
  else
  {
    // The LED is turned off
    digitalWrite(LED10, LOW);
    digitalWrite(buzzer2,LOW); // Buzzer is turned off
  }
  }

  /* 
   *  This is a method which calculates the distance of any object from any ultrasonic sensor.
   *  It takes the trigger port and echo port and do some internal calculations to give the distance.
   */
  long measure(int trigger, int echo){
    
    long dur = 0; // This is used to store the time to travel from ultrasonic sensor to object and back

    // These three lines of codes is used to send a pulse to the object
    digitalWrite(trigger , HIGH); 
    delayMicroseconds(2);
    digitalWrite(trigger , LOW);

    // This line receives the pulse back from the object
    dur = pulseIn(echo,HIGH);
    return (dur/2) / 28.5; // This line does some calculation to return the distance of the object
  
  }
