#ifndef CMP_H
#define CMP_H

#include "structs.h"

/*!
��������� unit test
\param test[] unit_test
\param len_array ����� ������
*/

void check_solve(const Unit_test test[], const int len_array);

/*!
C��������� ������, ������ ���������� � �������
\param coeff ������������
\param correct ans ������ ����� �� ����
\return ��������� ���������
*/

Status compare(const Data coeff, const Solution correct_ans);

#endif // CMP_H
