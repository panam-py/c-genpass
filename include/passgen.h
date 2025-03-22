#ifndef PASSGEN_H
#define PASSGEN_H

// Specify a type for options when generating a password
// struct genOpt {
//     int use_upper;
//     int use_lower;
//     int use_digits;
//     int use_symbols;
// };

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


// Main logic functions
struct score *scoreObj(char *password, struct score *scoreObject);
void *generatePassword(int length, int digits, int lower, int symbols, int upper);
void *getScore(char *possiblePass);

#endif