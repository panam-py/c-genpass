#include "passgen.h"
#include "../src/utils.c"
// #include "config.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>


void test() {
    // Confirm password length
    struct scoreAttributes *scoreAttr = malloc(sizeof(struct scoreAttributes));
    int length = 9;
    int digits =  89;
    int lower = 89;
    int symbols = 79;
    int upper = 79;

    scoreAttr = (struct scoreAttributes*)generatePassword(length, digits, lower, symbols, upper);
    assert(scoreAttr->passLen == length);

    // Confirm if characters not chosen are present
    // int present;
    // present = checkForAnyOfStringInString(scoreAttr->password, SYMBOLS);
    // assert(present == scoreAttr->has_symbols);
    
    // Estimate password strength using the newly created password
    struct score *scoreObj = malloc(sizeof(struct score));
    scoreObj = getScore(scoreAttr->password);
    
    
    // Assert that password strength and label(remark) equals what was previously received.
    assert(scoreObj->value == scoreAttr->scoreObject->value);
    assert(scoreObj->remark == scoreAttr->scoreObject->remark);

    // Free
    // free(scoreAttr->scoreObject->remark);
    free(scoreAttr->scoreObject);
    free(scoreAttr->password);
    free(scoreAttr);
    // free(scoreObj->remark);
    free(scoreObj);

    printf("All tests passed!\n");
}

int main() {
    test();
    return 0;
}

