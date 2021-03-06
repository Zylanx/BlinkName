// Author: Matt Merrett (216101672)
//
// Assignment 2.1P
//
// Morse Code


// Define a constant for the led
int const led = D7;


// === Morse code timing constants ===
// All times are in milliseconds
int const unitPeriod = 250; // How long a single unit is in milliseconds

// Length of particles
int const ditPeriod = 1 * unitPeriod; // Length of a dit ('.')
int const dahPeriod = 3 * unitPeriod; // Length of a dah ('-')

// Spacing lengths
int const intraCharPeriod = 1 * unitPeriod; // length of time between particles
int const interCharPeriod = 3 * unitPeriod; // Length of time between characters
int const wordSpacePeriod = 7 * unitPeriod; // Length of time between words


// The sentence to output
char const * morseOutput = "Matt";


// Setup function, runs once at start-up
// Initialise the LED pin and set it low
void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}


// Loop function, runs over and over again.
void loop() {
    emitSentence(morseOutput);
}


// Emits a sentence out of the LED.
// Loops through each character in a string,
//    gets the morse code representation, then blinks the LED.
void emitSentence(char const * inputSentence) {
    for (int i = 0; inputSentence[i] != 0; i++) {
        // If the character is a space, we need to wait between words
        // otherwise just output the character
        if (inputSentence[i] == ' ') {
            delay(wordSpacePeriod);
        } else {
            emitChar(getCharString(toupper(inputSentence[i])));
            
            delay(interCharPeriod);
        }
    }
    
    // Reached the end of the sentence, give a word space
    delay(wordSpacePeriod);
}


/*
void emitWord(char* inputWord) {
    for (int i = 0; inputWord[i] != 0; i++) {
        emitChar(getCharString(inputWord[i]));
        
        sleep(interCharPeriod);
    }
}
*/


// Takes in a character and returns a morse code string
//    that represents it.
char const * getCharString(char inputChar) {
    // Make sure the characters are uppercase, morse code standard
    char inputUpper = toupper(inputChar);
    
    // Big lookup table for each letter
    switch (inputChar) {
        case 'A':
            return ".-"; // Break unneeded. Return breaks the branch
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
    }
}


// Loops through a morse code string and blinks out either a dit or a dah
void emitChar(char const * charString) {
    for (int i = 0; charString[i] != 0; i++) {
        if (charString[i] == '.') {
            emitDit();
        } else { // else it will be a dash ('-')
            emitDah();
        }
        
        delay(intraCharPeriod);
    }
}


// Blinks the LED with a dit
void emitDit() {
    digitalWrite(led, HIGH);
    delay(ditPeriod);
    digitalWrite(led, LOW);
}


// Blinks the LED with a dah
void emitDah() {
    digitalWrite(led, HIGH);
    delay(dahPeriod);
    digitalWrite(led, LOW);
}