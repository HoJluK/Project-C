#include "s21_string_tests.h"

START_TEST (s21_strcspn_test)
{
    char src[] = "123";
    char dest[] = "123";
    ck_assert_int_eq(strcspn(dest, src), s21_strcspn(dest, src));
}
END_TEST

START_TEST (s21_strcspn_test_bob)
{
    char src[] = "bob";
    char dest[] = "bob";
    ck_assert_int_eq(strcspn(dest, src), s21_strcspn(dest, src));
}
END_TEST

START_TEST (s21_strcspn_test_reg)
{
    char src[] = "BoB";
    char dest[] = "BoBa";
    ck_assert_int_eq(strcspn(dest, src), s21_strcspn(dest, src));
}
END_TEST

START_TEST (s21_strcspn_test_long_num)
{
    char src[] = "1234567891011121314";
    char dest[] = "1413121110987654321";
    ck_assert_int_eq(strcspn(dest, src), s21_strcspn(dest, src));
}
END_TEST

START_TEST (s21_strcspn_test_random)
{
    char src[] = "123adfHA765";
    char dest[] = "Hfa32167DAA";
    ck_assert_int_eq(strcspn(dest, src), s21_strcspn(dest, src));
}
END_TEST

START_TEST (s21_strcspn_test_num_and_bob)
{
    char src[] = "12345679101112";
    char dest[] = "Bob";
    ck_assert_int_eq(strcspn(dest, src), s21_strcspn(dest, src));
}
END_TEST

START_TEST (s21_strcspn_test_empty)
{
    char src[] = "";
    char dest[] = "";
    ck_assert_int_eq(strcspn(dest, src), s21_strcspn(dest, src));
}
END_TEST

Suite *suite_s21_strcspn () {
    Suite *suite = suite_create("s21_strcspn");
    TCase *normal_tests = tcase_create("s21_strcspn_test");
    tcase_add_test (normal_tests, s21_strcspn_test);
    tcase_add_test (normal_tests, s21_strcspn_test_bob);
    tcase_add_test (normal_tests, s21_strcspn_test_reg);
    tcase_add_test (normal_tests, s21_strcspn_test_long_num);
    tcase_add_test (normal_tests, s21_strcspn_test_random);
    tcase_add_test (normal_tests, s21_strcspn_test_num_and_bob);
    tcase_add_test (normal_tests, s21_strcspn_test_empty);
    suite_add_tcase (suite, normal_tests);
    return suite;
}