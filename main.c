#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define maxn 100006
#define EPS 1e-9
#define INF 1e9
void input(long double *, long double *, long double *);
int existence_of_the_solution(long double *, long double *, long double *);
long double discriminant(long double *, long double *, long double *);
int existence_of_the_solution(long double *, long double *, long double *);
void solutions(long double *, long double *, long double *);
void solve(long double *, long double *, long double *);

int flag = 0;

int main() {
    long double a, b, c;
    solve(&a, &b, &c);
}

void input(long double * a, long double * b, long double * c) {
    printf("your coefficients for quadratic equation (a * x^2 + b * x + c = 0): ");
    printf("\nalso remember that b^2, 4*a*c, b^2+4*a*c should be the size long double, so smaller than 1.7E+308");
    printf("\na =");
    scanf(" %Lf", a);
    printf("b =");
    scanf(" %Lf", b);
    printf("c =");
    scanf(" %Lf", c);
}

long double discriminant(long double * a, long double * b, long double * c) {
    long double d = (*b)*(*b)-4*(*a)*(*c);
    return d;
}

int existence_of_the_solution(long double * a, long double * b, long double * c) {
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
    long double d = discriminant(a, b, c);
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

void solutions(long double * a, long double * b, long double * c) {
    int cnt_solutions = existence_of_the_solution(a, b, c);
    long double d = discriminant(a, b, c);
    if (cnt_solutions == 0) {
        return;
    }
    if (cnt_solutions == 1) {
        if (flag) {
            long double x = -(*c)/((*b));
            printf("\nx = %Lf", x);
            return;
        }
        long double x = -(*b)/(2*(*a));
        printf("\nx = %Lf", x);
        return;
    }
    if (cnt_solutions == 2) {
        long double x1 = (-(*b) + sqrt(d))/(2*(*a));
        long double x2 = (-(*b) - sqrt(d))/(2*(*a));
        printf("\nx1 = %Lf", x1);
        printf("\nx2 = %Lf", x2);
        return;
    }
    if (cnt_solutions == INF) {
        return;
    }
}

void solve(long double * a, long double * b, long double * c) {
    input(a, b, c);
    solutions(a, b, c);
}