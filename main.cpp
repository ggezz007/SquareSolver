#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#define EPS 1e-9
#define INF -1
typedef struct solution solution;
typedef struct data data;

struct solution{
    int cnt;
    double x1, x2;
};
struct data{
    double a, b, c;
};
void input(data *);
void output(const solution);
double dsmt(const double,const double, const double );
solution solve(const data);

int main() {
    data koef;
    input(&koef);
    solution ans = solve(koef);
    output(ans);
}

void input(data * koef) {
    printf("your coefficients for quadratic equation (a * x^2 + b * x + c = 0): ");
    printf("\nalso remember that b^2, 4*a*c, b^2+4*a*c should be the size  double, so smaller than 1.7E+308");
    printf("\na =");
    scanf(" %lf", &(koef->a));
    printf("b =");
    scanf(" %lf", &(koef->b));
    printf("c =");
    scanf(" %lf",  &(koef->c));
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
double dsmt(const double a,const double  b,const double  c) {
    return b*b-4*a*c;
}
solution inf_eq(const data koef) {
    if (abs(koef.a) < EPS) {
        if (abs(koef.b) < EPS) {
            if (abs(koef.c) < EPS) {
                return (solution) {INF, -1, -1};
            }
        }
    }
    return (solution) {-2, -2, -2};
}
solution zero_eq(const data koef) {
    if (abs(koef.a) < EPS) {
        if (abs(koef.b) < EPS) {
            return (solution) {0, -1, -1};
        }
    }
    return (solution) {-2, -2, -2};
}
solution line_eq(const data koef) {
    if (abs(koef.a) < EPS) {
        return (solution) {1, -koef.c/koef.b, -1};
    }
    return (solution) {-2, -2, -2};
}
solution square_eq(const data koef) {
    double d = dsmt(koef.a, koef.b, koef.c), x1, x2;
    if (d < 0.0 && abs(d) > EPS) {
        return (solution) {0, -1, -1};
    }
    if (abs(d) < EPS) {
        x1 = -(koef.b)/(2*(koef.a));
        return (solution){1, x1, -1};
    }
    x1 = (-koef.b + sqrt(d))/(2*koef.a);
    x2 = (-koef.b - sqrt(d))/(2*koef.a);
    return (solution) {2, x1, x2};
}
solution solve(const data koef) {
    solution ans;
    ans = inf_eq(koef);
    if (ans.cnt != -2) {
        return ans;
    }
    ans = zero_eq(koef);
    if (ans.cnt != -2) {
        return ans;
    }
    ans = line_eq(koef);
    if (ans.cnt != -2) {
        return ans;
    }
    ans = square_eq(koef);
    return ans;
}


