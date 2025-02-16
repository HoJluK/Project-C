#include "s21_string.h"

void *s21_memchr (const void* str, int expected, s21_size_t lenght)
{
    int flag = 0;
    void *res = s21_NULL;
    char* ch_str = (char*) str;
    int ch_expected = expected;
    for (s21_size_t i = 0; (i < lenght) && (!flag); i++){
        if (ch_str[i] == ch_expected){
            res = ch_str + i;
            flag = 1;
        }
    }
    return res;
}