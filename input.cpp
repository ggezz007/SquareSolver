#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "structs.h"
#include "input.h"

void clean_stdin() {
    while (getchar() != '\n');
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

void output_wrong() {
    printf("input should contain only numbers from range 0-9, '.', '-'.\n"
           "Please try again\n");
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
