#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "structs.h"
#include "solution.h"

#define EPS 1e-9

int is_zero(const double d) {
    return fabs(d) < EPS;
}

double get_diskriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

Solution line_eq(const Data coeff) {
    if (is_zero(coeff.b)) {
        if (is_zero(coeff.c)) {
            return (Solution) {CNT_INFINITY, NAN, NAN};
        } else {
            return (Solution) {CNT_ZERO, NAN, NAN};
        }
    }
    return (Solution) {CNT_ONE, -coeff.c / coeff.b, NAN};
}

Solution square_eq(const Data coeff) {
    assert(!isnan(coeff.a));
    assert(!isnan(coeff.b));
    assert(!isnan(coeff.c));

    double d = get_diskriminant(coeff.a, coeff.b, coeff.c);
    double x1 = NAN;
    double x2 = NAN;

    if (d < 0.0 && !is_zero(d)) {
        return (Solution) {CNT_ZERO, NAN, NAN};
    }

    if (is_zero(d)) {
        x1 = -coeff.b / (2 * coeff.a);
        assert(!isnan(x1));
        return (Solution) {CNT_ONE, x1, NAN};
    }
    x1 = (-coeff.b + sqrt(d)) / (2 * coeff.a);
    x2 = (-coeff.b - sqrt(d)) / (2 * coeff.a);
    assert(!isnan(x1));
    assert(!isnan(x2));
    return (Solution) {CNT_TWO, x1, x2};
}

Solution solve(const Data coeff) {
    if (is_zero(coeff.a)) {
        return line_eq(coeff);
    }
    return square_eq(coeff);
}
