#include "s21_math.h"

#include <check.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define PRECISION 1e-6

START_TEST(test_abs) {
  int n = 0;
  ck_assert_int_eq(abs(n), s21_abs(n));
  n = -12345;
  ck_assert_int_eq(abs(n), s21_abs(n));
  n = 12345;
  ck_assert_int_eq(abs(n), s21_abs(n));
  n = INT_MAX;
  ck_assert_int_eq(abs(n), s21_abs(n));
  n = INT_MIN;
  ck_assert_int_eq(abs(n), s21_abs(n));
}
END_TEST

START_TEST(test_fabs) {
  double n = 0;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = -12345.0;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = 12345.0;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = 12345.123456;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = -12345.123456;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = DBL_MAX;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = DBL_MAX - 1;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = DBL_MIN;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = INFINITY;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = -S21_INF;
  ck_assert_ldouble_eq(fabs(n), s21_fabs(n));
  n = NAN;
  ck_assert_ldouble_nan(n);
  ck_assert_ldouble_nan(fabs(n));
  ck_assert_ldouble_nan(s21_fabs(n));
}
END_TEST

START_TEST(test_ceil) {
  double n = 0;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = -12345.0;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = 12345.0;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = -12345.124567;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = 12345.1234567;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = DBL_MAX;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = DBL_MAX - 1;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = DBL_MIN;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = INFINITY;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = -S21_INF;
  ck_assert_ldouble_eq(ceil(n), s21_ceil(n));
  n = NAN;
  ck_assert_ldouble_nan(n);
  ck_assert_ldouble_nan(ceil(n));
  ck_assert_ldouble_nan(s21_ceil(n));
}
END_TEST

START_TEST(test_floor) {
  double n = 0;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = -12345.0;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = 12345.0;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = -12345.124567;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = 12345.1234567;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = DBL_MAX;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = DBL_MAX - 1;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = DBL_MIN;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = INFINITY;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
  n = -S21_INF;
  ck_assert_ldouble_eq(floor(n), s21_floor(n));
}
END_TEST

