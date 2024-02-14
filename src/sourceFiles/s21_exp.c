#include "../s21_math.h"

long double s21_exp(double x) {
  long double n = 0;
  long double result = 0;
  long double multiplier = 1.0;
  int is_neg = x < 0;
  if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = 0;
  } else if (isNAN(x)) {
    result = -S21_NAN;
  } else {
    x = s21_fabs(x);
    for (int i = 0; i < 400; i++) {
      result += multiplier;
      multiplier *= (x / ++n);
    }
  }
  if (is_neg == 1 && !isINF(x)) {
    result = 1.0 / result;
  }
  return result;
}