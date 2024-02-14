#include "../s21_math.h"

long double s21_floor(double x) {
  if (x == S21_MAX || x == S21_INF || x == -S21_INF || isNAN(x)) return x;
  long int m = (long int)x;
  long double fractional = x - m;
  long double r = (long double)m;
  return x >= 0 ? r : fractional != 0 ? r - 1 : r;
}