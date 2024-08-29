#ifndef SOLUTION_H
#define SOLUTION_H

#include "structs.h"

/*!
Берет дискриминант
\param a, b, c коэффициенты квадратного уравнения
\return дискриминант
*/

double get_diskriminant(const double a, const double b, const double c);

/*!
Решает линейное уравнение
\param coeff структура с коэффициентами квадратного уравнения
\return структура решение
*/

Solution line_eq(const Data coeff);

/*!
Решает квадратное уравнение
\param coeff структура с коэффициентами квадратного уравнения
\return структура решение
*/

Solution square_eq(const Data coeff);

/*!
Запускает решение квадратного уравнения в общем виде
\param coeff структура с коэффициентами квадратного уравнения
\return структура решение
*/

Solution solve(const Data coeff);

/*!
Проверка числа на принадлежность eps окрестности 0
\param d число
\return принадлежит ли число к eps окрестности 0
*/

int is_zero(const double d);

#endif //SOLUTION_H
