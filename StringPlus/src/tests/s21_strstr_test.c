#include "s21_string_tests.h"

START_TEST (s21_strstr_test)
{
    char haystack[] = "bObo li bob";
    char needle[] = "li";
    ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST (s21_strstr_test_empty)
{
    char haystack[] = "";
    char needle[] = "";
    ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST (s21_strstr_test_empty_haystack)
{
    char haystack[] = "";
    char needle[] = "li";
    ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST (s21_strstr_test_empty_needle)
{
    char haystack[] = "bObolibob";
    char needle[] = "";
    ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST (s21_strstr_test_not_result)
{
    char haystack[] = "bObolibob";
    char needle[] = "af";
    ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST (s21_strstr_test_num)
{
    char haystack[] = "bObol1bob";
    char needle[] = "1";
    ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

Suite *suite_s21_strstr () {
    Suite *suite = suite_create("s21_strstr");
    TCase *normal_tests = tcase_create("s21_strstr_test");
    tcase_add_test (normal_tests, s21_strstr_test);
    tcase_add_test (normal_tests, s21_strstr_test_empty);
    tcase_add_test (normal_tests, s21_strstr_test_empty_haystack);
    tcase_add_test (normal_tests, s21_strstr_test_empty_needle);
    tcase_add_test (normal_tests, s21_strstr_test_not_result);
    tcase_add_test (normal_tests, s21_strstr_test_num);
    suite_add_tcase (suite, normal_tests);
    return suite;
}