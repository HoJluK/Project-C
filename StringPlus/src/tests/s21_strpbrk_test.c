#include "s21_string_tests.h"

START_TEST (s21_strpbrk_test)
{
    char str1[] = "hello World";
    char str2[] = "h";
    ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST (s21_strpbrk_test_empty)
{
    char str1[] = "";
    char str2[] = "";
    ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST (s21_strpbrk_test_reg)
{
    char str1[] = "W";
    char str2[] = "hello World";
    ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST (s21_strpbrk_test_null)
{
    char str1[] = "helloWorld";
    char str2[] = "\0";
    ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST (s21_strpbrk_test_space)
{
    char str1[] = "hello World";
    char str2[] = " ";
    ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *suite_s21_strpbrk () {
    Suite *suite = suite_create("s21_strpbrk");
    TCase *normal_tests = tcase_create("s21_strpbrk_test");
    tcase_add_test (normal_tests, s21_strpbrk_test);
    tcase_add_test (normal_tests, s21_strpbrk_test_empty);
    tcase_add_test (normal_tests, s21_strpbrk_test_reg);
    tcase_add_test (normal_tests, s21_strpbrk_test_null);
    tcase_add_test (normal_tests, s21_strpbrk_test_space);
    suite_add_tcase (suite, normal_tests);
    return suite;
}