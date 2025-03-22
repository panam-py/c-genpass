#include "passgen.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handleShutDown(int signal) {
    (void)signal;
    printf("\nShutting down...\n");
    exit(0);
}

int main() {
    signal(SIGINT, handleShutDown); // Handle CTRL + C (SIGINT - SIGNAL INTERRUPTION)
    int choice;
    while(1) {
        printf("What do you want to do?\nSelect 1 to generate a password and 2 to estimate a password: ");
        int inputErr = scanf(" %d", &choice);
        if (inputErr != 1) {
            printf("Invalid input for generating password!\n");
            clearInputBuffer(); // Flush invalid input
            continue;
        };

        if (choice == 1) generatePassword(0);
        else if (choice == 2) getScore();

        else {
            printf("Invalid choice entered!\n");
            continue;
        }
    }

    return 0;
}