#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846 // ¼±¾ğ

int main() {
    double angle_degree, x, y, r, theta_radian;

    // (°¢µµ)
    printf("°¢µµ: ");
    scanf_s("%lf", &angle_degree);

    // °¢µµ ==> ¶óµğ¾È
    double angle_radian = angle_degree * M_PI / 180;
    printf("angle_radian: %f\n", angle_radian);

    //»ï°¢ÇÔ¼ö
    printf("cos(%f): %f\n", angle_radian, cos(angle_radian));
    printf("sin(%f): %f\n", angle_radian, sin(angle_radian));
    printf("tan(%f): %f\n", angle_radian, tan(angle_radian));

    // Á÷±³ÁÂÇ¥
    printf("x¿Í y ÁÂÇ¥: ");
    scanf_s("%lf %lf", &x, &y);

    // Á÷±³ ÁÂÇ¥ -> ±ØÁÂÇ¥
    r = sqrt(x * x + y * y);
    theta_radian = atan2(y, x);
    printf("±ØÁÂÇ¥: r = %f, theta = %f\n", r, theta_radian);

    // ±ØÁÂÇ¥ º¯È¯¿ë ¹İÁö¸§
    printf("±ØÁÂÇ¥ º¯È¯ ¹İÁö¸§: ");
    scanf_s("%lf", &r);

    // ±ØÁÂÇ¥ -> Á÷±³ ÁÂÇ¥ 
    double x_new = r * cos(angle_radian);
    double y_new = r * sin(angle_radian);
    printf("Á÷±³ ÁÂÇ¥: x = %f, y = %f\n", x_new, y_new);

    return 0;
}