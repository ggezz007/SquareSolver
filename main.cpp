#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define EPS 1e-9
#define INF -1
struct solution {
    int cnt;
    double x1, x2;
};
struct data {
    double a, b, c;
};

void input(data *coeff);

void output(const solution ans);

double get_diskriminant(const double a, const double b, const double c);

solution inf_eq(const data coeff);

solution zero_eq(const data coeff);

solution line_eq(const data coeff);

solution square_eq(const data coeff);

solution solve(const data coeff);

int main() {
    data coeff;
    input(&coeff);
    solution ans = solve(coeff);
    output(ans);
}

void input(data *coeff) {
    printf("your coefficients for quadratic equation (a * x^2 + b * x + c = 0): ");
    printf("\nalso remember that b^2, 4*a*c, b^2+4*a*c should be the size  double, so smaller than 1.7E+308");
    printf("\na =");
    scanf(" %lf", &(coeff->a));
    printf("b =");
    scanf(" %lf", &(coeff->b));
    printf("c =");
    scanf(" %lf", &(coeff->c));
}

void output(const solution ans) {
    if (ans.cnt == INF) {
        printf("your equation has INF solutions in R quantity");
    } else if (ans.cnt == 0) {
        printf("your equation has not solutions in R quantity");
    } else if (ans.cnt == 1) {
        printf("your equation has one solution in R quantity:");
        printf("\nx = %lf", ans.x1);
    } else {
        printf("your equation has two solutions in R quantity:");
        printf("\nx1 = %lf", ans.x1);
        printf("\nx2 = %lf", ans.x2);
    }
}

double get_diskriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

solution inf_eq(const data coeff) {
    return (solution) {INF, -1, -1};
}

solution zero_eq(const data coeff) {
    return (solution) {0, -1, -1};
}

solution line_eq(const data coeff) {
    return (solution) {1, -coeff.c / coeff.b, -1};
}

solution square_eq(const data coeff) {
    double d = get_diskriminant(coeff.a, coeff.b, coeff.c), x1, x2;
    if (d < 0.0 && abs(d) > EPS) {
        return (solution) {0, -1, -1};
    }
    if (abs(d) < EPS) {
        x1 = -(coeff.b) / (2 * (coeff.a));
        return (solution) {1, x1, -1};
    }
    x1 = (-coeff.b + sqrt(d)) / (2 * coeff.a);
    x2 = (-coeff.b - sqrt(d)) / (2 * coeff.a);
    return (solution) {2, x1, x2};
}

solution solve(const data coeff) {
    if (abs(coeff.a) < EPS) {
        if (abs(coeff.b) < EPS) {
            if (abs(coeff.c) < EPS) {
                return inf_eq(coeff);
            } else {
                return zero_eq(coeff);
            }
        } else {
            return line_eq(coeff);
        }
    }
    return square_eq(coeff);
}
