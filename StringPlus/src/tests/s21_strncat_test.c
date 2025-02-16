#include "s21_string_tests.h"

START_TEST (s21_strncat_test)
{
    char s21_dest[10] = "A";
    char dest[10] = "A";
    char s21_src[10] = "bOb";
    char src[10] = "bOb";
    size_t n = 3;
    ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_strncat_test_null_src)
{
    char s21_dest[10] = "Hello";
    char dest[10] = "Hello";
    char s21_src[] = "";
    char src[] = "";
    size_t n = 0;
    ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_strncat_test_all_null)
{
    char s21_dest[] = "";
    char dest[] = "";
    char s21_src[] = "";
    char src[] = "";
    size_t n = 0;
    ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_strncat_test_size_null)
{
    char s21_dest[10] = "21";
    char dest[10] = "21";
    char s21_src[10] = "School";
    char src[10] = "School";
    size_t n = 0;
    ck_assert_str_eq(strncat(dest, src, n), s21_strncat(s21_dest, s21_src, n));
}
END_TEST

Suite *suite_s21_strncat () {
    Suite *suite = suite_create("s21_strncat");
    TCase *normal_tests = tcase_create("s21_strncat_test");
    tcase_add_test (normal_tests, s21_strncat_test);
    tcase_add_test (normal_tests, s21_strncat_test_null_src);
    tcase_add_test (normal_tests, s21_strncat_test_all_null);
    tcase_add_test (normal_tests, s21_strncat_test_size_null);
    suite_add_tcase (suite, normal_tests);
    return suite;
}