START_TEST(test_fmod) {
  double x = 5.3, y = 2.1;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = 2.1, y = 5.3;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = 0.0, y = 5.3;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = 5.3, y = 0.0;
  ck_assert_ldouble_nan(fmod(x, y));
  ck_assert_ldouble_nan(s21_fmod(x, y));

  x = -1234.5678, y = 45.32;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = 1234.5678, y = -45.32;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = -1234.5678, y = -45.32;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = 1234.5678, y = INFINITY;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = 1234.5678, y = -S21_INF;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = -1234.5678, y = INFINITY;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = -1234.5678, y = -S21_INF;
  ck_assert_ldouble_eq(fmod(x, y), s21_fmod(x, y));
  x = INFINITY, y = 43.2;
  ck_assert_ldouble_nan(fmod(x, y));
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = -S21_INF, y = 43.2;
  ck_assert_ldouble_nan(fmod(x, y));
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = NAN, y = 43.2;
  ck_assert_ldouble_nan(fmod(x, y));
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 123.456, y = NAN;
  ck_assert_ldouble_nan(fmod(x, y));
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(test_sin) {
  double n = 0.;
  ck_assert_double_eq_tol(sin(n), s21_sin(n), PRECISION);
  n = -0.;
  ck_assert_double_eq_tol(sin(n), s21_sin(n), PRECISION);
  n = 1.0;
  ck_assert_double_eq_tol(sin(n), s21_sin(n), PRECISION);
  n = -1.0;
  ck_assert_double_eq_tol(sin(n), s21_sin(n), PRECISION);
  n = 12345.123456;
  ck_assert_double_eq_tol(sin(n), s21_sin(n), PRECISION);
  n = -12345.123456;
  ck_assert_double_eq_tol(sin(n), s21_sin(n), PRECISION);
  n = INFINITY;
  ck_assert_double_nan(sin(n));
  ck_assert_double_nan(s21_sin(n));
  n = NAN;
  ck_assert_double_nan(sin(n));
  ck_assert_double_nan(s21_sin(n));
}
END_TEST

START_TEST(test_cos) {
  double n = 0.;
  ck_assert_double_eq_tol(cos(n), s21_cos(n), PRECISION);
  n = -0.;
  ck_assert_double_eq_tol(cos(n), s21_cos(n), PRECISION);
  n = 1.0;
  ck_assert_double_eq_tol(cos(n), s21_cos(n), PRECISION);
  n = -1.0;
  ck_assert_double_eq_tol(cos(n), s21_cos(n), PRECISION);
  n = 12345.123456;
  ck_assert_double_eq_tol(cos(n), s21_cos(n), PRECISION);
  n = -12345.123456;
  ck_assert_double_eq_tol(cos(n), s21_cos(n), PRECISION);
  n = INFINITY;
  ck_assert_double_nan(cos(n));
  ck_assert_double_nan(s21_cos(n));
  n = NAN;
  ck_assert_double_nan(cos(n));
  ck_assert_double_nan(s21_cos(n));
}
END_TEST

START_TEST(test_tan) {
  double n = 0.;
  ck_assert_ldouble_eq_tol(tan(n), s21_tan(n), PRECISION);
  n = -0.;
  ck_assert_ldouble_eq_tol(tan(n), s21_tan(n), PRECISION);
  n = 1.0;
  ck_assert_ldouble_eq_tol(tan(n), s21_tan(n), PRECISION);
  n = -1.0;
  ck_assert_ldouble_eq_tol(tan(n), s21_tan(n), PRECISION);
  n = 12345.123456;
  ck_assert_ldouble_eq_tol(tan(n), s21_tan(n), PRECISION);
  n = -12345.123456;
  ck_assert_ldouble_eq_tol(tan(n), s21_tan(n), PRECISION);
  n = INFINITY;
  ck_assert_ldouble_nan(tan(n));
  ck_assert_ldouble_nan(s21_tan(n));
  n = NAN;
  ck_assert_ldouble_nan(tan(n));
  ck_assert_ldouble_nan(s21_tan(n));
}
END_TEST

START_TEST(test_atan) {
  double n = 0.;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = -0.;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = 1.0;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = -1.0;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = 12345.123456;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = 21.42;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = -12345.123456;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = -S21_INF;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = -S21_INF;
  ck_assert_ldouble_eq_tol(atan(n), s21_atan(n), PRECISION);
  n = NAN;
  ck_assert_ldouble_nan(atan(n));
  ck_assert_ldouble_nan(s21_atan(n));
}
END_TEST

START_TEST(test_acos) {
  double n = 0.;
  ck_assert_ldouble_eq_tol(acos(n), s21_acos(n), PRECISION);
  n = -0.;
  ck_assert_double_eq_tol(acos(n), s21_acos(n), PRECISION);
  n = 1.0;
  ck_assert_ldouble_eq_tol(acos(n), s21_acos(n), PRECISION);
  n = -1.0;
  ck_assert_ldouble_eq_tol(acos(n), s21_acos(n), PRECISION);
  n = 12345.123456;
  ck_assert_ldouble_nan(acos(n));
  ck_assert_ldouble_nan(s21_acos(n));

  n = -12345.123456;
  ck_assert_ldouble_nan(acos(n));
  ck_assert_ldouble_nan(s21_acos(n));
  n = INFINITY;
  ck_assert_ldouble_nan(acos(n));
  ck_assert_ldouble_nan(s21_acos(n));
  n = NAN;
  ck_assert_ldouble_nan(acos(n));
  ck_assert_ldouble_nan(s21_acos(n));
}
END_TEST

START_TEST(test_asin) {
  double n = 0.;
  ck_assert_ldouble_eq_tol(asin(n), s21_asin(n), PRECISION);
  n = -0.;
  ck_assert_ldouble_eq_tol(asin(n), s21_asin(n), PRECISION);
  n = 1.0;
  ck_assert_ldouble_eq_tol(asin(n), s21_asin(n), PRECISION);
  n = -1.0;
  ck_assert_ldouble_eq_tol(asin(n), s21_asin(n), PRECISION);

  n = 12345.123456;
  ck_assert_ldouble_nan(asin(n));
  ck_assert_ldouble_nan(s21_asin(n));
  n = -12345.123456;
  ck_assert_ldouble_nan(asin(n));
  ck_assert_ldouble_nan(s21_asin(n));
  n = INFINITY;
  ck_assert_ldouble_nan(asin(n));
  ck_assert_ldouble_nan(s21_asin(n));
  n = NAN;
  ck_assert_ldouble_nan(asin(n));
  ck_assert_ldouble_nan(s21_asin(n));
}
END_TEST

START_TEST(test_exp) {
  double n = 0.;
  ck_assert_ldouble_eq_tol(exp(n), s21_exp(n), PRECISION);
  n = -0.;
  ck_assert_ldouble_eq_tol(exp(n), s21_exp(n), PRECISION);
  n = 1.0;
  ck_assert_ldouble_eq_tol(exp(n), s21_exp(n), PRECISION);
  n = -1.0;
  ck_assert_ldouble_nan(sqrt(n));
  ck_assert_ldouble_nan(s21_sqrt(n));
  n = 2.0;
  ck_assert_ldouble_eq_tol(exp(n), s21_exp(n), PRECISION);
  n = 21.12356;
  ck_assert_ldouble_eq_tol(exp(n), s21_exp(n), PRECISION);
  n = -21.12356;
  ck_assert_ldouble_eq_tol(exp(n), s21_exp(n), PRECISION);
  n = INFINITY;
  ck_assert_ldouble_infinite(exp(n));
  ck_assert_ldouble_infinite(s21_exp(n));
  n = -S21_INF;
  ck_assert_ldouble_eq_tol(exp(n), s21_exp(n), PRECISION);
  n = NAN;
  ck_assert_ldouble_nan(exp(n));
  ck_assert_ldouble_nan(s21_exp(n));
}
END_TEST

START_TEST(test_log) {
  double n = 0.0;
  ck_assert_ldouble_infinite(log(n));
  ck_assert_ldouble_infinite(s21_log(n));
  n = 1.0;
  ck_assert_ldouble_eq_tol(log(n), s21_log(n), PRECISION);
  n = -1.0;
  ck_assert_ldouble_nan(log(n));
  ck_assert_ldouble_nan(s21_log(n));
  n = 1345.123456;
  ck_assert_ldouble_eq_tol(log(n), s21_log(n), PRECISION);
  n = S21_INF;
  ck_assert_ldouble_infinite(log(n));
  ck_assert_ldouble_infinite(s21_log(n));
  n = -S21_INF;
  ck_assert_ldouble_nan(log(n));
  ck_assert_ldouble_nan(s21_log(n));
  n = NAN;
  ck_assert_ldouble_nan(log(n));
  ck_assert_ldouble_nan(s21_log(n));
}
END_TEST

START_TEST(test_sqrt) {
  double n = 0.;
  ck_assert_ldouble_eq_tol(sqrt(n), s21_sqrt(n), PRECISION);
  n = -0.;
  ck_assert_ldouble_eq_tol(sqrt(n), s21_sqrt(n), PRECISION);
  n = 1.0;
  ck_assert_ldouble_eq_tol(sqrt(n), s21_sqrt(n), PRECISION);
  n = -1.0;
  ck_assert_ldouble_nan(sqrt(n));
  ck_assert_ldouble_nan(s21_sqrt(n));
  n = 2.0;
  ck_assert_ldouble_eq_tol(sqrt(n), s21_sqrt(n), PRECISION);
  n = 42.21;
  ck_assert_ldouble_eq_tol(sqrt(n), s21_sqrt(n), PRECISION);
  n = 12345.123456;
  ck_assert_ldouble_eq_tol(sqrt(n), s21_sqrt(n), PRECISION);
  n = 9999999999999999;
  ck_assert_ldouble_eq_tol(sqrt(n), s21_sqrt(n), PRECISION);
  n = INFINITY;
  ck_assert_ldouble_infinite(sqrt(n));
  ck_assert_ldouble_infinite(s21_sqrt(n));
  n = NAN;
  ck_assert_ldouble_nan(sqrt(n));
  ck_assert_ldouble_nan(s21_sqrt(n));
}
END_TEST

START_TEST(test_pow) {
  double x, y;
  x = 1.0, y = 2.0;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = 2.0, y = 1.0;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = 4.123, y = 3.43;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = 4.123, y = 0.0;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = 0.0, y = 4.3;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = -34.0, y = 4.3;
  ck_assert_ldouble_nan(pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = 34.0, y = 4.3;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = 34.0, y = -4.3;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = -34.0, y = 2.0;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = -2, y = 3;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = -34.3, y = -4.3;
  ck_assert_ldouble_nan(pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  x = 34.34567, y = 0.5;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = 34.34567, y = 0.0005;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
  x = INFINITY, y = 21;
  ck_assert_ldouble_infinite(pow(x, y));
  ck_assert_ldouble_infinite(s21_pow(x, y));
  x = 21, y = -S21_INF;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), PRECISION);
}
END_TEST

Suite *sample_suite() {
  Suite *s = suite_create("Sample Suite");

  TCase *tc_core = tcase_create("add");
  tcase_add_test(tc_core, test_abs);
  tcase_add_test(tc_core, test_fabs);
  tcase_add_test(tc_core, test_ceil);
  tcase_add_test(tc_core, test_floor);
  tcase_add_test(tc_core, test_fmod);
  tcase_add_test(tc_core, test_sin);
  tcase_add_test(tc_core, test_cos);
  tcase_add_test(tc_core, test_tan);
  tcase_add_test(tc_core, test_atan);
  tcase_add_test(tc_core, test_acos);
  tcase_add_test(tc_core, test_asin);
  tcase_add_test(tc_core, test_exp);
  tcase_add_test(tc_core, test_log);
  tcase_add_test(tc_core, test_sqrt);
  tcase_add_test(tc_core, test_pow);
  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  SRunner *sr = srunner_create(sample_suite());
  srunner_run_all(sr, CK_NORMAL);
  srunner_ntests_failed(sr);
  srunner_free(sr);
  return 0;
}
