#ifndef STRUCTS_H
#define STRUCTS_H

enum RootsNumber {
    CNT_INFINITY = -1,
    CNT_ZERO = 0,
    CNT_ONE = 1,
    CNT_TWO = 2
};

enum Status {
    WRONG = 0,
    CORRECT = 1,
};

struct Solution {
    RootsNumber cnt;
    double x1;
    double x2;
};

struct Data {
    double a;
    double b;
    double c;
};

struct Unit_test {
    Data test;
    Solution test_ans;
};

#endif
