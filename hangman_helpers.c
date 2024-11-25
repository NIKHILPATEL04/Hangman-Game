#include "hangman_helpers.h"

bool is_lowercase_letter(char c) {
    return c >= 'a' && c <= 'z';
}

bool string_contains_character(const char *s, char c) {
    unsigned long counter = strlen(s);
    for (unsigned long a = 0; a < counter; a++) {
        if (s[a] == c) {
            return true;
        }
    }
    return false;
}

bool validate_secret(const char *secret) {
    unsigned long number = strlen(secret);
    if (number > 256) {
        printf("the secret phrase is over 256 characters\n");
        exit(1);
    }
    for (unsigned long k = 0; k < number; k++) {
        if (!is_lowercase_letter(secret[k]) && !string_contains_character(punctuation, secret[k])) {
            printf("invalid character: '%c'\n", secret[k]);
            printf("the secret phrase must contain only lowercase letters, spaces, hyphens, and "
                   "apostrophes\n");
            exit(1);
        }
    }

    return true;
}

char read_letter(void) {
    int a;
    a = getchar();
    int b;
    do {
        b = getchar();
    } while ((char) b != '\n');
    return (char) a;
}
