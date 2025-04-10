/*
수평으로 던지 공의 운동 
*/

#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;

// 중력가속도 상수
const double g = 9.8;

int main() {
    double v0, angle_deg;

    printf("초기 속도 (m/s)를 입력하세요: ");
    scanf_s("%lf", &v0);
    printf("각도 (도)를 입력하세요: ");
    scanf_s("%lf", &angle_deg);

    // 각도를 라디안으로 변환
    double angle_rad = angle_deg * M_PI / 180.0;

    // x, y 방향의 초기속도를 구하여라
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    // 최고점의 높이를 구하여라
    double h = (v0y * v0y) / (2 * g);

    // 최고점에 도착하는 시간을 구하여라
    double t_top = v0y / g;

    // 수평으로 이동한 최고 거리를 구하여라
    double t_total = 2 * t_top;         // 전체 비행 시간
    double x_total = v0x * t_total;     // 전체 수평 거리

    // 결과 출력
    printf("\n[결과 출력]\n");
    printf("1. 초기 속도 x 성분: %.2f m/s\n", v0x);
    printf("1. 초기 속도 y 성분: %.2f m/s\n", v0y);
    printf("2. 최고점 높이: %.2f m\n", h);
    printf("3. 최고점 도달 시간: %.2f 초\n", t_top);
    printf("4. 수평 이동 거리: %.2f m\n", x_total);

    return 0;
}