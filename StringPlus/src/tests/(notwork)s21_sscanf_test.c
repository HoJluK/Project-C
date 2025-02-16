#include "s21_string_tests.h"

START_TEST(test_sscanf_integer) {
    int value;
    int res = s21_sscanf("123", "%d", &value);
    ck_assert_int_eq(res, 1);
    ck_assert_int_eq(value, 123);
}
END_TEST

START_TEST(test_sscanf_float) {
    double value;
    int res = s21_sscanf("123.45", "%f", &value);
    ck_assert_int_eq(res, 1);
    ck_assert_double_eq_tol(value, 123.45, 1e-6);
}
END_TEST

START_TEST(test_sscanf_octal) {
    unsigned int value;
    int res = s21_sscanf("123", "%o", &value);
    ck_assert_int_eq(res, 1);
    ck_assert_int_eq(value, 83);
}
END_TEST

START_TEST(test_sscanf_hex) {
    unsigned int value;
    int res = s21_sscanf("1A3F", "%x", &value);
    ck_assert_int_eq(res, 1);
    ck_assert_int_eq(value, 0x1A3F);
}
END_TEST

START_TEST(test_sscanf_suppress) {
    int value = 0;
    int res = s21_sscanf("123", "%*d", &value);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(value, 0);
}
END_TEST

START_TEST(test_sscanf_width) {
    char buffer[5];
    int res = s21_sscanf("hello", "%4s", buffer);
    ck_assert_int_eq(res, 1);
    ck_assert_str_eq(buffer, "hell");
}
END_TEST

Suite *suite_s21_sscanf () {
    Suite *suite = suite_create("s21_sscanf");
    TCase *normal_tests = tcase_create("s21_sscanf_test");
    tcase_add_test (normal_tests, test_sscanf_integer);
    tcase_add_test (normal_tests, test_sscanf_float);
    tcase_add_test (normal_tests, test_sscanf_octal);
    tcase_add_test (normal_tests, test_sscanf_hex);
    tcase_add_test (normal_tests, test_sscanf_hex);
    tcase_add_test (normal_tests, test_sscanf_suppress);
    tcase_add_test (normal_tests, test_sscanf_width);
    suite_add_tcase (suite, normal_tests);
    return suite;
}
