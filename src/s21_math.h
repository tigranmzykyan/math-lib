#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_INF 1.0f / 0.0f
#define S21_NEGZERO -0.0
#define S21_E 2.71828182845904523536
#define S21_NAN 0.0f / 0.0f
#define S21_EPS 1e-16
#define S21_SQRT_EPS 1e-20
#define S21_SQRT_3 ((float)1.732050807569)
#define S21_LIMIT 0.00000000000000000001
#define S21_PI 3.14159265358979323846
#define S21_PI_2 1.570796326
#define S21_PI_4 0.785398163
#define S21_PI_12 0.26179938
#define S21_MAX 1.7976931348623158e+308
#define isNAN(x) (x != x)
#define isINF(x) (!isNAN(x) && isNAN(x - x))
#define isPOS_INF(x) (x == S21_INF)
#define isNEG_INF(x) (x == -S21_INF)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);