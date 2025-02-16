#include "s21_string_tests.h"

START_TEST (s21_strlen_test)
{
    char str[] = "helloWorld21";
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST (s21_strlen_test_empty)
{
    char str[] = "";
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST (s21_strlen_test_num)
{
    char str[] = "1";
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *suite_s21_strlen () {
    Suite *suite = suite_create("s21_strlen");
    TCase *normal_tests = tcase_create("s21_strlen_test");
    tcase_add_test (normal_tests, s21_strlen_test);
    tcase_add_test (normal_tests, s21_strlen_test_empty);
    tcase_add_test (normal_tests, s21_strlen_test_num);
    suite_add_tcase (suite, normal_tests);
    return suite;
}