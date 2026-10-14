#define _USE_MATH_DEFINES 
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

int func();
int func2();
int func3_a();

double uravn(double x_, double y_, double z_);

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	double x, y, z, c;
	x = 3.251;
	y = 0.325;
	z = 0.466e-4;
	c = uravn(x,y,z);
	
	printf("Исходные данные:\n");
	printf("  x = %.3f\n", x);
	printf("  y = %.3f\n", y);
	printf("  z = %.7f (%.3e)\n", z, z);
	printf("\nРезультат вычислений:\n");
	printf("  c = %.6f\n", c);
	printf("Ожидаемый ответ из таблицы:\n");
	printf("  c = 4.251433\n");

	return 0;
}


int func()
{
	double gr;
	printf("Введите значение угла в градусах: ");
	if (scanf("%lf", &gr) != 1) {
		printf("Ошибка ввода.\n");
		return 1;
	}
	double rad = gr * M_PI / 180;
	double rez = sin(rad);
	printf("Результат %.6f\n", rez);
	return 0;
}

int func2()
{
	double t = 0.43;
	double x;
	double b, y;
	printf("Введём x: ");
	if (scanf("%lf", &x) != 1) {
		printf("Ошибка ввода.\n");
		return 1;
	}

	b = x * (pow(t, 3) + x);
	y = pow(log10(fabs(x)), 3) + b;
	printf("Найдём b = %lf\n", b);
	printf("Найдём y = %lf\n", y);
	printf("\nКонстанта t = %.2f\n", t);
	printf("x = %.1f\n", x);
	printf("y = %.4f\n", y);
	return 0;

}

int func3_a()
{
	double a = 4.5;
	double b = 7.1;
	double y = 9.9;

	int A = (int)a;
	int B = (int)b;
	int C = (int)y;

	int a_con = (A % 2 == 0) != (B % 2 == 0);
	int b_con = (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);

	printf("Использованные числа A = %d, B = %d, C = %d\n\n", A, B, C);
	printf("Условие а) выполнено 1 - да, 0 - нет): %d\n", a_con);
	printf("Условие б) выполнено 1 - да, 0 - нет): %d\n", b_con);
	return 0;
}

double uravn(double x_, double y_, double z_)
{
	double c;
	double part1, part2, num, denom;
	
	part1 = pow(pow(2.0, y_), x_);
	part2 = pow(pow(3.0, x_), y_);

	num = y_ * (atan(z_) - M_PI / 6.0);
	denom = fabs(x_) + 1.0 / (y_ * y_ + 1.0);
	c = part1 + part2 - (num / denom);
	return c;
}
