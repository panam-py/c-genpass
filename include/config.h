#ifndef CONFIG_H
#define CONFIG_H

// Utility functions
int checkIfUpper(char *password);
int checkIfLower(char *password);
int checkForAnyOfStringInString(char *stringA, char const *stringB);
void clearInputBuffer();

#endif