#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define EPS 1e-9

enum RootsNumber {
    CNT_INFINITY = -1,
    CNT_ZERO = 0,
    CNT_ONE = 1,
    CNT_TWO = 2
};

struct solution {
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

void output(const solution ans);

double get_diskriminant(const double a, const double b, const double c);

solution line_eq(const data coeff);

solution square_eq(const data coeff);

solution solve(const data coeff);

int compare(const double d1, const double d2);

int main() {
    data coeff = {};
    input(&coeff);
    solution ans = solve(coeff);
    output(ans);
}

void input(data *coeff) {
    printf("your coefficients for quadratic equation (a * x ^ 2 + b * x + c = 0): \n"
           "also remember that b ^ 2, 4 * a * c, b ^ 2 + 4 * a * c should be the size double, so smaller than 1.7E+308\n"
           "a = ");
    scanf("%lf", &(coeff->a));
    printf("b = ");
    scanf("%lf", &(coeff->b));
    printf("c = ");
    scanf("%lf", &(coeff->c));
}

void output(const solution ans) {
    if (ans.cnt == CNT_INFINITY) {
        printf("your equation has INF solutions in R quantity\n");
    } else if (ans.cnt == CNT_ZERO) {
        printf("your equation has not solutions in R quantity\n");
    } else if (ans.cnt == CNT_ONE) {
        printf("your equation has one solution in R quantity:\n"
               "x = %lf\n", ans.x1);
    } else {
        printf("your equation has two solutions in R quantity:\n"
               "x1 = %lf\n"
               "x2 = %lf\n", ans.x1, ans.x2);
    }
}

double get_diskriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

int compare(const double d1, const double d2) {
    return d1 < d2;
}

solution line_eq(const data coeff) {
    if (compare(fabs(coeff.b), EPS)) {
        if (compare(fabs(coeff.c), EPS)) {
            return (solution) {CNT_INFINITY, -1, -1};
        } else {
            return (solution) {CNT_ZERO, -1, -1};
        }
    }
    return (solution) {CNT_ONE, -coeff.c / coeff.b, -1};
}

solution square_eq(const data coeff) {
    double d = get_diskriminant(coeff.a, coeff.b, coeff.c);
    double x1 = -1.0;
    double x2 = -1.0;
    if (compare(d, 0.0) && !compare(fabs(d), EPS)) {
        return (solution) {CNT_ZERO, -1, -1};
    }
    if (compare(fabs(d), EPS)) {
        x1 = -coeff.b / (2 * coeff.a);
        return (solution) {CNT_ONE, x1, -1};
    }
    x1 = (-coeff.b + sqrt(d)) / (2 * coeff.a);
    x2 = (-coeff.b - sqrt(d)) / (2 * coeff.a);
    return (solution) {CNT_TWO, x1, x2};
}

solution solve(const data coeff) {
    if (compare(fabs(coeff.a), EPS)) {
        return line_eq(coeff);
    }
    return square_eq(coeff);
}

