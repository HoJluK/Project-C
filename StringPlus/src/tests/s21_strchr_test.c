#include "s21_string_tests.h"

START_TEST (s21_strchr_test)
{
    char s21_str[15] = "bObolibob";
    char str[15] = "bObolibob";
    int c = 'i';
    ck_assert_pstr_eq(strchr(str, c), s21_strchr(s21_str, c));
}
END_TEST

START_TEST (s21_strchr_test_number)
{
    char s21_str[10] = "bObo10bob";
    char str[10] = "bObo10bob";
    int c = '1';
    ck_assert_pstr_eq(strchr(str, c), s21_strchr(s21_str, c));
}
END_TEST

START_TEST (s21_strchr_test_1)
{
    char s21_src[10] = "1";
    char src[10] = "1";
    int c = '1';
    ck_assert_pstr_eq(strchr(src, c), s21_strchr(s21_src, c));
}
END_TEST

START_TEST (s21_strchr_test_null)
{
    char s21_str[10] = "";
    char str[10] = "";
    int c = '\0';
    ck_assert_pstr_eq(strchr(str, c), s21_strchr(s21_str, c));
}
END_TEST

START_TEST (s21_strchr_test_null_result)
{
    char s21_str[10] = "helloman";
    char str[10] = "helloman";
    int c = '1';
    ck_assert_pstr_eq(strchr(str, c), s21_strchr(s21_str, c));
}
END_TEST

Suite *suite_s21_strchr () {
    Suite *suite = suite_create("s21_strchr");
    TCase *normal_tests = tcase_create("s21_strchr_test");
    tcase_add_test (normal_tests, s21_strchr_test);
    tcase_add_test (normal_tests, s21_strchr_test_number);
    tcase_add_test (normal_tests, s21_strchr_test_1);
    tcase_add_test (normal_tests, s21_strchr_test_null);
    tcase_add_test (normal_tests, s21_strchr_test_null_result);
    suite_add_tcase (suite, normal_tests);
    return suite;
}