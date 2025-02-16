#include "s21_string_tests.h"

START_TEST (s21_insert_test)
{
    char s21_str[] = "bob";
    char s21_src[] = "aa";
    s21_size_t index = 1;
    ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "aboba");
}
END_TEST

START_TEST (s21_insert_test_empty_src)
{
    char s21_str[] = "Ky";
    char s21_src[] = "";
    s21_size_t index = 3;
    ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
}
END_TEST

START_TEST (s21_insert_test_empty_index)
{
    char s21_str[] = "Ky";
    char s21_src[] = "";
    s21_size_t index = 0;
    ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "Ky");
}
END_TEST

START_TEST (s21_insert_test_start)
{
    char s21_str[] = "hello";
    char s21_src[] = " world";
    s21_size_t index = 0;
    ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "hello world");
}
END_TEST

START_TEST (s21_insert_test_end)
{
    char s21_str[] = "21";
    char s21_src[] = "school";
    s21_size_t index = 6;
    ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "school21");
}
END_TEST

START_TEST (s21_insert_test_null_src)
{
    char s21_str[] = "Go";
    char *s21_src = s21_NULL;
    s21_size_t index = 0;
    ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
}
END_TEST

START_TEST (s21_insert_test_null_str)
{
    char *s21_str = s21_NULL;
    char s21_src[] = "To";
    s21_size_t index = 0;
    ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
}
END_TEST

Suite *suite_s21_insert () {
    Suite *suite = suite_create("s21_insert");
    TCase *normal_tests = tcase_create("s21_insert_test");
    tcase_add_test (normal_tests, s21_insert_test);
    tcase_add_test (normal_tests, s21_insert_test_empty_src);
    tcase_add_test (normal_tests, s21_insert_test_empty_index);
    tcase_add_test (normal_tests, s21_insert_test_start);
    tcase_add_test (normal_tests, s21_insert_test_end);
    tcase_add_test (normal_tests, s21_insert_test_null_src);
    tcase_add_test (normal_tests, s21_insert_test_null_str);
    suite_add_tcase (suite, normal_tests);
    return suite;
}