#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (isINF(x) || x == 0 || x == S21_NEGZERO || isNAN(x) || x == DBL_MAX) {
    res = x;
  } else if (x == DBL_MIN) {
    res = 1;
  } else {
    if (s21_fabs(x) > 0. && x != res)
      if (x > 0.) {
        res += 1;
      }
  }
  return res;
}