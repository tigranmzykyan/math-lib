
#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  if (!exp) return 1;
  if (base == -S21_INF && exp == -S21_INF) return 0;
  if (base == -S21_INF && exp == S21_INF) return S21_INF;
  if (base < 0 && exp != (long long int)exp) return S21_NAN;
  long double res = 0;
  int sign = base < 0 ? -1 : 1;
  res = s21_exp(exp * s21_log(base * sign));
  if (s21_fmod(exp, 2)) res *= sign;
  return res;
}