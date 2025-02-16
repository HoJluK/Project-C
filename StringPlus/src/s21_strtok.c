#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
    static char *last_ptr = s21_NULL;
    int flag = 0;
    char *ptr = s21_NULL;
    if (str == s21_NULL){
        str = last_ptr;
    }
    if (str == s21_NULL || *str == '\0'){
        flag = 1;
    }
    while ((!flag) && (s21_strchr(delim,*str) != s21_NULL)){
        str++;
    }
    if (!flag) {
        ptr = str;
        while ((*str != '\0') && (s21_strchr(delim,*str) == s21_NULL)){
            str++;
        }
        if (*str != '\0'){
            *str = '\0';
            last_ptr = str+1;
        } else {
            last_ptr = s21_NULL;
        }
    } else {
        last_ptr = s21_NULL;
    }
    return ptr;
}


// int main() {
//     char str[] = "you,,,are,a,happy,wolf";
//     const char *delimiters = ",";
//     char *token = s21_strtok(str, delimiters);
//     while (token != NULL) {
//         printf("%s\n", token);
//         token = s21_strtok(NULL, ",");
//     }
// }