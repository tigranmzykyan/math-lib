#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  if (y == 0.0 || x == S21_INF || x == -S21_INF || isNAN(y)) return S21_NAN;
  long long int mantisa = (long long int)(x / y);
  long double m = (long double)mantisa;
  return isINF(y) ? x : x - m * y;
}