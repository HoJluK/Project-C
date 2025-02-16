#include "s21_string_tests.h"

void runtests () {
    Suite *all_functions[] = {suite_s21_memchr(), suite_s21_memcmp(), suite_s21_memcpy(),
                              suite_s21_memset(), suite_s21_strncat(), suite_s21_strchr(),
                              suite_s21_strncmp(), suite_s21_strncpy(), suite_s21_strcspn(),
                              suite_s21_strlen(), suite_s21_strpbrk(), suite_s21_strerror(),
                              suite_s21_strrchr(), suite_s21_strstr(), suite_s21_strtok(),
                              suite_s21_to_upper(), suite_s21_to_lower(),suite_s21_insert(),
                              suite_s21_trim(), suite_s21_sscanf(), NULL};

    for (int i = 0; all_functions[i] != NULL; i++){
        runtest (all_functions[i]);
    }
}

void runtest (Suite *test)
{
    SRunner *sr = srunner_create (test);
    srunner_run_all (sr, CK_NORMAL);

    int num_failed = srunner_ntests_failed (sr);
    if (num_failed == 0){
        printf ("All tests are done\n");
    } else {
        printf ("Number of failed tests:%d\n",num_failed);
    }
    srunner_free(sr);
}

int main ()
{
    runtests();
}