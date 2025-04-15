#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

int main() {
    double v0, angle_deg, h;
    double g = 9.8;

    // 입력
    cout << "초기 속도 (m/s): ";
    cin >> v0;

    cout << "발사 각도 (도): ";
    cin >> angle_deg;

    cout << "출발 높이 (m): ";
    cin >> h;

    // 각도 -> 라디안 변환
    double angle_rad = angle_deg * PI / 180.0;

    // 초기 속도 x, y 성분
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    // (1) 시간 계산 (2차 방정식)
    // 0 = h + v0y * t - 0.5 * g * t^2 → 0 = -4.9t^2 + v0y*t + h
    double a = -0.5 * g;
    double b = v0y;
    double c = h;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << "해가 존재하지 않음\n";
        return 1;
    }

    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    double t = max(t1, t2); // 양수 시간만 선택

    // (2) 수평 거리
    double x = v0x * t;

    // (3) 충돌 순간 속도 성분
    double vy_final = v0y - g * t;

    // (4) 속도 크기 및 방향
    double v_final = sqrt(v0x * v0x + vy_final * vy_final);
    double theta_final = atan2(vy_final, v0x) * 180 / PI;

    // 출력
    cout << "\n충돌까지 시간: " << t << " 초\n";
    cout << "수평 거리: " << x << " m\n";
    cout << "충돌 순간 속도 크기: " << v_final << " m/s\n";
    cout << "속도 방향 (x축 기준 각도): " << theta_final << " 도\n";

    return 0;
}