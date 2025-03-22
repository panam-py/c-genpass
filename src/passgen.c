#include "passgen.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int POSSIBLE_OPTION_LENGTH = 95; // Total length of the possible characters that could be added
const char UPPER[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char LOWER[27] = "abcdefghijklmnopqrstuvwxyz";
const char DIGITS[11] = "0123456789";
const char SYMBOLS[33] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

int collectOptions(char *text) {
    char userChoice;
    int choice = 0; // Set initial choice to 0 (false - No)
    // Loop by asking users their choices for different options continuing the loop if the user enters the wrong thing
    while (1) {
        printf("%s", text);
        scanf(" %c", &userChoice);
        if (userChoice == 89 || userChoice == 121 ) { // If userchoice is 'Y' or 'y'
            choice = 1;
            return choice;
        }

        else if (userChoice == 78  || userChoice == 110 ) return choice; // If userchoice is 'N' or 'n'
        else if (userChoice != 89 && userChoice != 121 && userChoice != 78 && userChoice != 110) {
            printf("Invalid choice, please choose 'Y' or 'N'.\n");
            continue;
        }
    };
};

// Function to return the score object for the current password
struct score *scoreObj(char *password, struct score *scoreObject) {
    int score = 0;
    size_t passwordLength = strlen(password);

    // Implement scoring system
    if (passwordLength >= 8) ++score;
    if (passwordLength >= 12) ++score;
    if (checkIfLower(password)) ++score;
    if (checkIfUpper(password)) ++score;
    if (checkForAnyOfStringInString(password, DIGITS)) ++score;
    if (checkForAnyOfStringInString(password, SYMBOLS)) ++score;
    
    scoreObject->value = score;

    // Assign score remark based on score (remark is used as a string literal here so it's read only)
    if (score >= 0 && score <= 2) scoreObject->remark = "WEAK";
    else if (score >= 3 && score <= 4) scoreObject->remark = "MODERATE";
    else if (score >= 5 && score <= 6)  scoreObject->remark = "STRONG";
    else if (score == 7) scoreObject->remark =  "VERY STRONG";


    return scoreObject;
};

void *getScore(char *possiblePass) {
    char *password;
    int passwordEmpty = strcmp(possiblePass, ""); // Check if possiblePass is an empty string, if 0 it means possiblePass os empty

    // if possiblePass is an empty string, collect password from user, if not use passed value
    if (passwordEmpty == 0) {
        password = malloc(128 * sizeof(char)); // Setting length to 128 MAX
        printf("Enter the password to check it's security level: ");
        scanf("%s", password);
    } else {
        password = possiblePass;
    }

    struct score *scoreObject = malloc((sizeof(struct score)));
    scoreObject = scoreObj(password, scoreObject);


    printf("This password had a strength of %d and is labeled as %s\n", scoreObject->value, scoreObject->remark);

    if (passwordEmpty == 0) {
        free(scoreObject);
        free(password);
        return NULL;
    }

    return scoreObject;
}

void *generatePassword(int length, int digits, int lower, int symbols, int upper) { // Set length to zero for the function to get length from stdin
    // Current of options selected
    char *optionSet = malloc(POSSIBLE_OPTION_LENGTH * sizeof(char));
    
    // Collect length of password from user
    // int digits, lower, symbols, upper;

    if (length == 0) {
        printf("Your password should be how long?: ");
        scanf("%d", &length);
    }

    // Set options based on received values
    if (digits == -1) digits = collectOptions("Do you want digits in your password? (Y or N): ");
    if (lower == -1) lower = collectOptions("Do you want lowercase in your password? (Y or N): ");
    if (symbols == -1) symbols = collectOptions("Do you want symbols in your password? (Y or N): ");
    if (upper == -1) upper = collectOptions("Do you want uppercase in your password? (Y or N): ");
   

    // Exit from app if user does not select yes to any option
    if ((upper + symbols + lower + digits) < 1) {
        printf("User disabled all options!\n");
        exit(EXIT_FAILURE);
    }


    // If option is enabled append the option array to the optionSet
    if (digits) strcat(optionSet, (char *)(&DIGITS));
    if (lower) strcat(optionSet, (char *)(&LOWER));
    if (symbols) strcat(optionSet, (char *)(&SYMBOLS));
    if (upper) strcat(optionSet, (char *)(&UPPER));

    // Get the length of the optionSet
    int optionLen = (int)strlen(optionSet);
    char *newPassword = malloc(length * sizeof(char));

    // Loop and get a random character until it reaches the length of the password
    for (int i = 0; i < length; i++) {
        int curIndex = rand() % optionLen;
        *(newPassword+i) = optionSet[curIndex];
    }

    // Get score object for the password
    struct score *scoreObject = malloc(sizeof(struct score));
    scoreObject = scoreObj(newPassword, scoreObject);
    
    printf("The password is: %s\nThe score for this password is %d and it is labeled as %s\n", newPassword, scoreObject->value, scoreObject->remark);

    struct scoreAttributes *scoreAttr = malloc(sizeof(struct scoreAttributes));
    scoreAttr->passLen = length;
    scoreAttr->password = newPassword;
    scoreAttr->scoreObject = scoreObject;
    scoreAttr->has_digit = digits;
    scoreAttr->has_lower = lower;
    scoreAttr->has_symbols = symbols;
    scoreAttr->has_upper = upper;

    // Free out space since length was not passed we do not need to return the scoreAttribute 
    if (length == 0) {
        free(newPassword);
        free(scoreObject);
        newPassword = NULL;
        scoreObject = NULL;
        return NULL;
    }
    
    free(optionSet);
    optionSet =  NULL;
    return scoreAttr;
};

