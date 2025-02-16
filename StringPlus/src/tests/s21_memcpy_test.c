#include "s21_string_tests.h"

START_TEST (s21_memcpy_test)
{
    char s21_dest[5] = "";
    char dest[5] = "";
    const char s21_src[] = "Hello";
    const char src[] = "Hello";
    size_t n = 4;
    ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_memcpy_test_size_0)
{
    char s21_dest[5] = "";
    char dest[5] = "";
    const char s21_src[] = "Hello";
    const char src[] = "Hello";
    size_t n = 0;
    ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_memcpy_test_rewrite)
{
    char s21_dest[15] = "Hello";
    char dest[15] = "Hello";
    const char s21_src[] = "school21";
    const char src[] = "school21";
    size_t n = 6;
    ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_memcpy_test_under)
{
    char s21_dest[20] = "";
    char dest[20] = "";
    const char s21_src[] = "Hello_school21";
    const char src[] = "Hello_school21";
    size_t n = 15;
    ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(s21_dest, s21_src, n));
}
END_TEST

Suite *suite_s21_memcpy () {
    Suite *suite = suite_create("s21_memcpy");
    TCase *normal_tests = tcase_create("s21_memcpy_test");
    tcase_add_test (normal_tests, s21_memcpy_test);
    tcase_add_test (normal_tests, s21_memcpy_test_size_0);
    tcase_add_test (normal_tests, s21_memcpy_test_rewrite);
    tcase_add_test (normal_tests, s21_memcpy_test_under);
    suite_add_tcase (suite, normal_tests);
    return suite;
}