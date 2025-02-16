#include "s21_string_tests.h"

START_TEST (s21_strncpy_test)
{
    char s21_dest[10] = "man";
    char dest[10] = "man";
    char s21_src[10] = "Hello bob";
    char src[10] = "Hello bob";
    size_t n = 9;
    ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_strncpy_test_full_empty)
{
    char s21_dest[] = "";
    char dest[] = "";
    char s21_src[] = "";
    char src[] = "";
    size_t n = 0;
    ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_strncpy_test_n_empty)
{
    char s21_dest[] = "hello";
    char dest[] = "hello";
    char s21_src[] = "world";
    char src[] = "world";
    size_t n = 0;
    ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_strncpy_test_dest_empty)
{
    char s21_dest[5] = "";
    char dest[5] = "";
    char s21_src[10] = "hello";
    char src[10] = "hello";
    size_t n = 2;
    ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_strncpy_test_not_full_n)
{
    char s21_dest[15] = "Hello";
    char dest[15] = "Hello";
    char s21_src[10] = "world";
    char src[10] = "world";
    size_t n = 3;
    ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(s21_dest, s21_src, n));
}
END_TEST

Suite *suite_s21_strncpy () {
    Suite *suite = suite_create("s21_strncpy");
    TCase *normal_tests = tcase_create("s21_strncpy_test");
    tcase_add_test (normal_tests, s21_strncpy_test);
    tcase_add_test (normal_tests, s21_strncpy_test_full_empty);
    tcase_add_test (normal_tests, s21_strncpy_test_n_empty);
    tcase_add_test (normal_tests, s21_strncpy_test_dest_empty);
    tcase_add_test (normal_tests, s21_strncpy_test_not_full_n);
    suite_add_tcase (suite, normal_tests);
    return suite;
}