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

struct data {
    double a;
    double b;
    double c;
};

void input(data *coeff);

Status input_coef_x(double *d);

void output(const Solution ans);

void output_wrong();

double get_diskriminant(const double a, const double b, const double c);

Solution line_eq(const data coeff);

Solution square_eq(const data coeff);

Solution solve(const data coeff);

int is_zero(const double d);

int main() {
    data coeff = {};
    input(&coeff);
    Solution ans = solve(coeff);
    output(ans);
    return 0;
}

Status input_coef_x(double *d) {
    assert(d != NULL);
    int first_checker = scanf("%lf", d);
    if (!first_checker) {
        _flushall();
        return WRONG;
    }
    char symbol;
    while ((symbol = (char) getchar()) != EOF) {
        if (symbol == '\n') {
            _flushall();
            return CORRECT;
        } else {
            _flushall();
            return WRONG;
        }
    }
    return CORRECT;
}

void input(data *coeff) {
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
    return d < EPS;
}

double get_diskriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

Solution line_eq(const data coeff) {
    if (is_zero(fabs(coeff.b))) {
        if (is_zero(fabs(coeff.c))) {
            return (Solution) {CNT_INFINITY, -1, -1};
        } else {
            return (Solution) {CNT_ZERO, -1, -1};
        }
    }
    return (Solution) {CNT_ONE, -coeff.c / coeff.b, -1};
}

Solution square_eq(const data coeff) {
    double d = get_diskriminant(coeff.a, coeff.b, coeff.c);
    double x1 = -1;
    double x2 = -1;
    if (d < 0.0 && !is_zero(fabs(d))) {
        return (Solution) {CNT_ZERO, -1, -1};
    }
    if (is_zero(fabs(d))) {
        x1 = -coeff.b / (2 * coeff.a);
        return (Solution) {CNT_ONE, x1, -1};
    }
    x1 = (-coeff.b + sqrt(d)) / (2 * coeff.a);
    x2 = (-coeff.b - sqrt(d)) / (2 * coeff.a);
    return (Solution) {CNT_TWO, x1, x2};
}

Solution solve(const data coeff) {
    if (is_zero(fabs(coeff.a))) {
        return line_eq(coeff);
    }
    return square_eq(coeff);
}
