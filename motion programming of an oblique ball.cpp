#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    double v0, angle_deg, h;
    const double g = 9.8;

    printf("초기 속도 v0 (m/s): ");
    scanf_s("%lf", &v0);

    printf("발사 각도 (도): ");
    scanf_s("%lf", &angle_deg);

    printf("초기 높이 h (m): ");
    scanf_s("%lf", &h);

    // 각도 변환
    double angle_rad = angle_deg * PI / 180.0;

    // 속도 성분 분해
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    // (1) 시간 계산 (이차방정식)
    double a = -0.5 * g;
    double b = v0y;
    double c = h;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        printf("해가 존재하지 않습니다.\n");
        return 1;
    }

    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    double t = (t1 > t2) ? t1 : t2;

    // (2) 수평 거리
    double x = v0x * t;

    // (3) 충돌 순간 속도 성분
    double vx = v0x;
    double vy = v0y - g * t;

    // (4) 속도 크기
    double v = sqrt(vx * vx + vy * vy);

    // (5) 속도 방향 각도
    double theta = atan2(vy, vx) * 180 / PI;

    // 출력
    printf("\n1 충돌까지 시간: %.2f 초\n", t);
    printf("2 수평 거리: %.2f m\n", x);
    printf("3 충돌 순간 속도 성분 - Vx: %.2f m/s, Vy: %.2f m/s\n", vx, vy);
    printf("4 충돌 순간 속도 크기: %.2f m/s\n", v);
    printf("5 속도 방향 각도 (수평 기준): %.2f 도\n", theta);

    return 0;
}