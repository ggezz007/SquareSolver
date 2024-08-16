#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#define EPS 1e-9
#define INF -1
typedef struct solvation solvation;

struct solvation{
    int cnt;
    double x1, x2;
};

void input(double *, double *, double *);
void output(solvation);
double dsmt(const double,const double, const double );
solvation solutions(const double, const double, const double);

int main() {
    double a, b, c;
    input(&a, &b, &c);
    solvation ans = solutions(a, b, c);
    output(ans);
}

void input( double * a,  double * b,  double * c) {
    printf("your coefficients for quadratic equation (a * x^2 + b * x + c = 0): ");
    printf("\nalso remember that b^2, 4*a*c, b^2+4*a*c should be the size  double, so smaller than 1.7E+308");
    printf("\na =");
    scanf(" %lf", a);
    printf("b =");
    scanf(" %lf", b);
    printf("c =");
    scanf(" %lf", c);
}
void output(solvation ans) {
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

solvation solutions(const double a,const double b,const double c) {
    double x1, x2;
    if (abs(a) < EPS) {
        if (abs(b) < EPS) {
            if (abs(c) < EPS) {
                return (solvation) {INF, -1, -1};
            } else {
                return (solvation) {0, -1, -1};
            }
        } else {
            x1 = -c/b;
            return (solvation) {1, x1, -1};
        }
    }
    double d = dsmt(a, b, c);
    if (d < 0.0 && abs(d) > EPS) {
        return (solvation) {0, -1, -1};
    }
    if (abs(d) < EPS) {
        x1 = -(b)/(2*(a));
        return (solvation) {1, x1, -1};
    }
    x1 = (-b + sqrt(d))/(2*a);
    x2 = (-b - sqrt(d))/(2*a);
    return (solvation) {2, x1, x2};
}

