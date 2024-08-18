#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define EPS 1e-9

enum count {
    cnt_infinity = -1,
    cnt_zero = 0,
    cnt_one = 1,
    cnt_two = 2
};

struct solution {
    enum count cnt;
    double x1, x2;
};

struct data {
    double a, b, c;
};

void input(data *coeff);

void output(const solution ans);

double get_diskriminant(const double a, const double b, const double c);

solution line_eq(const data coeff);

solution square_eq(const data coeff);

solution solve(const data coeff);

int main() {
    data coeff = {};
    input(&coeff);
    solution ans = solve(coeff);
    output(ans);
}

void input(data *coeff) {
    printf("your coefficients for quadratic equation (a * x ^ 2 + b * x + c = 0): "
           "\nalso remember that b ^ 2, 4 * a * c, b ^ 2 + 4 * a * c should be the size double, so smaller than 1.7E+308"
           "\na =");
    scanf(" %lf", &(coeff->a));
    printf("b =");
    scanf(" %lf", &(coeff->b));
    printf("c =");
    scanf(" %lf", &(coeff->c));
}

void output(const solution ans) {
    if (ans.cnt == cnt_infinity) {
        printf("your equation has INF solutions in R quantity\n");
    } else if (ans.cnt == cnt_zero) {
        printf("your equation has not solutions in R quantity\n");
    } else if (ans.cnt == cnt_one) {
        printf("your equation has one solution in R quantity:"
               "\nx = %lf\n", ans.x1);
    } else {
        printf("your equation has two solutions in R quantity:"
               "\nx1 = %lf"
               "\nx2 = %lf\n", ans.x1, ans.x2);
    }
}

double get_diskriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

solution line_eq(const data coeff) {
    if (fabs(coeff.b) < EPS) {
        if (fabs(coeff.c) < EPS) {
            return (solution) {cnt_infinity, -1, -1};
        } else {
            return (solution) {cnt_zero, -1, -1};
        }
    }
    return (solution) {cnt_one, -coeff.c / coeff.b, -1};
}

solution square_eq(const data coeff) {
    double d = get_diskriminant(coeff.a, coeff.b, coeff.c);
    double x1 = -1;
    double x2 = -1;
    if (d < 0.0 && fabs(d) > EPS) {
        return (solution) {cnt_zero, -1, -1};
    }
    if (fabs(d) < EPS) {
        x1 = -coeff.b / (2 * coeff.a);
        return (solution) {cnt_one, x1, -1};
    }
    x1 = (-coeff.b + sqrt(d)) / (2 * coeff.a);
    x2 = (-coeff.b - sqrt(d)) / (2 * coeff.a);
    return (solution) {cnt_two, x1, x2};
}

solution solve(const data coeff) {
    if (fabs(coeff.a) < EPS) {
        return line_eq(coeff);
    }
    return square_eq(coeff);
}

