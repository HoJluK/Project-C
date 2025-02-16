#ifndef S21_STRING_TESTS
#define S21_STRING_TESTS

#include <string.h>
#include <check.h>
#include <ctype.h>
#include <locale.h>
#include <stdint.h>
#include <wchar.h>
#include "../s21_string.h"


#define BUFF_SIZE 512

void runtests ();
void runtest (Suite *test);

Suite *suite_s21_memchr ();
Suite *suite_s21_memcmp ();
Suite *suite_s21_memcpy ();
Suite *suite_s21_memset ();
Suite *suite_s21_strncat ();
Suite *suite_s21_strchr ();
Suite *suite_s21_strncmp ();
Suite *suite_s21_strncpy ();
Suite *suite_s21_strcspn ();
Suite *suite_s21_strerror ();
Suite *suite_s21_strlen ();
Suite *suite_s21_strpbrk ();
Suite *suite_s21_strrchr ();
Suite *suite_s21_strstr ();
Suite *suite_s21_strtok ();

//Suite *suite_s21_sprintf ();
Suite *suite_s21_sscanf ();

Suite *suite_s21_to_upper ();
Suite *suite_s21_to_lower ();
Suite *suite_s21_insert ();
Suite *suite_s21_trim ();

#endif