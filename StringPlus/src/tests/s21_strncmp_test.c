#include "s21_string_tests.h"

START_TEST (s21_strncmp_test)
{
    char str1[15] = "";
    char str2[15] = "";
    size_t n = 1; 
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST (s21_strncmp_test_empty_1)
{
    char str1[15] = "";
    char str2[15] = "b0b";
    size_t n = 1; 
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST (s21_strncmp_test_empty_2)
{
    char str1[15] = "b0b";
    char str2[15] = "";
    size_t n = 1; 
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST (s21_strncmp_test_less)
{
    char str1[15] = "1234";
    char str2[15] = "1bob23";
    size_t n = 3; 
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST (s21_strncmp_test_more)
{
    char str1[15] = "1bob23";
    char str2[15] = "1234";
    size_t n = 3; 
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *suite_s21_strncmp () {
    Suite *suite = suite_create("s21_strncmp");
    TCase *normal_tests = tcase_create("s21_strncmp_test");
    tcase_add_test (normal_tests, s21_strncmp_test);
    tcase_add_test (normal_tests, s21_strncmp_test_empty_1);
    tcase_add_test (normal_tests, s21_strncmp_test_empty_2);
    tcase_add_test (normal_tests, s21_strncmp_test_less);
    tcase_add_test (normal_tests, s21_strncmp_test_more);
    suite_add_tcase (suite, normal_tests);
    return suite;
}