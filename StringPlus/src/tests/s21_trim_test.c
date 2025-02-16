#include "s21_string_tests.h"

START_TEST (s21_trim_test)
{
    char s21_src[] = "aboba";
    char* s21_trim_char = "a";
    ck_assert_pstr_eq(s21_trim(s21_src, s21_trim_char), "bob");
}
END_TEST

START_TEST (s21_trim_test_end)
{
    char s21_src[] = "bob   ";
    char* s21_trim_char = " ";
    ck_assert_pstr_eq(s21_trim(s21_src, s21_trim_char), "bob");
}
END_TEST

START_TEST (s21_trim_test_start)
{
    char s21_src[] = "   bob";
    char* s21_trim_char = " ";
    ck_assert_pstr_eq(s21_trim(s21_src, s21_trim_char), "bob");
}
END_TEST

START_TEST (s21_trim_test_full)
{
    char s21_src[] = "bob";
    char* s21_trim_char = "bob";
    ck_assert_pstr_eq(s21_trim(s21_src, s21_trim_char), "");
}
END_TEST

START_TEST (s21_trim_test_null_chr)
{
    char s21_src[] = "bob";
    char* s21_trim_char = s21_NULL;
    ck_assert_pstr_eq(s21_trim(s21_src, s21_trim_char), s21_NULL);
}
END_TEST

START_TEST (s21_trim_test_null_src)
{
    char* s21_src = s21_NULL;
    char* s21_trim_char = " ";
    ck_assert_pstr_eq(s21_trim(s21_src, s21_trim_char), s21_NULL);
}
END_TEST

START_TEST (s21_trim_test_not_ans)
{
    char s21_src[] = "bob";
    char* s21_trim_char = "a";
    ck_assert_pstr_eq(s21_trim(s21_src, s21_trim_char), "bob");
}
END_TEST

Suite *suite_s21_trim () {
    Suite *suite = suite_create("s21_trim");
    TCase *normal_tests = tcase_create("s21_trim_test");
    tcase_add_test (normal_tests, s21_trim_test);
    tcase_add_test (normal_tests, s21_trim_test_end);
    tcase_add_test (normal_tests, s21_trim_test_start);
    tcase_add_test (normal_tests, s21_trim_test_full);
    tcase_add_test (normal_tests, s21_trim_test_null_chr);
    tcase_add_test (normal_tests, s21_trim_test_null_src);
    tcase_add_test (normal_tests, s21_trim_test_not_ans);
    suite_add_tcase (suite, normal_tests);
    return suite;
}