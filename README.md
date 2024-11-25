Interactive Hangman Simulation in C
NIKHIL PATEL 


**Purpose**

This project implements the classic "Hangman" game in C. Players attempt to guess a hidden word or phrase by suggesting one letter at a time. For each incorrect guess, a part of the hangman is drawn, and the player loses if they accumulate six incorrect guesses. The program supports multi-word phrases, spaces, hyphens, and apostrophes. Additionally, ASCII art dynamically updates the gallows based on the player's progress. Designed with modularity, error handling, and robust input validation, the game ensures seamless gameplay and provides clear feedback for valid and invalid inputs.

**Guesses**


In this game, players can make 27 valid single-character guesses, including alphabetical letters, spaces, hyphens, and apostrophes. These guesses are tracked to display incorrect letters in a bank, organized in alphabetical order. Tracking each guess is essential to avoid repetition and ensure the game's state is accurately reflected. An integer-based counter function was selected for this purpose, allowing efficient storage, sorting, and retrieval of guessed letters.
To check if a letter has already been guessed, the program compares the player's input to an array of stored guesses. This prevents repeated inputs from affecting gameplay and ensures that eliminated letters are displayed correctly. This approach keeps the game flow consistent and user-friendly.

**Strings and Characters**

In Python, the chr() function converts integers to characters, while the ord() function converts characters to their corresponding Unicode or integer values. These functions are translated into C by using type casting to manipulate characters and their numeric equivalents. For example, the Python snippet print(ord('q')) can be implemented in C as printf("%d\n", (int)'q');.
In C, strings are arrays of characters terminated by a null byte (\0). For instance, char myString[] = "Hello, World!"; represents a valid string, while an improperly initialized pointer such as char* invalidString = "Invalid String"; may cause errors. Strings in C are null-terminated by default when defined as literals. However, failure to null-terminate a string can lead to undefined behavior, including infinite loops. Properly handling null termination is crucial for program stability.
The macro CLEAR_SCREEN is used to refresh the terminal display during gameplay. Although it does not have a specific data type, it plays a vital role in ensuring the user interface updates dynamically and remains intuitive.

**Testing**


The program is rigorously tested across multiple scenarios to validate functionality and error handling. Tests include inputs with non-alphabetic symbols, multi-character strings, and edge cases such as empty strings or invalid characters. Additionally, comprehensive checks are performed on functions that process and validate input, ensuring correct updates to the displayed phrase and the bank of eliminated letters. By simulating a variety of gameplay scenarios, the program demonstrates its ability to handle both typical and edge-case inputs.

**How to Use the Program**

The Hangman game begins by displaying ASCII art for the gallows and a secret phrase represented by underscores for unrevealed characters. Players are prompted to guess letters, which are either revealed in the phrase or added to a bank of incorrect guesses. Each incorrect guess updates the gallows with a new limb. Gameplay continues until the player either successfully guesses the entire phrase or the hangman is completed.
If the player wins, a congratulatory message is displayed, such as:
**You WIN! The secret phrase was: don't go in empty-handed.**
If the player loses, the program displays a message like:
**You lose! The secret phrase was: don't go in empty-handed.**
The game dynamically updates after each turn, providing clear feedback and ensuring an engaging user experience.

**Program Design**

The program is structured to be modular and maintainable. It utilizes helper functions to handle specific tasks, ensuring clear separation of logic. These include:
is_lowercase_letter(char c): This function determines if a character is a lowercase letter between 'a' and 'z'. It returns a boolean value, facilitating input validation for guesses.
string_contains_character(const char* s, char c): This function checks if a string contains a specific character. By iterating through the string, it returns true if the character is found and false otherwise. This is essential for tracking whether a letter has already been guessed.
validate_secret(const char* secret): This function ensures that the secret phrase adheres to the game's constraints, such as a maximum length of 256 characters and the use of valid characters (letters, spaces, hyphens, and apostrophes). If invalid, the function prints an appropriate error message and returns false.
read_letter(): This function prompts the player to input a single character, validates it, and returns the character for further processing. It ensures that only valid inputs are considered during gameplay.
The main function initializes variables for user input and the secret phrase. The phrase is displayed as underscores, with spaces and special characters revealed by default. Correct guesses replace underscores in the phrase, while incorrect guesses are added to a bank of eliminated letters. A while loop manages gameplay, iterating until the player either wins by guessing the phrase or loses after six incorrect guesses. The CLEAR_SCREEN macro ensures the interface updates dynamically, enhancing the user experience.

