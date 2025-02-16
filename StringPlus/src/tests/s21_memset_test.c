#include "s21_string_tests.h"

START_TEST (s21_memset_test)
{
    char s21_dest[] = "HelloSchool21";
    char dest[] = "HelloSchool21";
    int s21_src = 'a';
    int src = 'a';
    size_t n = 5;
    ck_assert_str_eq(memset(dest, src, n), s21_memset(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_memset_test_null)
{
    char s21_dest[] = "HelloSchool21";
    char dest[] = "HelloSchool21";
    int s21_src = 'a';
    int src = 'a';
    size_t n = 0;
    ck_assert_str_eq(memset(dest, src, n), s21_memset(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_memset_test_empty)
{
    char s21_dest[] = "";
    char dest[] = "";
    int s21_src = '\0';
    int src = '\0';
    size_t n = 0;
    ck_assert_str_eq(memset(dest, src, n), s21_memset(s21_dest, s21_src, n));
}
END_TEST

START_TEST (s21_memset_test_number)
{
    char s21_dest[] = "Hello";
    char dest[] = "Hello";
    int s21_src = '4';
    int src = '4';
    size_t n = 1;
    ck_assert_str_eq(memset(dest, src, n), s21_memset(s21_dest, s21_src, n));
}
END_TEST

Suite *suite_s21_memset () {
    Suite *suite = suite_create("s21_memset");
    TCase *normal_tests = tcase_create("s21_memset_test");
    tcase_add_test (normal_tests, s21_memset_test);
    tcase_add_test (normal_tests, s21_memset_test_null);
    tcase_add_test (normal_tests, s21_memset_test_empty);
    tcase_add_test (normal_tests, s21_memset_test_number);
    suite_add_tcase (suite, normal_tests);
    return suite;
}