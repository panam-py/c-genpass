#include "passgen.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int choice;
    while(1) {
        printf("What do you want to do?\nSelect 1 to generate a password and 2 to estimate a password: ");
        int inputErr = scanf(" %d", &choice);
        if (inputErr != 1) {
            printf("Invalid input for generating password!\n");
            clearInputBuffer(); // Flush invalid input
            continue;
        };

        if (choice == 1) generatePassword();
        else if (choice == 2) getScore();

        else {
            printf("Invalid choice entered!\n");
            continue;
        }
    }

    return 0;
}