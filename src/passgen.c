#include "passgen.h"
#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        else if (userChoice == 78  || userChoice == 110 ) {
            printf("User chose NO! %c\n", userChoice);
            return choice; // If userchoice is 'N' or 'n'
        } else if (userChoice != 89 && userChoice != 121 && userChoice != 78 && userChoice != 110) {
            printf("Invalid choice, please choose 'Y' or 'N'.\n");
            continue;
        }
    };
};

char *generatePassword() {
    // Current of options selected
    char *optionSet = malloc(POSSIBLE_OPTION_LENGTH * sizeof(char));

    // Collect length of password from user
    int length, digits, lower, symbols, upper;
    printf("Your password should be how long?: ");
    scanf("%d", &length);

    // Set options based on received values
    digits = collectOptions("Do you want digits in your password? (Y or N): ");
    lower = collectOptions("Do you want lowercase in your password? (Y or N): ");
    symbols = collectOptions("Do you want symbols in your password? (Y or N): ");
    upper = collectOptions("Do you want uppercase in your password? (Y or N): ");
   

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

    printf("The password is: %s\n", newPassword);
    free(optionSet);
    free(newPassword);
    optionSet =  NULL;
    newPassword = NULL;
    return newPassword;
};

