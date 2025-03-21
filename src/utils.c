// #include "config.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int checkIfUpper(char *password) {
    int has_upper = 0;
    int passwordLength = (int)strlen(password);

    // Loop through password to find upper char
    for (int i = 0; i < passwordLength; i++) {
        if (isupper(*(password+i))) {
            has_upper = 1;
            return has_upper;
        }
    }

    return has_upper;

}

int checkIfLower(char *password) {
    int has_lower = 0;
    int passwordLength = (int)strlen(password);

    // Loop through password to find upper char
    for (int i = 0; i < passwordLength; i++) {
        if (islower(*(password+i))) {
            has_lower = 1;
            return has_lower;
        }
    }

    return has_lower;

}

// Function to check if any of string b appears in string a
int checkForAnyOfStringInString(char *stringA, char const *stringB) {
    int appears = 0;
    int stringLength = (int)strlen(stringB);

    for (int i = 0; i < stringLength; i++) {
        int ch = stringB[i]; 
        if (strchr(stringA, ch) != NULL) {
            appears = 1;
            return appears;
        }
    }

    return appears;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //Discard all characters until new line; 
}