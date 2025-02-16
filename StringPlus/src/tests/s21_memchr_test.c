#include "s21_string_tests.h"

START_TEST (s21_memchr_test_at_start)
{
    char *str1 = "Hell no";
    char *exp_result = memchr (str1,'H', strlen(str1));
    ck_assert_ptr_eq(exp_result, &str1[0]);
    char *result = s21_memchr (str1,'H', strlen(str1));
    ck_assert_ptr_eq(result, &str1[0]);
    ck_assert_ptr_eq (exp_result, result);
}
END_TEST

START_TEST (s21_memchr_test_at_middle)
{
    char *str1 = "Hell no";
    char *exp_result = memchr (str1,'n', strlen(str1));
    ck_assert_ptr_eq(exp_result, &str1[5]);
    char *result = s21_memchr (str1,'n', strlen(str1));
    ck_assert_ptr_eq(result, &str1[5]);
    ck_assert_ptr_eq (exp_result, result);
}
END_TEST

START_TEST (s21_memchr_test_at_end)
{
    char *str1 = "Hell no";
    char *exp_result = memchr (str1,'o', strlen(str1));
    ck_assert_ptr_eq(exp_result, &str1[6]);
    char *result = s21_memchr (str1,'o', strlen(str1));
    ck_assert_ptr_eq(result, &str1[6]);
    ck_assert_ptr_eq (exp_result, result);
}
END_TEST

START_TEST (s21_memchr_test_space)
{
    char *str1 = "Hell no";
    char *exp_result = memchr (str1,' ', strlen(str1));
    ck_assert_ptr_eq(exp_result, &str1[4]);
    char *result = s21_memchr (str1,' ', strlen(str1));
    ck_assert_ptr_eq(result, &str1[4]);
    ck_assert_ptr_eq (exp_result, result);
}
END_TEST

START_TEST (s21_memchr_test_null_in_none)
{
    char *str1 = "";
    int *exp_result = memchr (str1,'\0', strlen(str1)+1);
    ck_assert_ptr_eq(exp_result, &str1[0]);
    char *result = s21_memchr (str1,'\0', strlen(str1)+1);
    ck_assert_ptr_eq(result, &str1[0]);
    ck_assert_ptr_eq(exp_result, result);
}
END_TEST

START_TEST (s21_memchr_nonexist_char)
{
    char *str1 = "Hell no";
    char *exp_result = memchr (str1,'x', strlen(str1));
    ck_assert_ptr_eq(exp_result, NULL);
    char *result = s21_memchr (str1,'x', strlen(str1));
    ck_assert_ptr_eq(result, NULL);
    ck_assert_ptr_eq(exp_result,result);
}
END_TEST

START_TEST (s21_memchr_char_out_of_frame)
{
    char *str1 = "Hell no";
    char *exp_result = memchr (str1,'n', 4);
    ck_assert_ptr_eq(exp_result, NULL);
    char *result = s21_memchr (str1,'n', 4);
    ck_assert_ptr_eq(result, NULL);
    ck_assert_ptr_eq(exp_result,result);
}
END_TEST

Suite *suite_s21_memchr () {
    Suite *suite = suite_create("s21_memchr");
    TCase *normal_tests = tcase_create("s21_memchr_test");
    tcase_add_test (normal_tests, s21_memchr_test_at_start);
    tcase_add_test (normal_tests, s21_memchr_test_at_middle);
    tcase_add_test (normal_tests, s21_memchr_test_at_end);
    tcase_add_test (normal_tests, s21_memchr_test_space);
    tcase_add_test (normal_tests, s21_memchr_test_null_in_none);
    tcase_add_test (normal_tests, s21_memchr_nonexist_char);
    tcase_add_test (normal_tests, s21_memchr_char_out_of_frame);
    suite_add_tcase (suite, normal_tests);
    return suite;
}