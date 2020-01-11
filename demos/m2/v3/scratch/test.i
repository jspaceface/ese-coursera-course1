# 1 "test.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "test.c"
# 1 "test.h" 1






int getANumber();
# 2 "test.c" 2

void main() {
    int a = getANumber();
    int b = 15;
    int c = a + b;

    return 0;
}

int getANumber() {
    return 4;
}
