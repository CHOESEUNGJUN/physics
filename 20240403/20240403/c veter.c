#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846 // 선언

int main() {
    double angle_degree, x, y, r, theta_radian;

    // (각도)
    printf("각도를 입력하세요 (degree): ");
    scanf_s("%lf", &angle_degree);

    // 각도 ==> 라디안
    double angle_radian = angle_degree * M_PI / 180;
    printf("angle_radian: %f\n", angle_radian);

    //삼각함수
    printf("cos(%f): %f\n", angle_radian, cos(angle_radian));
    printf("sin(%f): %f\n", angle_radian, sin(angle_radian));
    printf("tan(%f): %f\n", angle_radian, tan(angle_radian));

    // 직교좌표
    printf("x와 y 좌표를 입력하세요 (공백으로 구분): ");
    scanf_s("%lf %lf", &x, &y);

    // 직교 좌표 -> 극좌표
    r = sqrt(x * x + y * y);
    theta_radian = atan2(y, x);
    printf("극좌표: r = %f, theta = %f\n", r, theta_radian);

    // 극좌표 변환용 반지름
    printf("극좌표 변환을 위한 반지름을 입력하세요: ");
    scanf_s("%lf", &r);

    // 극좌표 -> 직교 좌표 
    double x_new = r * cos(angle_radian);
    double y_new = r * sin(angle_radian);
    printf("직교 좌표: x = %f, y = %f\n", x_new, y_new);

    return 0;
}