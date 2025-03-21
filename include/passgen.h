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


// Main logic functions
struct score *scoreObj(char *password, struct score *scoreObject);
void generatePassword();
void getScore();

#endif