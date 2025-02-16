#include "s21_string_tests.h"

START_TEST (s21_memcmp_test)
{
    const char *str1 = "Hello man";
    const char *str2 = "man Hello";
    size_t n = 8;
    ck_assert_int_eq (memcmp (str1,str2,n), s21_memcmp(str1,str2,n));
}
END_TEST

START_TEST (s21_memcmp_test_tab)
{
    const char *str1 = "Hello school21    ";
    const char *str2 = "school21 Hello    ";
    size_t n = 13;
    ck_assert_int_eq (memcmp (str1,str2,n), s21_memcmp(str1,str2,n));
}
END_TEST

START_TEST (s21_memcmp_test_n)
{
    const char *str1 = "world\nHello";
    const char *str2 = "Hello\nworld";
    size_t n = 10;
    ck_assert_int_eq (memcmp (str1,str2,n), s21_memcmp(str1,str2,n));
}
END_TEST

START_TEST (s21_memcmp_test_out)
{
    const char *str1 = "man Hello";
    const char *str2 = "Hello man";
    size_t n = 10;
    ck_assert_int_eq (memcmp (str1,str2,n), s21_memcmp(str1,str2,n));
}    
END_TEST

START_TEST (s21_memcmp_test_null)
{
    const char *str1 = "Hello\0man";
    const char *str2 = "Hello\0man";
    size_t n = 8;
    ck_assert_int_eq (memcmp (str1,str2,n), s21_memcmp(str1,str2,n));
}
END_TEST

START_TEST (s21_memcmp_test_flags)
{
    const char *str1 = "Hello\0man";
    const char *str2 = "Hle11o\0m";
    size_t n = 8;
    ck_assert_int_eq (memcmp (str1,str2,n), s21_memcmp(str1,str2,n));
}
END_TEST

Suite *suite_s21_memcmp() {
    Suite *suite = suite_create("s21_memcmp");
    TCase *normal_tests = tcase_create ("s21_memcmp_test");
    tcase_add_test (normal_tests, s21_memcmp_test);
    tcase_add_test (normal_tests, s21_memcmp_test_tab);
    tcase_add_test (normal_tests, s21_memcmp_test_n);
    tcase_add_test (normal_tests, s21_memcmp_test_out);
    tcase_add_test (normal_tests, s21_memcmp_test_null);
    tcase_add_test (normal_tests, s21_memcmp_test_flags);
    suite_add_tcase (suite, normal_tests);
    return suite;
}