#include "hangman_helpers.h"

char elim[7] = { '\0' };

void sortelim(void) {
    unsigned long h = 0;
    unsigned long k = 0;
    char placeHolder;
    unsigned long numberString = strlen(elim);
    for (h = 0; h < numberString - 1; h++) {
        for (k = h + 1; k < numberString; k++) {
            if (elim[h] > elim[k]) {
                placeHolder = elim[h];
                elim[h] = elim[k];
                elim[k] = placeHolder;
            }
        }
    }
}

int main(int input, char **argv) {
    if (input != 2) {
        exit(1);
    }

    char *secretword;
    char letters[27] = { '\0' };
    int a = 0;

    secretword = argv[1];
    validate_secret(secretword);

    char word[256];
    for (int j = 0; j < 256; j++) {
        if (secretword[j] == '\0') {
            word[j] = '\0';
            break;
        }
        char alphatemp = secretword[j];
        if (alphatemp >= 'a' && alphatemp <= 'z') {
            word[j] = '_';
        } else {
            word[j] = alphatemp;
        }
    }
    int r = 0;
    char index;
    while (r <= 6) {
        printf("%s", CLEAR_SCREEN);
        printf("%s\n\n", arts[r]);
        printf("    Phrase: %s\n", word);
        printf("Eliminated: %s\n", elim);

        if (r == 6) {
            printf("\nYou lose! The secret phrase was: %s\n", secretword);
            break;
        }
        printf("\nGuess a letter: ");
        index = read_letter();
        while (string_contains_character(letters, index) || !is_lowercase_letter(index)) {
            printf("Guess a letter: ");
            index = read_letter();
        }

        letters[a] = index;
        a++;

        if (string_contains_character(secretword, index)) {
            for (unsigned long a = 0; a < strlen(secretword); a++) {
                if (secretword[a] == index) {
                    word[a] = secretword[a];
                }
            }
        } else {
            elim[r] = index;
            r++;
            if (r > 1) {
                sortelim();
            }
        }
        if (!string_contains_character(word, '_')) {
            printf("%s", CLEAR_SCREEN);
            printf("%s\n\n", arts[r]);
            printf("    Phrase: %s\n", word);
            printf("Eliminated: %s\n", elim);
            printf("\n");
            printf("You win! The secret phrase was: %s\n", secretword);
            break;
        }
    }
    return 0;
}
