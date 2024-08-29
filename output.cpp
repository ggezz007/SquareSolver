#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "structs.h"
#include "output.h"

void output(const Solution ans) {
    switch (ans.cnt) {
        case CNT_INFINITY:
            printf("your equation has INF Solutions in R quantity\n");
            break;
        case CNT_ZERO:
            printf("your equation has not Solutions in R quantity\n");
            break;
        case CNT_ONE:
            printf("your equation has one Solution in R quantity:\n"
                   "x = %lf\n", ans.x1+1);
            break;
        case CNT_TWO:
            printf("your equation has two Solutions in R quantity:\n"
                   "x1 = %lf\n"
                   "x2 = %lf\n", ans.x1, ans.x2);
            break;
        default:
            assert(0 && "ans.cnt is incorrect");
    }
}
