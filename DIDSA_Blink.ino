// Allocate names to the pins to which the devices are connected
const int ledPin = 13;
const int switchA = 14;
const int switchB = 34;

// Allocate names to values which will be read or calculated
int rate = 1;
int buttA = 0;
int buttB = 0;

void setup() {  
  // Configure the GPIO directions (input/output) and enable internal pull ups
  pinMode(switchA, INPUT_PULLUP);
  pinMode(switchB, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Checks the position on button A and inverts the logic
  // Alternative code to invert logic included using the ! operator
  // buttA = !digitalRead(switchA)
  buttA = ((digitalRead(switchA)-1)*(-1));
  // buttB = !digitalRead(switchB)
  buttB = ((digitalRead(switchB)-1)*(-1));
  // Calculate the rate at which to blink the LED
  rate = (1000 - (400*(buttA)) - (400*(buttB)));
  // Turn on the LED
  digitalWrite(ledPin, HIGH);
  // Wait the time calculated above
  delay(rate);
  // Turn the LED off
  digitalWrite(ledPin, LOW);
  // Wait the time calculated above before repeating the cycle
  delay(rate);
}
