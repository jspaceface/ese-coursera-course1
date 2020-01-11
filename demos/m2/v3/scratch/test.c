#include "test.h"

void main() {
    int a = getANumber();
    int b = ANOTHER_CONSTANT;
    int c = a + b;
    
    return 0;
}

int getANumber() {
    return SOME_CONSTANT;
}