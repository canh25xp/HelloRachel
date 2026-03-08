// Time definitions for Morse code
const int TIME_UNIT = 100;            // basic unit (ms)
const int DOT_TIME = TIME_UNIT;       // dot duration
const int DASH_TIME = TIME_UNIT * 3;  // dash duration
const int SYMBOL_SPACE = TIME_UNIT;
const int LETTER_SPACE = TIME_UNIT * 3;
const int WORD_SPACE = TIME_UNIT * 7;


// Morse code lookup table
struct MorseEntry {
  char letter;
  const char* morse;
};

MorseEntry morseTable[] = {
  { 'A', ".-" },
  { 'B', "-..." },
  { 'C', "-.-." },
  { 'D', "-.." },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', "-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." }
};

const int MORSETABLESIZE = sizeof(morseTable) / sizeof(MorseEntry);

// Turn LED on for dot
void sendDot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DOT_TIME);
  digitalWrite(LED_BUILTIN, LOW);
}

// Turn LED on for dash
void sendDash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DASH_TIME);
  digitalWrite(LED_BUILTIN, LOW);
}

// Send a single Morse symbol
void sendSymbol(char symbol) {
  if (symbol == '.') {
    sendDot();
  } else if (symbol == '-') {
    sendDash();
  }

  // gap between symbols
  delay(SYMBOL_SPACE);
}

// Send Morse code for a letter
void sendLetter(char letter) {
  letter = toupper(letter);
  for (int i = 0; i < MORSETABLESIZE; i++) {
    if (morseTable[i].letter == letter) {
      const char* morse = morseTable[i].morse;
      Serial.print(letter);
      Serial.print(" -> ");
      Serial.println(morse);

      for (int j = 0; morse[j] != '\0'; j++) {
        sendSymbol(morse[j]);
      }

      delay(LETTER_SPACE);
      return;
    }
  }
}

// Send an entire message
void sendMessage(const char* message) {
  for (int i = 0; message[i] != '\0'; i++) {
    char c = message[i];
    if (c == ' ') {
      delay(WORD_SPACE);
    } else {
      sendLetter(c);
    }
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Arduino Morse Code");
}

void loop() {
  sendMessage("HELLO RACHEL");
  Serial.print("\n");
  delay(5000);
}
