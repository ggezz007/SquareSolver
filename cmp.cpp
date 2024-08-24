#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "structs.h"
#include "solution.h"
#include "cmp.h"
Status compare(const Data coeff, const Solution correct_ans) {
    Solution system_ans = solve(coeff);
    switch (correct_ans.cnt) {
        case CNT_INFINITY:
            if (system_ans.cnt == CNT_INFINITY && isnan(system_ans.x1) && isnan(system_ans.x2)) {
                return CORRECT;
            } else {
                return WRONG;
            }
        case CNT_ZERO:
            if (system_ans.cnt == CNT_ZERO && isnan(system_ans.x1) && isnan(system_ans.x2)) {
                return CORRECT;
            } else {
                return WRONG;
            }
        case CNT_ONE:
            if (system_ans.cnt == CNT_ONE &&
                is_zero(fmax(system_ans.x1, correct_ans.x1) - fmin(system_ans.x1, correct_ans.x1)) &&
                isnan(system_ans.x2)) {
                return CORRECT;
            } else {
                return WRONG;
            }
        case CNT_TWO:
            if (system_ans.cnt == CNT_TWO &&
                is_zero(fmax(system_ans.x1, correct_ans.x1) - fmin(system_ans.x1, correct_ans.x1)) &&
                is_zero(fmax(system_ans.x2, correct_ans.x2) - fmin(system_ans.x2, correct_ans.x2))) {
                return CORRECT;
            } else {
                return WRONG;
            }
        default:
            assert(0 && "correct_ans is incorrect");
    }
}

void check_solve(const Unit_test test[], const int len_array) {
    printf("First check\n");
    for (int i = 0; i < len_array; i++) {
        if (compare(test[i].test, test[i].test_ans) == CORRECT) {
            printf("test %d is correct\n", i + 1);
        } else {
            printf("test %d is incorrect\n", i + 1);
        }
    }
}
