#include "s21_string_tests.h"

START_TEST (s21_strtok_test)
{
    char s21_str[] = "Hello!++world!====and!_*school! 21!";
    char str[] = "Hello!++world!====and!_*school! 21!";
    char delim[] = "! *_=+";

    char *s21 = s21_strtok(s21_str, delim);
    char *sys = strtok(str, delim);

    ck_assert_uint_eq(s21_strlen(sys), s21_strlen(s21));
    ck_assert_str_eq(s21, sys);

    while (s21 && sys) {
        s21 = s21_strtok(NULL, delim);
        sys = strtok(NULL, delim);
        ck_assert_pstr_eq(s21, sys);
    }
}
END_TEST

START_TEST (s21_strtok_test_2)
{
    char s21_str[] = "_Hel !+ **+wo!=+=+a!_ *school!==21!";
    char str[] = "_Hel !+ **+wo!=+=+a!_ *school!==21!";
    char delim[] = "! *_=+";

    char *s21 = s21_strtok(s21_str, delim);
    char *sys = strtok(str, delim);

    ck_assert_uint_eq(s21_strlen(sys), s21_strlen(s21));
    ck_assert_str_eq(s21, sys);

    while (s21 && sys) {
        s21 = s21_strtok(NULL, delim);
        sys = strtok(NULL, delim);
        ck_assert_pstr_eq(s21, sys);
    }
}
END_TEST

START_TEST (s21_strtok_test_empty_delim)
{
    char s21_str[] = "Helloworldandschool21";
    char str[] = "Helloworldandschool21";
    char delim[] = "! *_=+";

    char *s21 = s21_strtok(s21_str, delim);
    char *sys = strtok(str, delim);

    ck_assert_uint_eq(s21_strlen(sys), s21_strlen(s21));
    ck_assert_str_eq(s21, sys);

    while (s21 && sys) {
        s21 = s21_strtok(NULL, delim);
        sys = strtok(NULL, delim);
        ck_assert_pstr_eq(s21, sys);
    }
}
END_TEST

START_TEST (s21_strtok_test_only_delim)
{
    char s21_str[] = "_ !+ **+!=+=+!_ ";
    char str[] = "_ !+ **+!=+=+!_ ";
    char delim[] = "! *_=+";

    char *s21 = s21_strtok(s21_str, delim);
    char *sys = strtok(str, delim);

    ck_assert_uint_eq(s21_strlen(sys), s21_strlen(s21));
    ck_assert_str_eq(s21, sys);

    while (s21 && sys) {
        s21 = s21_strtok(NULL, delim);
        sys = strtok(NULL, delim);
        ck_assert_pstr_eq(s21, sys);
    }
}
END_TEST

Suite *suite_s21_strtok () {
    Suite *suite = suite_create("s21_strtok");
    TCase *normal_tests = tcase_create("s21_strtok_test");
    tcase_add_test (normal_tests, s21_strtok_test);
    tcase_add_test (normal_tests, s21_strtok_test_2);
    tcase_add_test (normal_tests, s21_strtok_test_empty_delim);
    tcase_add_test (normal_tests, s21_strtok_test_only_delim);
    suite_add_tcase (suite, normal_tests);
    return suite;
}