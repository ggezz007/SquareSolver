#ifndef INPUT_H
#define INPUT_H

#include "structs.h"

/*!
Очищает входной поток данных
*/

void clean_stdin(void);

/*!
Ввод одного из коэффициентов квадратного уравнения
\param d коэффициент
\return корректный ли ввод
*/

Status input_coef_x(double *d);

/*!
Сообщение о неверном формате входных данных
*/

void output_wrong(void);

/*!
Ввод всех коэффициентов квадратного уравнения
\param coeff структура с коэффициентами квадратного уравнения
*/

void input(Data * coeff);

#endif //INPUT_H

