#include "s21_string.h"

char *s21_strstr(const char* str, const char* substr){
    char *ptr = s21_NULL;
    int flag = 0;
    s21_size_t count = 0;
    for (s21_size_t i = 0; (i < s21_strlen(str)) && (!flag); i++){
        if (str[i] == substr[count]){
            count++;
        } else {
            count = 0;
        }
        if (count == s21_strlen(substr)) {
            ptr = (char*)str +(i-count+1);
            flag = 1;
        }
    }
    return ptr;
}

// int main() {
//     char *str = "trick or treat";
//     char *substr = "treat";
//     char *ptr = strstr(str,substr);
//     printf ("%s", ptr);
//     return 0;
// }