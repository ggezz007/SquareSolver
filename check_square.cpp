#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define maxn 100006
#define EPS 1e-9
#define INF 1e9
void input( double *,  double *,  double *);
int existence_of_the_solution( double *,  double *,  double *);
 double discriminant( double *,  double *,  double *);
int existence_of_the_solution( double *,  double *,  double *);
void solutions( double *,  double *,  double *);
void solve( double *,  double *,  double *);

int flag = 0;

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

 double discriminant( double * a,  double * b,  double * c) {
     double d = (*b)*(*b)-4*(*a)*(*c);
    return d;
}

int existence_of_the_solution( double * a,  double * b,  double * c) {
    if ((*a) == 0 || abs(*a) < EPS) {
        if ((*b) == 0 ||  abs(*b) < EPS) {
            if ((*c) == 0 ||  abs(*c) < EPS) {
                printf("your equation has INF solutions in R quantity");
                return INF;
            } else {
                printf("your equation has not solutions in R quantity");
                return 0;
            }
        } else {
            printf("your equation has one solution in R quantity:");
            flag = 1;
            return 1;
        }
    }
     double d = discriminant(a, b, c);
    if (d < 0 && abs(d) > EPS) {
        printf("your equation has not solutions in R quantity");
        return 0;
    } else if ((d < 0 && abs(d) < EPS) || d == 0) {
        printf("your equation has one solution in R quantity:");
        return 1;
    } else {
        printf("your equation has two solutions in R quantity");
        return 2;
    }
}

void solutions( double * a,  double * b,  double * c) {
    int cnt_solutions = existence_of_the_solution(a, b, c);
     double d = discriminant(a, b, c);
    if (cnt_solutions == 0) {
        return;
    }
    if (cnt_solutions == 1) {
        if (flag) {
             double x = -(*c)/((*b));
            printf("\nx = %lf", x);
            return;
        }
         double x = -(*b)/(2*(*a));
        printf("\nx = %lf", x);
        return;
    }
    if (cnt_solutions == 2) {
         double x1 = (-(*b) + sqrt(d))/(2*(*a));
         double x2 = (-(*b) - sqrt(d))/(2*(*a));
        printf("\nx1 = %lf", x1);
        printf("\nx2 = %lf", x2);
        return;
    }
    if (cnt_solutions == INF) {
        return;
    }
}

void solve( double * a,  double * b,  double * c) {
    input(a, b, c);
    solutions(a, b, c);
}
