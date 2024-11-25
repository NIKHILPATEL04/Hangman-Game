#include "hangman_helpers.h"

void test_assert(bool condition, const char *message) {
    if (!condition) {
        printf("Test failed: %s\n", message);
        exit(1);
    }
}

// Test for is_lowercase_letter
void test_is_lowercase_letter() {
    test_assert(is_lowercase_letter('a'), "Test 1");
    test_assert(is_lowercase_letter('z'), "Test 2");
    test_assert(!is_lowercase_letter('A'), "Test 3");
    test_assert(!is_lowercase_letter('Z'), "Test 4");
}

// Test for string_contains_characte
void test_string_contains_character() {
    const char *str1 = "hello";
    test_assert(string_contains_character(str1, 'h'), "Test 1");
    test_assert(string_contains_character(str1, 'o'), "Test 2");
    test_assert(!string_contains_character(str1, 'z'), "Test 3");
}

// Test for read_letter - requires manual testin
void test_read_letter() {
    printf("Test read_letter requires manual testing.\n");
    printf("Please enter a single character followed by Enter:\n");
    char result = read_letter();
    printf("You entered: %c\n", result);
}

void test_validate_secret() {
    const char *validSecret = "hangman-game";
    test_assert(validate_secret(validSecret), "Test 1");
    const char *invalidSecret2 = "TooLongPhraseOver256Characters";
    test_assert(!validate_secret(invalidSecret2), "Test 3");
}

int main() {
    test_is_lowercase_letter();
    test_string_contains_character();
    test_read_letter();
    test_validate_secret();

    printf("All tests passed!\n");

    return 0;
}
