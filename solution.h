#ifndef SOLUTION_H
#define SOLUTION_H

#include "structs.h"

double get_diskriminant(const double a, const double b, const double c);

Solution line_eq(const Data coeff);

Solution square_eq(const Data coeff);

Solution solve(const Data coeff);

int is_zero(const double d);

#endif
