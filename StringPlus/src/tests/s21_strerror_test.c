#include "s21_string_tests.h"

// START_TEST (s21_strerror_test)
// {
//     for (int i = 0; i < 133; i++) {
//         char* s21_err = s21_strerror(i);
//         char* err = strerror(i);
//         ck_assert_str_eq(err, s21_err);
//     }
// }
// END_TEST


START_TEST (s21_strerror_test)
{
    for (int i = 0; i < 133; i++){
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

Suite *suite_s21_strerror () {
    Suite *suite = suite_create("s21_strerror");
    TCase *normal_tests = tcase_create("s21_strerror_test");
    tcase_add_test (normal_tests, s21_strerror_test);
    suite_add_tcase (suite, normal_tests);
    return suite;
}