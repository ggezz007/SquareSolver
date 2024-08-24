#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "output.h"
#include "solution.h"
#include "structs.h"
#include "input.h"
#include "cmp.h"
#define EPS 1e-9

int main() {
    const Unit_test test[] = {{{0.0, 0.0, 0.0}, {CNT_INFINITY, NAN, NAN}},
                                 {{-1.0, -1.0, 10.0}, {CNT_TWO, (-1 - sqrt(41.0)) / 2, (-1 + sqrt(41.0)) / 2}},
                                 {{0.0, 0.0, 2.0}, {CNT_ZERO, NAN, NAN}},
                                 {{0.0, 1.0, 2.0}, {CNT_ONE, -2.0, NAN}},
                                 {{5.0, 0.0, -1.0}, {CNT_TWO, sqrt(5) / 5, -sqrt(5) / 5}},
                                 {{ 2.0, 3.0, -1.0 }, { CNT_TWO, (-3 + sqrt(17)) / 4, (-3 - sqrt(17)) / 4 }},
                                 {{ 1.0, 0.0, 5.0 }, { CNT_ZERO, NAN, NAN }},
                                 {{ 0.0, 4.0, -16.0 }, { CNT_ONE, 4.0, NAN }}};
    const int len_array = sizeof(test)/sizeof(*test);
    check_solve(test, len_array);
    Data coeff = { NAN, NAN, NAN };
    input(&coeff);
    Solution ans = solve(coeff);
    output(ans);
    return 0;
}

