#include <stdio.h>  // For printf, fgets, getchar
#include <string.h> // For strlen
// #include <stdlib.h> // Not strictly needed for this specific sscanf approach, but useful for strtol

// Define a buffer size for reading the input line
#define MAX_LINE_LENGTH 1000

int main() {
    int n;
    char line[MAX_LINE_LENGTH]; // Buffer to store the entire line of input

    // Loop indefinitely until a valid integer (and only an integer) is entered
    while (1) {
        printf("Enter an integer: ");

        // Read the entire line of input into 'line'.
        // fgets returns NULL on error or end-of-file.
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            return 1; // Indicate an error occurred
        }

        // Remove the trailing newline character if it's present.
        // fgets typically includes the newline character if there's space.
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0'; // Replace newline with null terminator
        } else {
            // If the line was too long for our buffer, or no newline was found,
            // clear the rest of the input buffer to prevent issues on next read.
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Attempt to parse the string as an integer.
        // We use "%d" to read the integer and then "%c" to try and capture any
        // *extra* non-whitespace character that might follow the integer.
        char remaining_char; // This will catch any unexpected character
        int scan_count = sscanf(line, "%d %c", &n, &remaining_char);

        if (scan_count == 1) {
            // Success: sscanf found exactly one item, which was our integer (%d).
            // This means there were no extra non-whitespace characters after the number.
            break; // Valid input, exit the loop
        } else if (scan_count == 2) {
            // Failure: sscanf found both the integer (%d) AND another character (%c).
            // This indicates extra, unexpected characters in the input (e.g., "123a").
            printf("Error: Input contains extra characters ('%c'). Please enter ONLY an integer.\n", remaining_char);
        } else { // scan_count == 0 or EOF
            // Failure: sscanf found no integer at all (e.g., "abc" or an empty line).
            printf("Error: Invalid input. Please enter an integer.\n");
        }
    }

    // At this point, 'n' holds a valid integer.
    // Proceed with the odd/even check.
    if (n % 2 == 0) {
        printf("%d is even.\n", n);
    } else {
        // If the number is not even, it must be odd (remainder 1 or -1).
        printf("%d is odd.\n", n);
    }

    return 0; // Indicate successful program execution
}