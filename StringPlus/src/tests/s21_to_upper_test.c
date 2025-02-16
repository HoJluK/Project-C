#include "s21_string_tests.h"

START_TEST (s21_to_upper_test)
{
    char s21_str[] = "bob";
    ck_assert_str_eq(s21_to_upper(s21_str), "BOB");
}
END_TEST

START_TEST (s21_to_upper_test_empty)
{
    char s21_str[] = "";
    ck_assert_str_eq(s21_to_upper(s21_str), s21_NULL);
}
END_TEST

START_TEST (s21_to_upper_test_num)
{
    char s21_str[] = "b123ob";
    ck_assert_str_eq(s21_to_upper(s21_str), "B123OB");
}
END_TEST

START_TEST (s21_to_upper_test_reg)
{
    char s21_str[] = "BOB";
    ck_assert_str_eq(s21_to_upper(s21_str), "BOB");
}
END_TEST

Suite *suite_s21_to_upper () {
    Suite *suite = suite_create("s21_to_upper");
    TCase *normal_tests = tcase_create("s21_to_upper_test");
    tcase_add_test (normal_tests, s21_to_upper_test);
    tcase_add_test (normal_tests, s21_to_upper_test_empty);
    tcase_add_test (normal_tests, s21_to_upper_test_num);
    tcase_add_test (normal_tests, s21_to_upper_test_reg);
    suite_add_tcase (suite, normal_tests);
    return suite;
}