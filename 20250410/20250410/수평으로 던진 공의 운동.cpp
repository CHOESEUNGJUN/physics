/*
�������� ���� ���� � 
*/

#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;

// �߷°��ӵ� ���
const double g = 9.8;

int main() {
    double v0, angle_deg;

    printf("�ʱ� �ӵ� (m/s)�� �Է��ϼ���: ");
    scanf_s("%lf", &v0);
    printf("���� (��)�� �Է��ϼ���: ");
    scanf_s("%lf", &angle_deg);

    // ������ �������� ��ȯ
    double angle_rad = angle_deg * M_PI / 180.0;

    // x, y ������ �ʱ�ӵ��� ���Ͽ���
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    // �ְ����� ���̸� ���Ͽ���
    double h = (v0y * v0y) / (2 * g);

    // �ְ����� �����ϴ� �ð��� ���Ͽ���
    double t_top = v0y / g;

    // �������� �̵��� �ְ� �Ÿ��� ���Ͽ���
    double t_total = 2 * t_top;         // ��ü ���� �ð�
    double x_total = v0x * t_total;     // ��ü ���� �Ÿ�

    // ��� ���
    printf("\n[��� ���]\n");
    printf("1. �ʱ� �ӵ� x ����: %.2f m/s\n", v0x);
    printf("1. �ʱ� �ӵ� y ����: %.2f m/s\n", v0y);
    printf("2. �ְ��� ����: %.2f m\n", h);
    printf("3. �ְ��� ���� �ð�: %.2f ��\n", t_top);
    printf("4. ���� �̵� �Ÿ�: %.2f m\n", x_total);

    return 0;
}