#include "s21_string.h"

char *s21_strpbrk (const char* str1, const char* str2) {
    s21_size_t index = 0;
    s21_size_t index2 = 0;
    char* ptr = s21_NULL;
    int flag = 0;
    while ((str1[index] != '\0') && (!flag)){
        while ((str2[index2] != '\0') && (!flag)){
            if (str1[index] == str2[index2]) {
                ptr = (char*)str1 + index;
                flag = 1;
            }
            if (!flag) index2++;
        }
        index2 = 0;
        if (!flag) index++;
    }
    return ptr;
}

// int main() {
//     char *str1 = "hello world";
//     char *str2 = "le";
//     char *ptr = s21_strpbrk (str1,str2);
//     printf ("%c",*ptr);
//     return 0;
// }