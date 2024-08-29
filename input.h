#ifndef INPUT_H
#define INPUT_H

#include "structs.h"

/*!
������� ������� ����� ������
*/

void clean_stdin(void);

/*!
���� ������ �� ������������� ����������� ���������
\param d �����������
\return ���������� �� ����
*/

Status input_coef_x(double *d);

/*!
��������� � �������� ������� ������� ������
*/

void output_wrong(void);

/*!
���� ���� ������������� ����������� ���������
\param coeff ��������� � �������������� ����������� ���������
*/

void input(Data * coeff);

#endif //INPUT_H

