#ifndef PASSGEN_H
#define PASSGEN_H

// Specify a type for options when generating a password
// struct genOpt {
//     int use_upper;
//     int use_lower;
//     int use_digits;
//     int use_symbols;
// };

extern const int POSSIBLE_OPTION_LENGTH;// = 95; // Total length of the possible characters that could be added
extern const char UPPER[27];// = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
extern const char LOWER[27];// = "abcdefghijklmnopqrstuvwxyz";
extern const char DIGITS[11]; //= "0123456789";
extern const char SYMBOLS[33];// = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

struct score {
    int value;
    char *remark;
};

struct scoreAttributes {
    struct score *scoreObject;
    int passLen;
    char *password;
    int has_digit;
    int has_lower;
    int has_upper;
    int has_symbols;
};

// Utility functions
int checkIfUpper(char *password);
int checkIfLower(char *password);
int checkForAnyOfStringInString(char *stringA, char const *stringB);
void clearInputBuffer();

// Main logic functions
struct score *scoreObj(char *password, struct score *scoreObject);
void *generatePassword(int length, int digits, int lower, int symbols, int upper);
void *getScore(char *possiblePass);

#endif