#ifndef CMP_H
#define CMP_H

#include "structs.h"

/*!
Запускает unit test
\param test[] unit_test
\param len_array число тестов
*/

void check_solve(const Unit_test test[], const int len_array);

/*!
Cравнивает ответы, данные программой с верными
\param coeff коэффициенты
\param correct ans верный ответ на тест
\return результат сравнения
*/

Status compare(const Data coeff, const Solution correct_ans);

#endif // CMP_H
