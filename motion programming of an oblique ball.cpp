#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

int main() {
    double v0, angle_deg, h;
    double g = 9.8;

    // �Է�
    cout << "�ʱ� �ӵ� (m/s): ";
    cin >> v0;

    cout << "�߻� ���� (��): ";
    cin >> angle_deg;

    cout << "��� ���� (m): ";
    cin >> h;

    // ���� -> ���� ��ȯ
    double angle_rad = angle_deg * PI / 180.0;

    // �ʱ� �ӵ� x, y ����
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    // (1) �ð� ��� (2�� ������)
    // 0 = h + v0y * t - 0.5 * g * t^2 �� 0 = -4.9t^2 + v0y*t + h
    double a = -0.5 * g;
    double b = v0y;
    double c = h;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << "�ذ� �������� ����\n";
        return 1;
    }

    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    double t = max(t1, t2); // ��� �ð��� ����

    // (2) ���� �Ÿ�
    double x = v0x * t;

    // (3) �浹 ���� �ӵ� ����
    double vy_final = v0y - g * t;

    // (4) �ӵ� ũ�� �� ����
    double v_final = sqrt(v0x * v0x + vy_final * vy_final);
    double theta_final = atan2(vy_final, v0x) * 180 / PI;

    // ���
    cout << "\n�浹���� �ð�: " << t << " ��\n";
    cout << "���� �Ÿ�: " << x << " m\n";
    cout << "�浹 ���� �ӵ� ũ��: " << v_final << " m/s\n";
    cout << "�ӵ� ���� (x�� ���� ����): " << theta_final << " ��\n";

    return 0;
}