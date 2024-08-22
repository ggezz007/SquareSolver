#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPS 1e-9

enum RootsNumber {
    CNT_INFINITY = -1,
    CNT_ZERO = 0,
    CNT_ONE = 1,
    CNT_TWO = 2
};

enum Status {
    WRONG = 0,
    CORRECT = 1
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

void check_solve();

void input(Data *coeff);

Status input_coef_x(double *d);

void output(const Solution ans);

void output_wrong();

double get_diskriminant(const double a, const double b, const double c);

Solution line_eq(const Data coeff);

Solution square_eq(const Data coeff);

Solution solve(const Data coeff);

int is_zero(const double d);

void clean_stdin();


int main() {
    check_solve();
    Data coeff = {NAN, NAN, NAN};
    input(&coeff);
    Solution ans = solve(coeff);
    output(ans);
    return 0;
}

void clean_stdin() {
    char elem = '0';
    while ((elem = (char) getchar()) != '\n');
}

Status input_coef_x(double *d) {
    assert(d != NULL);
    int first_checker = scanf("%lf", d);
    if (!first_checker) {
        clean_stdin();
        return WRONG;
    }
    char symbol = (char) getchar();
    if (symbol == '\n') {
        return CORRECT;
    } else {
        clean_stdin();
        return WRONG;
    }
}

void input(Data *coeff) {
    assert(coeff != NULL);
    printf("your coefficients for quadratic equation (a * x ^ 2 + b * x + c = 0): \n"
           "also remember that b ^ 2, 4 * a * c, b ^ 2 + 4 * a * c should be the size double, so smaller than 1.7E+308\n"
           "a = ");
    while (!input_coef_x(&(coeff->a))) {
        output_wrong();
    }
    printf("b = ");
    while (!input_coef_x(&(coeff->b))) {
        output_wrong();
    }
    printf("c = ");
    while (!input_coef_x(&(coeff->c))) {
        output_wrong();
    }
}

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
                   "x = %lf\n", ans.x1);
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

void output_wrong() {
    printf("input should contain only numbers from range 0-9, '.', '-'.\n"
           "Please try again\n");
}

int is_zero(const double d) {
    return fabs(d) < EPS;
}

double get_diskriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

Solution line_eq(const Data coeff) {
    if (is_zero(coeff.b)) {
        if (is_zero(coeff.c)) {
            return (Solution) {CNT_INFINITY, NAN, NAN};
        } else {
            return (Solution) {CNT_ZERO, NAN, NAN};
        }
    }
    return (Solution) {CNT_ONE, -coeff.c / coeff.b, NAN};
}

Solution square_eq(const Data coeff) {
    assert(!isnan(coeff.a));
    assert(!isnan(coeff.b));
    assert(!isnan(coeff.c));
    double d = get_diskriminant(coeff.a, coeff.b, coeff.c);
    double x1 = NAN;
    double x2 = NAN;
    if (d < 0.0 && !is_zero(d)) {
        return (Solution) {CNT_ZERO, NAN, NAN};
    }
    if (is_zero(d)) {
        x1 = -coeff.b / (2 * coeff.a);
        return (Solution) {CNT_ONE, x1, NAN};
    }
    x1 = (-coeff.b + sqrt(d)) / (2 * coeff.a);
    x2 = (-coeff.b - sqrt(d)) / (2 * coeff.a);
    return (Solution) {CNT_TWO, x1, x2};
}

Solution solve(const Data coeff) {
    if (is_zero(coeff.a)) {
        return line_eq(coeff);
    }
    return square_eq(coeff);
}

void check_solve() {
    printf("First check\n");
    Data test1 = {0, 0, 0};
    Solution test1_solve = solve(test1);
    if (test1_solve.cnt == CNT_INFINITY && isnan(test1_solve.x1) && isnan(test1_solve.x2)) {
        printf("test 1 is correct\n");
    }
    Data test2 = {-1, -1, 10};
    Solution test2_solve = solve(test2);
    if (test2_solve.cnt == CNT_TWO &&
        is_zero(fmax(test2_solve.x1, (-1 - sqrt(41.0)) / 2) - fmin(test2_solve.x1, (-1 - sqrt(41.0)) / 2)) &&
        is_zero(fmax(test2_solve.x2, (-1 + sqrt(41.0)) / 2) - fmin(test2_solve.x2, (-1 + sqrt(41.0)) / 2))) {
        printf("test 2 is correct\n");
    }
    Data test3 = {0, 0, 2};
    Solution test3_solve = solve(test3);
    if (test3_solve.cnt == CNT_ZERO && isnan(test3_solve.x1) && isnan(test3_solve.x2)) {
        printf("test 3 is correct\n");
    }
    Data test4 = {0, 1, 2};
    Solution test4_solve = solve(test4);
    if (test4_solve.cnt == CNT_ONE &&
        is_zero(fmax(test4_solve.x1, -2.0) - fmin(test4_solve.x1, -2.0)) && isnan(test4_solve.x2)) {
        printf("test 4 is correct\n");
    }
    Data test5 = {5, 0, -1};
    Solution test5_solve = solve(test5);
    if (test5_solve.cnt == CNT_TWO &&
        is_zero(fmax(test5_solve.x1, sqrt(5) / 5) - fmin(test5_solve.x1, sqrt(5) / 5)) &&
        is_zero(fmax(test5_solve.x2, -sqrt(5) / 5) - fmin(test5_solve.x2, -sqrt(5) / 5))) {
        printf("test 5 is correct\n");
    }
    Data test6 = {2, 3, -1};
    Solution test6_solve = solve(test6);
    if (test6_solve.cnt == CNT_TWO &&
        is_zero(fmax(test6_solve.x1, (-3 + sqrt(17)) / 4) - fmin(test6_solve.x1, (-3 + sqrt(17)) / 4)) &&
        is_zero(fmax(test6_solve.x2, (-3 - sqrt(17)) / 4) - fmin(test6_solve.x2, (-3 - sqrt(17)) / 4))) {
        printf("test 6 is correct\n");
    }
    Data test7 = {1, 0, 5};
    Solution test7_solve = solve(test7);
    if (test7_solve.cnt == CNT_ZERO && isnan(test7_solve.x1) && isnan(test7_solve.x2)) {
        printf("test 7 is correct\n");
    }
    Data test8 = {0, 4, -16};
    Solution test8_solve = solve(test8);
    if (test8_solve.cnt == CNT_ONE && is_zero(fmax(test8_solve.x1, 4) - fmin(test8_solve.x1, 4)) &&
        isnan(test8_solve.x2)) {
        printf("test 8 is correct\n\n");
    }
}

