



jv // Must declare the main assembly entry point before use.
void main_asm();

// Set up buttons ETC
/**
 * @brief Initialise a gpio pin - see SDK for detail on gpio_init()
 */
void asm_gpio_init(uint pin) {
    gpio_init(pin);
}

/**
 * @brief Set direction of a GPIO pin – see SDK for detail on gpio_set_dir()
 */
void asm_gpio_set_dir(uint pin, bool out) {
    gpio_set_dir(pin, out);
}

/**
 * @brief Get the value of a GPIO pin – see SDK for detail on gpio_get()
 * 
 * @param pin GPIO value of pin whos value will be fetched
 * @return true if value fetched successfully   
 * @return false if value fetch failed
 */
bool asm_gpio_get(uint pin) {
    return gpio_get(pin);
}

int inputInserted = 0;

/**
 * @brief an array of numbers in morse 
 */
char morseCodeNumbers[10][6] =    {"-----", ".----", "..---", "...--", "....-", ".....",
                        "-....", "--...", "---..", "----."};

/**
 * @brief an array of letters in morse 
 */
char morseCodeLanguage[26][5] = {".-", "-...", "-.-.", "-..", ".",
                        "..-.", "--.", "....", "..", ".---",
                        "-.-", ".-..", "--", "-.", "---",
                        ".--.", "--.-", ".-.", "...", "-",
                        "..-", "...-", ".--", "-..-", "-.--", "--.."};

                        /**
 * @brief turns a letter or number into morse code
 * 
 * @param input a letter or number 
 * @return sequence translated into morse code
 */
char* translate_to_morse(char input) {
    int index = 26;
    char* output;
    
    if ( (int) input >= 65 && (int) input <= 90 ) {
        index = (int) input - 65;
        output = morseCodeLanguage[index];
    } else if ( (int) input >= 48 && (int) input <= 57 ) {
        index = (int) input - 48;
        output = morseCodeNumbers[index];  
    } else {
        output = "Error has occured";
    }
    return output;
}

char in;

void checkInterrupt();
/*
 * Main entry point for the code - simply calls the main assembly function.
 */
int main() {
     // Initialise all basic IO
    stdio_init_all();
    // Pick a random number 
    int randomnumber = rand() % 36;
    char puzzle;
        char* puzzlePointer;
        if ( randomnumber >= 10 ) {
            puzzle = (char) randomnumber + 55;
        }
        else {
            puzzle = (char) randomnumber + 48;
        }

        printf("Please solve the following in morse code: %c\n", puzzle);
        if (in == '1') {
            puzzlePointer = translate_to_morse(puzzle);
            printf("Answer: %s\n", puzzlePointer);
        }
        printf("Your input: ");
        while (!(inputInserted == 1)) {
            waitForInterrupt();
        }
        inputInserted = 0;
        
        printf("Decoded: %c\n", morse_code_translate());
        if ( puzzle == morse_code_translate() ) {
            printf("Correct!\n");
            
        }
        else {
            printf("Incorrect\n");
           
        }

   
    return(0);
}

