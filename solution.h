#ifndef SOLUTION_H
#define SOLUTION_H

#include "structs.h"

/*!
����� ������������
\param a, b, c ������������ ����������� ���������
\return ������������
*/

double get_diskriminant(const double a, const double b, const double c);

/*!
������ �������� ���������
\param coeff ��������� � �������������� ����������� ���������
\return ��������� �������
*/

Solution line_eq(const Data coeff);

/*!
������ ���������� ���������
\param coeff ��������� � �������������� ����������� ���������
\return ��������� �������
*/

Solution square_eq(const Data coeff);

/*!
��������� ������� ����������� ��������� � ����� ����
\param coeff ��������� � �������������� ����������� ���������
\return ��������� �������
*/

Solution solve(const Data coeff);

/*!
�������� ����� �� �������������� eps ����������� 0
\param d �����
\return ����������� �� ����� � eps ����������� 0
*/

int is_zero(const double d);

#endif //SOLUTION_H
