#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#define EPS 1e-9
#define INF -1
void input(double *, double *, double *);
void output(const int, const double, const double );
double discriminant(const double,const double,const double );
int existence_of_the_solution(const double,const double,const double);
void solutions(const double, const double, const double);
void solve(double *, double *, double *);


int main() {
    double a, b, c;
    solve(&a, &b, &c);
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
void output(const int cnt,const double x1,const double x2) {
    if (cnt == -1) {
        printf("your equation has INF solutions in R quantity");
    } else if (cnt == 0) {
        printf("your equation has not solutions in R quantity");
    } else if (cnt == 1) {
        printf("your equation has one solution in R quantity:");
        printf("\nx = %lf", x1);
    } else {
        printf("your equation has two solutions in R quantity:");
        printf("\nx1 = %lf", x1);
        printf("\nx2 = %lf", x2);
    }
}
double discriminant(const double a,const double  b,const double  c) {
    double d = (b)*(b)-4*(a)*(c);
    return d;
}

int existence_of_the_solution(const double a,const double b,const double c) {
    if (abs(a) < EPS) {
        if (abs(b) < EPS) {
            if (abs(c) < EPS) {
                return INF;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    }
    double d = discriminant(a, b, c);
    if (d < 0 && abs(d) > EPS) {
        return 0;
    } else if (abs(d) < EPS) {
        return 1;
    } else {
        return 2;
    }
}

void solutions(const double a,const double b,const double c) {
    int cnt_solutions = existence_of_the_solution(a, b, c);
    double d = discriminant(a, b, c);
    double x1 = -1.0, x2 = -1.0;
    if (cnt_solutions == 0) {
        output(0, x1, x2);
        return;
    }
    if (cnt_solutions == 1) {
        if (abs(a)<EPS) {
            x1 = -c/b;
            output(1, x1, x2);
            return;
        }
        x1 = -(b)/(2*(a));
        output(1, x1, x2);
        return;
    }
    if (cnt_solutions == 2) {
        x1 = (-(b) + sqrt(d))/(2*(a));
        x2 = (-(b) - sqrt(d))/(2*(a));
        output(2, x1, x2);
        return;
    }
    if (cnt_solutions == INF) {
        output(-1, x1, x2);
        return;
    }
}

void solve(double * a,  double * b,  double * c) {
    input(a, b, c);
    solutions(*a, *b, *c);
}
